#pragma once

#include "DSP/InterpolationCollection.h"
#include "DSP/SkipSmoothing.h"

#include "Modulation.h"

#include <algorithm>
#include <array>
#include <vector>

namespace OT::DSP
{

/*
 * no filters
 * no feedback
 * modulation
 * soft size adaption
 *
 * sizes: changed realtime when pitching or jump
 * in FADE it waits until fade done, then starts new fade for last position request
 *
 */

template <size_t MAXSIZE>
class ModulatingPlainDelay
{
  public:
    static constexpr size_t InterpolationPoints{2};
    explicit ModulatingPlainDelay(const float sampleRate)
        : m_modulation(sampleRate)
        , m_buffer(MAXSIZE + InterpolationPoints, 0.f)
    {
        setModulationSpeed(0.2f);
    }
    ~ModulatingPlainDelay() = default;
    ModulatingPlainDelay(const ModulatingPlainDelay&) = delete;
    ModulatingPlainDelay& operator=(const ModulatingPlainDelay&) = delete;
    ModulatingPlainDelay(ModulatingPlainDelay&& other) = delete;
    ModulatingPlainDelay& operator=(ModulatingPlainDelay&& other) = delete;

    void setSize(const size_t newSize)
    {
        setSizeImpl<false>(newSize);
    }

    void setSize(const size_t newSize, const SkipSmoothing_t&)
    {
        setSizeImpl<true>(newSize);
    }

    void setModulationDepth(const float depth)
    {
        m_modulationDepth = depth * 250.f;
        trimModulationDepth();
    }

    void setModulationSpeed(const float speedHz)
    {
        m_modulation.setModulationSpeed(speedHz);
    }

    float step(const float in)
    {
        m_modulation.tick();
        newFadeIfNeeded();
        feedWrite(in);
        if (m_fadeSteps)
        {
            const auto outValue = nextHeadRead(0) * m_fadeFactorOut;
            const auto inValue = nextHeadRead(1) * m_fadeFactorIn;
            m_fadeFactorOut -= m_fadeAdvance;
            m_fadeFactorIn += m_fadeAdvance;
            if (--m_fadeSteps == 0)
            {
                m_headRead[0] = m_headRead[1];
                m_newFadeSize = m_newFadeSizeScheduled;
                m_newFadeSizeScheduled = 0;
            }
            return outValue + inValue;
        }
        return nextHeadRead(0);
    }

    void processBlock(const float* source, float* target, const size_t numSamples)
    {
        std::transform(source, source + numSamples, target, [this](const float in) { return step(in); });
    }

    [[nodiscard]] size_t size() const
    {
        return m_currentDelayWidth;
    }

  private:
    template <bool fastSetting>
    void setSizeImpl(const size_t newSize)
    {
        const auto clampedSize = std::clamp<size_t>(newSize, 48, MAXSIZE - 1);
        if (clampedSize == m_currentDelayWidth)
        {
            return;
        }
        if constexpr (fastSetting)
        {
            m_currentDelayWidth = clampedSize;
            m_newFadeSizeScheduled = 0;
            m_newFadeSize = 0;
            m_headWrite = m_currentDelayWidth;
            m_headRead[0] = 0;
            return;
        }
        if (m_newFadeSize)
        {
            m_newFadeSizeScheduled = clampedSize;
        }
        else
        {
            m_newFadeSize = clampedSize;
        }
    }

    void trimModulationDepth()
    {
        m_modulation.setModulationDepth(std::min(static_cast<float>(m_currentDelayWidth - 3), m_modulationDepth));
    }

    void newFadeIfNeeded()
    {
        if (m_newFadeSize && !m_fadeSteps)
        {
            m_fadeFactorIn = 0.0f;
            m_fadeFactorOut = 1.0f;
            m_fadeSteps = std::min<size_t>(8192, m_currentDelayWidth / 2);
            m_fadeAdvance = 1.0f / static_cast<float>(m_fadeSteps);
            m_headRead[1] = (m_headWrite + MAXSIZE - m_newFadeSize) % MAXSIZE;
            m_currentDelayWidth = m_newFadeSize;
            trimModulationDepth();
        }
    }

    void feedWrite(const float in)
    {
        m_buffer[m_headWrite] = in;

        // replicate values of begin at end, so we don't need to do handle InterPolate on splitted buffer
        if (m_headWrite < InterpolationPoints)
        {
            const size_t padIndex = m_headWrite + MAXSIZE;
            m_buffer[padIndex] = m_buffer[m_headWrite];
        }

        if (++m_headWrite >= MAXSIZE)
        {
            m_headWrite = 0;
        }
    }

    float nextHeadRead(const size_t index)
    {
        if (m_modulation.isModulating())
        {
            const auto [depth, fraction] = m_modulation.lastValuePair();

            auto dHead = m_headRead[index] + static_cast<size_t>(depth);
            if (dHead >= MAXSIZE)
            {
                dHead -= MAXSIZE;
            }
            m_headRead[index] = (m_headRead[index] + 1) % MAXSIZE;
            return Interpolation<float>::linearPt2(&m_buffer[dHead], fraction);
        }

        const auto returnValue = m_buffer[m_headRead[index]];
        m_headRead[index] = (m_headRead[index] + 1) % MAXSIZE;
        return returnValue;
    }

    std::array<size_t, 2> m_headRead{0, 0};

    size_t m_headWrite{MAXSIZE / 8};
    // fade strategy
    size_t m_fadeSteps{0};
    float m_fadeFactorIn{0.0f};
    float m_fadeFactorOut{0.0f};
    float m_fadeAdvance{0.0f};
    size_t m_newFadeSize{0};
    size_t m_newFadeSizeScheduled{0};

    size_t m_currentDelayWidth{MAXSIZE / 8};
    Modulation m_modulation;
    float m_modulationDepth{0};
    std::vector<float> m_buffer;
};

}
