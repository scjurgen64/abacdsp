#pragma once

#include "EffectBase.h"
#include "Analysis/Spectrogram.h"
#include "Audio/AudioBuffer.h"

#include <cassert>
#include <cstdint>
#include <cmath>
#include <functional>

template <size_t BlockSize>
class MiniReverbImpl final : public EffectBase
{
  public:
    MiniReverbImpl(const float sampleRate)
        : EffectBase(sampleRate)
    {
    }
    void setOrder(const size_t value)
    {
        m_order = value;
    }
    void setDry(const float value)
    {
        m_dry = std::pow(10.f, value / 20.f);
    }
    void setWet(const float value)
    {
        m_wet = std::pow(10.f, value / 20.f);
    }
    void setLowSize(const float value)
    {
        m_lowSize = value;
    }
    void setHighSize(const float value)
    {
        m_highSize = value;
    }
    void setUniqueDelay(const bool value)
    {
        m_uniqueDelay = value;
    }
    void setBulge(const float value)
    {
        m_bulge = value;
    }
    void setDecay(const float value)
    {
        m_decay = value;
    }
    void setAllPassUp(const float value)
    {
        m_allPassUp = value;
    }
    void setAllPassDown(const float value)
    {
        m_allPassDown = value;
    }
    void setAllPassCount(const size_t value)
    {
        m_allPassCount = value;
    }
    void setLowPass(const float value)
    {
        m_lowPass = value;
    }
    void setHighPass(const float value)
    {
        m_highPass = value;
    }
    void setModulationDepth(const float value)
    {
        m_modulationDepth = value;
    }
    void setModulationSpeed(const float value)
    {
        m_modulationSpeed = value;
    }
    void setModulationCount(const size_t value)
    {
        m_modulationCount = value;
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
    bool m_order{};
    float m_dry{};
    float m_wet{};
    float m_lowSize{};
    float m_highSize{};
    size_t m_uniqueDelay{};
    float m_bulge{};
    float m_decay{};
    float m_allPassUp{};
    float m_allPassDown{};
    bool m_allPassCount{};
    float m_lowPass{};
    float m_highPass{};
    float m_modulationDepth{};
    float m_modulationSpeed{};
    bool m_modulationCount{};
};