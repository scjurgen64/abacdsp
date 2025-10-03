#pragma once

#include "Numbers/Interpolation.h"
#include "Modulation/Wow.h"
#include "Audio/FixedSizeProcessor.h"
#include <algorithm>
#include <vector>
#include <cmath>

namespace AbacDsp
{

/*
 *
 * | ------------- rd ---------- wr -------------|
 * | ------------------ nrd ---- wr -------------|
 *
 * reduce distance:
 *     m_advanceDirection > 0.f:
 *         delta = targetRead - currentRead
 *         delta < 0 -> target reached
 *         delta < 100 -> slow down
 *
 *
 *
 *
 *
 */

template <size_t MaxSizeInSamples>
class OuModDelay
{
  public:
    static constexpr size_t WowStep{8};
    explicit OuModDelay(const float sampleRate)
        : m_sampleRate(sampleRate)
        , m_buffer(MaxSizeInSamples + 6)
        , m_wow(sampleRate / WowStep)
    {
        m_wow.setDepth(0.1f);
        m_wow.setRate(0.25f);
        m_wow.setDrift(0.1f);
        m_wow.setVariance(0.1f);
    }

    void setWidthInMsecs(float milliseconds)
    {
        m_setByTime = true;
        auto newSize = std::clamp<size_t>(getSamplesPerMillisecond(milliseconds, m_sampleRate, MaxSizeInSamples), 48u,
                                          MaxSizeInSamples - 1);

        if (newSize == m_currentDistance)
        {
            return;
        }
        m_lastDistanceRequested = newSize;
    }

    void setSize(size_t newSize)
    {
        if (newSize >= MaxSizeInSamples)
        {
            newSize = MaxSizeInSamples - 1;
        }
        if (newSize == m_currentDistance)
        {
            return;
        }
        m_setByTime = false;
        m_lastDistanceRequested = newSize;
    }

    void setFeedback(const float gain)
    {
        m_feedback = std::clamp(gain, -0.99999f, 0.99999f);
    }

    void feedBackByTime(const float msecs, const float db = 0.001f, const bool negative = false)
    {
        m_decayMsecs = msecs;
        const auto feedback = std::pow(db, m_currentDistance / m_sampleRate / (msecs / 1000.0f));
        setFeedback(negative ? -feedback : feedback);
    }

    void setModDepth(const float depth) noexcept
    {
        m_wow.setDepth(depth);
    }

    void setModSpeed(const float speedHz) noexcept
    {
        m_wow.setRate(speedHz);
    }

    void setModVariance(const float variance) noexcept
    {
        m_wow.setVariance(variance);
    }

    void setModDrift(const float drift) noexcept
    {
        m_wow.setDrift(drift);
    }

    int m_wowCount{WowStep - 1};
    float m_lastWow{0.f};
    float step(const float in) noexcept
    {
        if (--m_wowCount <= 0)
        {
            m_lastWow = m_wow.step() * 100.f;
            m_wowCount = WowStep;
        }
        float dHead = m_headRead + m_lastWow;
        if (dHead >= MaxSizeInSamples)
        {
            dHead -= MaxSizeInSamples;
        }
        float intTailPosition;
        const auto fraction = modff(dHead, &intTailPosition);
        const auto bufferValue = Interpolation::hermite43z(&m_buffer[static_cast<size_t>(intTailPosition)], fraction);
        const auto feedDelay = in + bufferValue * m_feedback;
        const auto ret = bufferValue;
        m_buffer[m_headWrite] = feedDelay;

        if (m_headWrite < 6)
        {
            const auto padIndex = m_headWrite + MaxSizeInSamples;
            m_buffer[padIndex] = m_buffer[m_headWrite];
        }

        m_headWrite++;
        if (m_headWrite >= MaxSizeInSamples)
        {
            m_headWrite = 0;
        }
        if (m_advanceSteps)
        {
            long dt;
            if (m_headWrite > m_headRead)
            {
                dt = m_headWrite - (long) m_headRead;
            }
            else
            {
                dt = m_headWrite + MaxSizeInSamples - (long) m_headRead;
            }

            m_currentDistance = dt;
            if (static_cast<size_t>(dt) / 4 == m_newDistance / 4)
            {
                m_advanceSteps = false;
                m_advance = 1.0;
                if (m_setByTime)
                {
                    feedBackByTime(m_decayMsecs);
                }
            }
        }
        else
        {
            if (m_lastDistanceRequested)
            {
                adjustBufferByPitching(m_lastDistanceRequested + 3);
                m_lastDistanceRequested = 0;
            }
        }
        m_headRead += m_advance;
        if (m_headRead >= MaxSizeInSamples)
        {
            m_headRead -= MaxSizeInSamples;
        }
        return ret;
    }

    bool isAdvancing() const noexcept
    {
        return m_advanceSteps;
    }

    template <size_t blockSize>
    void blockFill(const float* in, float* out) noexcept
    {
        for (uint32_t pos = 0; pos < blockSize; pos++)
        {
            out[pos] = step(in[pos]);
        }
    }

  private:
    void adjustBufferByPitching(const size_t newSize) noexcept
    {
        m_newDistance = newSize;
        if (newSize > m_currentDistance)
        {
            if (newSize == 0)
            {
                return;
            }
            m_advanceSteps = true;
            m_advance = 0.5f;
        }
        else
        {
            if (m_currentDistance == 0)
            {
                return;
            }
            m_advanceSteps = true;
            m_advance = 2.f;
        }
    }

    float m_sampleRate{48000.0f};
    float m_feedback{0};
    float m_headRead{0};
    size_t m_headWrite{0};
    float m_decayMsecs{100};
    // adapt soft buffersize *speed up/down*
    size_t m_currentDistance{MaxSizeInSamples / 10};
    size_t m_newDistance{0};
    size_t m_lastDistanceRequested{0};
    bool m_advanceSteps{false};
    float m_advance{1.0f};
    float m_advanceDirection{0.f};

    // modulation

    bool m_setByTime{false};
    std::vector<float> m_buffer;
    Wow m_wow;
};
}
