#pragma once

#include "EffectBase.h"
#include "Audio/AudioBuffer.h"
#include "Delays/NaiveDelay.h"

#include <cassert>
#include <cstdint>
#include <cmath>
#include <functional>

template <size_t BlockSize>
class DelayImpl final : public EffectBase
{
  public:
    using Delay = AbacDsp::NaiveDelay<48000>;
    DelayImpl(const float sampleRate)
        : EffectBase(sampleRate)
        , m_delay{Delay(sampleRate), Delay(sampleRate)}
    {
        m_visualWavedata.resize(6000);
    }
    void setGain(const float value)
    {
        m_gain = std::pow(10.f, value / 20.f);
    }

    void processBlock(const AbacDsp::AudioBuffer<2, BlockSize>& in, AbacDsp::AudioBuffer<2, BlockSize>& out)
    {
        for (size_t i = 0; i < BlockSize; ++i)
        {
            out(i, 0) = m_delay[0].step(in(i, 0)) + in(i, 0);
            out(i, 1) = m_delay[1].step(in(i, 1)) + in(i, 1);
        }

        m_visualWavedata[m_currentSample] = out(0, 0) * 0.5f;
        m_currentSample++;
        if (m_currentSample >= m_visualWavedata.size())
        {
            m_currentSample = 0;
        }
    }
    const std::vector<float>& visualizeWaveData()
    {
        m_preparedWavedata.resize(m_visualWavedata.size());
        m_preparedWavedata = m_visualWavedata;
        return m_preparedWavedata;
    }

  private:
    float m_gain{};
    std::array<AbacDsp::NaiveDelay<48000>, 2> m_delay;
    std::vector<float> m_visualWavedata;
    std::vector<float> m_preparedWavedata;
    size_t m_currentSample = 0;
};