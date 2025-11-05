#pragma once

#include <memory>
#include <vector>
namespace AbacDsp
{
class SamplePlayerBasic
{
  public:
    void runStereo(const std::shared_ptr<std::vector<float>>& data, const float gain)
    {
        m_data = data;
        m_gain = gain;
    }

    void restart()
    {
        m_isDone = false;
        m_playPos = 0.0f;
    }

    void setLoop(const bool loop)
    {
        m_loop = loop;
    }

    void setPlaybackRate(const float rate)
    {
        m_advanceFactor = rate * 2.0f; // N.B.: stereo interleaved
    }

    void processBlock(float* targetAddLeft, float* targetAddRight, const size_t numSamples)
    {
        if (m_isDone || !m_data)
        {
            return;
        }

        const size_t dataSize = m_data->size();
        const float* samples = m_data->data();

        for (size_t i = 0; i < numSamples; ++i)
        {
            const auto pos = static_cast<size_t>(m_playPos);

            if (pos + 3 >= dataSize)
            {
                if (m_loop)
                {
                    m_playPos = 0.0f;
                    continue;
                }

                m_isDone = true;
                return;
            }

            const float frac = m_playPos - static_cast<float>(pos);

            // 4-point Hermite interpolation (stereo interleaved)
            const float ym1_L = samples[pos > 0 ? pos - 2 : pos];
            const float y0_L = samples[pos];
            const float y1_L = samples[pos + 2];
            const float y2_L = samples[pos + 4];

            const float ym1_R = samples[pos > 0 ? pos - 1 : pos + 1];
            const float y0_R = samples[pos + 1];
            const float y1_R = samples[pos + 3];
            const float y2_R = samples[pos + 5];

            const float c0_L = y0_L;
            const float c1_L = 0.5f * (y1_L - ym1_L);
            const float c2_L = ym1_L - 2.5f * y0_L + 2.0f * y1_L - 0.5f * y2_L;
            const float c3_L = 0.5f * (y2_L - ym1_L) + 1.5f * (y0_L - y1_L);

            const float c0_R = y0_R;
            const float c1_R = 0.5f * (y1_R - ym1_R);
            const float c2_R = ym1_R - 2.5f * y0_R + 2.0f * y1_R - 0.5f * y2_R;
            const float c3_R = 0.5f * (y2_R - ym1_R) + 1.5f * (y0_R - y1_R);

            targetAddLeft[i] += (((c3_L * frac + c2_L) * frac + c1_L) * frac + c0_L) * m_gain;
            targetAddRight[i] += (((c3_R * frac + c2_R) * frac + c1_R) * frac + c0_R) * m_gain;

            m_playPos += m_advanceFactor;
        }
    }

    [[nodiscard]] bool isDone() const
    {
        return m_isDone;
    }

  private:
    float m_gain{1.f};
    std::shared_ptr<std::vector<float>> m_data{};
    float m_playPos{0.0f};
    float m_advanceFactor{2.0f};
    bool m_loop{false};
    bool m_isDone{true};
};
}
