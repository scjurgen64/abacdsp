#pragma once

#include <memory>
#include <vector>

#include "Filters/Biquad.h"

namespace AbacDsp
{

class SamplePlayerBasic
{
  public:
    explicit SamplePlayerBasic(const float sampleRate)
        : m_sampleRate(sampleRate)
        , m_lowPassFilter(sampleRate)
    {
    }

    void runStereo(const std::shared_ptr<std::vector<float>>& data)
    {
        m_data = data;
    }

    void restart()
    {
        m_isDone = false;
        m_intPlayPos = 0;
        m_frac = 0.0f;
    }

    void setLoop(const bool loop)
    {
        m_loop = loop;
    }

    void setPlaybackRate(const float rate)
    {
        m_advanceFactor = rate;
        m_needsFiltering = rate < 1.0f;
        if (m_needsFiltering)
        {
            const float cutoffFreq = (m_sampleRate * 0.5f) * rate * 0.8f;
            m_lowPassFilter.computeType1(4, cutoffFreq, 0.5f, true);
        }
    }

    void processBlock(float* targetAddLeft, float* targetAddRight, const size_t numSamples)
    {
        if (m_isDone || !m_data)
        {
            return;
        }

        const size_t dataSize = m_data->size() / 2;
        const float* samples = m_data->data();

        for (size_t i = 0; i < numSamples; ++i)
        {
            if (m_intPlayPos + 2 >= dataSize)
            {
                if (m_loop)
                {
                    m_intPlayPos = 0;
                    m_frac = 0.0f;
                    continue;
                }
                m_isDone = true;
                return;
            }

            // 4-point Hermite interpolation (stereo interleaved)
            const size_t pPos = m_intPlayPos * 2;
            const float ym1_L = samples[pPos];
            const float y0_L = samples[pPos + 2];
            const float y1_L = samples[pPos + 4];
            const float y2_L = samples[pPos + 6];

            const float ym1_R = samples[pPos + 1];
            const float y0_R = samples[pPos + 3];
            const float y1_R = samples[pPos + 5];
            const float y2_R = samples[pPos + 7];

            const float c0_L = y0_L;
            const float c1_L = 0.5f * (y1_L - ym1_L);
            const float c2_L = ym1_L - 2.5f * y0_L + 2.0f * y1_L - 0.5f * y2_L;
            const float c3_L = 0.5f * (y2_L - ym1_L) + 1.5f * (y0_L - y1_L);

            const float c0_R = y0_R;
            const float c1_R = 0.5f * (y1_R - ym1_R);
            const float c2_R = ym1_R - 2.5f * y0_R + 2.0f * y1_R - 0.5f * y2_R;
            const float c3_R = 0.5f * (y2_R - ym1_R) + 1.5f * (y0_R - y1_R);

            float outL = ((c3_L * m_frac + c2_L) * m_frac + c1_L) * m_frac + c0_L;
            float outR = ((c3_R * m_frac + c2_R) * m_frac + c1_R) * m_frac + c0_R;

            targetAddLeft[i] += outL;
            targetAddRight[i] += outR;

            m_frac += m_advanceFactor;
            const auto increment = static_cast<size_t>(m_frac);
            m_frac -= static_cast<float>(increment);
            m_intPlayPos += increment;
        }

        if (m_needsFiltering)
        {
            m_lowPassFilter.processBlockStereo(targetAddLeft, targetAddRight, targetAddLeft, targetAddRight,
                                               numSamples);
        }
    }

    [[nodiscard]] bool isDone() const
    {
        return m_isDone;
    }

  private:
    std::shared_ptr<std::vector<float>> m_data{};
    size_t m_intPlayPos{0};
    float m_frac{0.0f};
    float m_advanceFactor{1.0f};
    bool m_loop{false};
    bool m_isDone{true};
    const float m_sampleRate;
    ChebyshevBiquad m_lowPassFilter;
    bool m_needsFiltering{false};
};

}
