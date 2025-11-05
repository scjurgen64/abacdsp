#pragma once

#include "EffectBase.h"
#include "Analysis/Spectrogram.h"
#include "Audio/AudioBuffer.h"

#include <cassert>
#include <cstdint>
#include <cmath>
#include <functional>

template <size_t BlockSize>
class GenericImpl final : public EffectBase
{
  public:
    GenericImpl(const float sampleRate)
        : EffectBase(sampleRate)
    {
    }
    void setVol(const float value)
    {
        m_vol = std::pow(10.f, value / 20.f);
    }
    void setReverbLevel(const float value)
    {
        m_reverbLevel = std::pow(10.f, value / 20.f);
    }
    void setVol1(const float value)
    {
        m_vol1 = std::pow(10.f, value / 20.f);
    }
    void setVol2(const float value)
    {
        m_vol2 = std::pow(10.f, value / 20.f);
    }
    void setVol3(const float value)
    {
        m_vol3 = std::pow(10.f, value / 20.f);
    }
    void setVol4(const float value)
    {
        m_vol4 = std::pow(10.f, value / 20.f);
    }
    void setVol5(const float value)
    {
        m_vol5 = std::pow(10.f, value / 20.f);
    }
    void setVol6(const float value)
    {
        m_vol6 = std::pow(10.f, value / 20.f);
    }
    void setVol7(const float value)
    {
        m_vol7 = std::pow(10.f, value / 20.f);
    }
    void setVol8(const float value)
    {
        m_vol8 = std::pow(10.f, value / 20.f);
    }
    void setVol9(const float value)
    {
        m_vol9 = std::pow(10.f, value / 20.f);
    }
    void setVol10(const float value)
    {
        m_vol10 = std::pow(10.f, value / 20.f);
    }

    void processBlock(const AbacDsp::AudioBuffer<2, BlockSize>& in, AbacDsp::AudioBuffer<2, BlockSize>& out)
    {
        for (size_t i = 0; i < BlockSize; ++i)
        {
            out(i, 0) = in(i, 0);
            out(i, 1) = in(i, 1);
        }
    }

  private:
    float m_vol{};
    float m_reverbLevel{};
    float m_vol1{};
    float m_vol2{};
    float m_vol3{};
    float m_vol4{};
    float m_vol5{};
    float m_vol6{};
    float m_vol7{};
    float m_vol8{};
    float m_vol9{};
    float m_vol10{};
};