#pragma once

#include "EffectBase.h"
#include "Analysis/Spectrogram.h"
#include "Audio/AudioBuffer.h"
#include "AudioFile/LoadOgg.h"
#include "SamplerateConverter/ConvertSampleBuffer.h"
#include "Sampler/SamplePlayerBasic.h"

#include <cassert>
#include <cstdint>
#include <cmath>
#include <functional>

template <size_t BlockSize>
class SamplePlayer final : public EffectBase
{
  public:
    explicit SamplePlayer(const float sampleRate)
        : EffectBase(sampleRate)
    {
        loadSet(0, "DOLPHINS", 'a');
        loadSet(10, "DOLPHINS", 'b');
        for (size_t i = 0; i < m_smplPlayer.size(); ++i)
        {
            if (m_samples[i] != nullptr)
            {
                m_smplPlayer[i].runStereo(m_samples[i], 1.f);
                m_smplPlayer[i].setLoop(false);
                m_smplPlayer[i].restart();
            }
        }
    }
    void loadSet(const size_t baseIdx, const std::string& folder, const char letter)
    {
        for (size_t i = 0; i < 10; ++i)
        {
            std::stringstream ss;
            ss << "/Users/scjurgen/projects/mynoise/" << folder << "/" << i << letter << ".ogg";
            loadSample(baseIdx + i, ss.str());
        }
    }
    void loadSample(const size_t index, const std::string& fname)
    {
        if (std::vector<float> sampleTmp; AudioUtility::LoadOgg::loadStereoInterleavedFromFile(fname, sampleTmp))
        {
            std::vector<float> sampleTmpSRC;
            const auto ratio = sampleRate() / static_cast<float>(AudioUtility::LoadOgg::getSampleRate(fname));
            AbacDsp::ConvertSampleBuffer::convert<2>(ratio, sampleTmp, sampleTmpSRC);
            std::cout << "Loaded " << sampleTmpSRC.size() / 2 / sampleRate() << " seconds from " << fname << "\n";
            m_samples[index] = std::make_shared<std::vector<float>>(sampleTmpSRC);
        }
        else
        {
            std::cout << "couldn't read " << fname << "\n";
        }
    }

    void setVol(const float valueDb)
    {
        m_vol = std::pow(10.f, valueDb / 20.f);
    }

    void setReverbLevel(const float valueDb)
    {
        m_reverbLevel = std::pow(10.f, valueDb / 20.f);
    }

    void setChannelLevel(const size_t index, const float valueDb)
    {
        m_chanLevel[index] = valueDb <= -99.f ? 0 : std::pow(10.f, valueDb / 20.f);
    }

    void setVol1(const float value)
    {
        setChannelLevel(0, value);
    }

    void setVol2(const float value)
    {
        setChannelLevel(1, value);
    }

    void setVol3(const float value)
    {
        setChannelLevel(2, value);
    }

    void setVol4(const float value)
    {
        setChannelLevel(3, value);
    }

    void setVol5(const float value)
    {
        setChannelLevel(4, value);
    }

    void setVol6(const float value)
    {
        setChannelLevel(5, value);
    }

    void setVol7(const float value)
    {
        setChannelLevel(6, value);
    }

    void setVol8(const float value)
    {
        setChannelLevel(7, value);
    }

    void setVol9(const float value)
    {
        setChannelLevel(8, value);
    }

    void setVol10(const float value)
    {
        setChannelLevel(9, value);
    }

    void checkDone()
    {
        for (size_t i = 0; i < m_smplPlayer.size(); ++i)
        {
            if (m_smplPlayer[i].isDone())
            {
                auto idx = 10 * (rand() % 2); // NOLINT
                if (m_samples[i + idx] != nullptr)
                {
                    m_smplPlayer[i].runStereo(m_samples[i + idx], 1.f);
                    m_smplPlayer[i].setLoop(false);
                    m_smplPlayer[i].restart();
                }
            }
        }
    }
    void processBlock(const AbacDsp::AudioBuffer<2, BlockSize>&, AbacDsp::AudioBuffer<2, BlockSize>& out)
    {
        std::array<std::array<float, BlockSize>, 2> sum{};

        for (size_t c = 0; c < m_smplPlayer.size(); ++c)
        {
            std::array<std::array<float, BlockSize>, 2> tmp{};
            m_smplPlayer[c].processBlock(tmp[0].data(), tmp[1].data(), BlockSize);
            for (size_t i = 0; i < BlockSize; ++i)
            {
                sum[0][i] += tmp[0][i] * m_chanLevel[c];
                sum[1][i] += tmp[1][i] * m_chanLevel[c];
            }
        }
        for (size_t i = 0; i < BlockSize; ++i)
        {
            out(i, 0) = sum[0][i] * m_vol;
            out(i, 1) = sum[1][i] * m_vol;
        }
        checkDone();
    }

  private:
    size_t m_index{0};
    std::vector<float> m_sample;
    float m_vol{};
    std::array<float, 10> m_chanLevel{};
    float m_reverbLevel{};
    std::array<std::shared_ptr<std::vector<float>>, 20> m_samples;

    std::array<AbacDsp::SamplePlayerBasic, 10> m_smplPlayer;
};