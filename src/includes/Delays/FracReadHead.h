#pragma once

#include <cassert>
#include <cmath>

namespace AbacDsp
{
template <size_t WrapSize>
class FracReadHead
{
  public:
    explicit FracReadHead(const float sampleRate)
        : m_sampleRate(sampleRate)
    {
    }

    void setDelta(const float delta, const float maxFactor)
    {
        assert(maxFactor > 1.f); // greater 1 otherwise we can not modify the advance head
        assert(delta > 1.f);     // at least a distance of one cell
        if (m_targetDelta == delta)
        {
            return;
        }
        m_maxFactor = maxFactor;
        m_isAdjusting = true;
        m_targetDelta = delta;
    }


    float step(const float currentHead)
    {
        if (m_isAdjusting)
        {
            const auto delta = currentHead - m_pos;
            if (delta <= m_targetDelta) // slow down
            {
            }
            if (delta >= m_targetDelta) // speed up
            {
            }
            // add reaching logic, phase of easy in and easy out etc.
        }
        m_pos += m_advance;
        if (m_pos >= WrapSize)
        {
            m_pos -= WrapSize;
        }
        return m_pos;
    }

  private:
    float m_sampleRate;

    float m_pos{0.f};
    float m_advance{1.f};

    bool m_isAdjusting{false};
    float m_maxFactor{2.f};
    float m_direction{0};
    float m_targetDelta{0.f};
};
}