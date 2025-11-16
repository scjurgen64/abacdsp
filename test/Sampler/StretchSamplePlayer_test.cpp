#include <gtest/gtest.h>

#include <numbers>
#include <memory>
#include <vector>
#include <cmath>

#include "Analysis/ZeroCrossings.h"
#include "Sampler/StretchSamplePlayer.h"

namespace AbacDsp::Test
{

class StretchSamplePlayerTest : public ::testing::Test
{
  protected:
    static constexpr float sampleRate{48000.f};

    void SetUp() override
    {
        m_player = std::make_unique<StretchSamplePlayer>(sampleRate);
        generateInterleavedSineWave();
    }

    void generateInterleavedSineWave()
    {
        const float frequency = 440.0f;
        const float duration = 1.5f;
        const size_t numSamples = static_cast<size_t>(sampleRate * duration);
        m_sineData = std::make_shared<std::vector<float>>(numSamples * 2);

        for (size_t i = 0; i < numSamples; ++i)
        {
            const float t = static_cast<float>(i) / sampleRate;
            const float sample = std::sin(2.0f * std::numbers::pi_v<float> * frequency * t);
            (*m_sineData)[i * 2] = sample;
            (*m_sineData)[i * 2 + 1] = sample;
        }
    }

    std::unique_ptr<StretchSamplePlayer> m_player;
    std::shared_ptr<std::vector<float>> m_sineData;
};

TEST_F(StretchSamplePlayerTest, BasicPlayback)
{
    constexpr size_t bufferSize = 1024;
    std::vector<float> leftOut(bufferSize);
    std::vector<float> rightOut(bufferSize);

    m_player->runStereo(m_sineData);
    m_player->setPlaybackRate(1.0f);
    m_player->restart();

    std::ranges::fill(leftOut, 0.0f);
    std::ranges::fill(rightOut, 0.0f);

    m_player->processBlock(leftOut.data(), rightOut.data(), bufferSize);

    float maxAmplitude = 0.0f;
    for (const auto sample : leftOut)
    {
        maxAmplitude = std::max(maxAmplitude, std::abs(sample));
    }

    EXPECT_GT(maxAmplitude, 0.1f) << "Output should contain audio signal";
}

TEST_F(StretchSamplePlayerTest, PhaseCoherenceAfterRestart)
{
    constexpr size_t bufferSize = 4096;
    std::vector<float> leftOut1(bufferSize);
    std::vector<float> leftOut2(bufferSize);
    std::vector<float> rightOut(bufferSize);

    m_player->runStereo(m_sineData);
    m_player->setPlaybackRate(1.0f);
    m_player->restart();

    m_player->processBlock(leftOut1.data(), rightOut.data(), bufferSize);

    m_player->restart();
    m_player->processBlock(leftOut2.data(), rightOut.data(), bufferSize);

    for (size_t i = 0; i < bufferSize; ++i)
    {
        EXPECT_NEAR(leftOut1[i], leftOut2[i], 0.01f) << "Phase reset should produce consistent output at sample " << i;
    }
}

TEST_F(StretchSamplePlayerTest, PositionControl)
{
    constexpr size_t bufferSize = 2048;
    constexpr size_t jumpPosition = 4800;
    std::vector<float> leftOut(bufferSize);
    std::vector<float> rightOut(bufferSize);

    m_player->runStereo(m_sineData);
    m_player->setPlaybackRate(1.0f);
    m_player->setPosition(jumpPosition);

    std::ranges::fill(leftOut, 0.0f);
    std::ranges::fill(rightOut, 0.0f);

    m_player->processBlock(leftOut.data(), rightOut.data(), bufferSize);

    float rms = 0.0f;
    for (const auto sample : leftOut)
    {
        rms += sample * sample;
    }
    rms = std::sqrt(rms / bufferSize);

    EXPECT_GT(rms, 0.1f) << "Should produce audio after position jump";
}

TEST_F(StretchSamplePlayerTest, PitchShiftUp)
{
    constexpr size_t bufferSize = 24000;
    std::vector<float> leftOut(bufferSize);
    std::vector<float> rightOut(bufferSize);

    const float pitchShiftSemitones = 12.0f;
    const float playbackRate = std::pow(2.0f, pitchShiftSemitones / 12.0f);
    const auto statsSine = AbacDsp::calculateZeroCrossingStatistics(m_sineData->data(), bufferSize, true);
    m_player->runStereo(m_sineData);
    m_player->setPlaybackRate(playbackRate);
    m_player->restart();

    std::ranges::fill(leftOut, 0.0f);
    std::ranges::fill(rightOut, 0.0f);

    m_player->processBlock(leftOut.data(), rightOut.data(), bufferSize);

    const auto stats = AbacDsp::calculateZeroCrossingStatistics(leftOut.data(), bufferSize, true);

    if (stats.periodCount > 10)
    {
        const float expectedFreq = 440.0f * playbackRate;
        const float expectedPeriod = sampleRate / expectedFreq;
        const float tolerance = expectedPeriod * 0.15f;

        EXPECT_NEAR(stats.meanPeriodLen, expectedPeriod, tolerance)
            << "Pitch shift +12 semitones. Expected period: " << expectedPeriod
            << " Mean period: " << stats.meanPeriodLen;
    }
}

TEST_F(StretchSamplePlayerTest, PitchShiftUpPreservesFrequency)
{
    constexpr size_t bufferSize = 24000;
    std::vector<float> leftOut(bufferSize);
    std::vector<float> rightOut(bufferSize);

    const float pitchShiftSemitones = 12.0f;
    const float playbackRate = std::pow(2.0f, pitchShiftSemitones / 12.0f);

    m_player->runStereo(m_sineData);
    m_player->setPlaybackRate(playbackRate);
    m_player->restart();

    std::ranges::fill(leftOut, 0.0f);
    std::ranges::fill(rightOut, 0.0f);

    m_player->processBlock(leftOut.data(), rightOut.data(), bufferSize);

    const auto stats = AbacDsp::calculateZeroCrossingStatistics(leftOut.data(), bufferSize, true);

    if (stats.periodCount > 10)
    {
        const float expectedFreq = 440.0f * playbackRate;
        const float expectedPeriod = sampleRate / expectedFreq;
        const float tolerance = expectedPeriod * 0.15f;

        EXPECT_NEAR(stats.meanPeriodLen, expectedPeriod, tolerance)
            << "Pitch shift +12 semitones. Expected period: " << expectedPeriod
            << " Mean period: " << stats.meanPeriodLen;
    }
}

TEST_F(StretchSamplePlayerTest, PitchShiftDownPreservesFrequency)
{
    constexpr size_t bufferSize = 24000;
    std::vector<float> leftOut(bufferSize);
    std::vector<float> rightOut(bufferSize);

    const float pitchShiftSemitones = -12.0f;
    const float playbackRate = std::pow(2.0f, pitchShiftSemitones / 12.0f);

    m_player->runStereo(m_sineData);
    m_player->setPlaybackRate(playbackRate);
    m_player->restart();

    std::ranges::fill(leftOut, 0.0f);
    std::ranges::fill(rightOut, 0.0f);

    m_player->processBlock(leftOut.data(), rightOut.data(), bufferSize);

    const auto stats = AbacDsp::calculateZeroCrossingStatistics(leftOut.data(), bufferSize, true);

    if (stats.periodCount > 10)
    {
        const float expectedFreq = 440.0f * playbackRate;
        const float expectedPeriod = sampleRate / expectedFreq;
        const float tolerance = expectedPeriod * 0.15f;

        EXPECT_NEAR(stats.meanPeriodLen, expectedPeriod, tolerance)
            << "Pitch shift -12 semitones. Expected period: " << expectedPeriod
            << " Mean period: " << stats.meanPeriodLen;
    }
}

TEST_F(StretchSamplePlayerTest, LoopingBehavior)
{
    constexpr size_t bufferSize = 48000;
    std::vector<float> leftOut(bufferSize);
    std::vector<float> rightOut(bufferSize);

    m_player->runStereo(m_sineData);
    m_player->setLoop(true);
    m_player->setPlaybackRate(1.0f);
    m_player->restart();

    std::ranges::fill(leftOut, 0.0f);
    std::ranges::fill(rightOut, 0.0f);

    m_player->processBlock(leftOut.data(), rightOut.data(), bufferSize);

    EXPECT_FALSE(m_player->isDone()) << "Player should continue when looping enabled";

    float rms = 0.0f;
    for (const auto sample : leftOut)
    {
        rms += sample * sample;
    }
    rms = std::sqrt(rms / bufferSize);

    EXPECT_GT(rms, 0.1f) << "Looped playback should produce continuous audio";
}

TEST_F(StretchSamplePlayerTest, NonLoopingStops)
{
    constexpr size_t bufferSize = 48000;
    std::vector<float> leftOut(bufferSize);
    std::vector<float> rightOut(bufferSize);

    m_player->runStereo(m_sineData);
    m_player->setLoop(false);
    m_player->setPlaybackRate(1.0f);
    m_player->restart();

    std::ranges::fill(leftOut, 0.0f);
    std::ranges::fill(rightOut, 0.0f);

    m_player->processBlock(leftOut.data(), rightOut.data(), bufferSize);

    EXPECT_TRUE(m_player->isDone()) << "Player should stop when non-looping after playback";
}

TEST_F(StretchSamplePlayerTest, StereoOutputSymmetry)
{
    constexpr size_t bufferSize = 2048;
    std::vector<float> leftOut(bufferSize);
    std::vector<float> rightOut(bufferSize);

    m_player->runStereo(m_sineData);
    m_player->setPlaybackRate(1.0f);
    m_player->restart();

    std::ranges::fill(leftOut, 0.0f);
    std::ranges::fill(rightOut, 0.0f);

    m_player->processBlock(leftOut.data(), rightOut.data(), bufferSize);

    for (size_t i = 0; i < bufferSize; ++i)
    {
        EXPECT_NEAR(leftOut[i], rightOut[i], 0.001f)
            << "Stereo channels should be identical for mono input at sample " << i;
    }
}

} // namespace AbacDsp::Test
