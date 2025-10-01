#pragma once

#include "EffectBase.h"
#include "Analysis/Spectrogram.h"
#include "Audio/AudioBuffer.h"
#include "Reverbs/FdnReverb.h"
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
        , m_fdnTank{sampleRate}
    {
    }

    void setOrder(const size_t value)
    {
        std::vector<size_t> orderMap{4, 8, 12, 16, 20, 24, 32};
        m_order = value;
        m_fdnTank.setOrder(orderMap[value]);
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
        m_fdnTank.setMinSize(value);
    }
    void setHighSize(const float value)
    {
        m_highSize = value;
        m_fdnTank.setMaxSize(value);
    }
    void setUniqueDelay(const bool value)
    {
        m_uniqueDelay = value;
        m_fdnTank.setUniqueDelay(value);
    }

    void setBulge(const float value)
    {
        m_bulge = value;
        m_fdnTank.setSpreadBulge(value);
    }

    void setDecay(const float value)
    {
        m_decay = value;
        m_fdnTank.setDecay(value);
    }

    void setAllPassUp(const float value)
    {
        m_allPassUp = value;
        m_fdnTank.setAllpassFirstCutoff(value);
    }
    void setAllPassDown(const float value)
    {
        m_allPassDown = value;
        m_fdnTank.setAllpassLastCutoff(value);
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
        std::array<float, BlockSize> inData{};
        for (size_t i = 0; i < BlockSize; ++i)
        {
            inData[i] = in(i, 0) + in(i, 1);
        }
        std::array<float, BlockSize> left{};
        std::array<float, BlockSize> right{};
        // m_fdnTank.processBlock(inData.data(), left.data(), BlockSize);
        // for (size_t i = 0; i < BlockSize; ++i)
        // {
        //     out(i, 0) = m_dry * in(i, 0) + m_wet * left[i];
        //     out(i, 1) = m_dry * in(i, 1) + m_wet * left[i];
        // }
        m_fdnTank.processBlockSplit(inData.data(), left.data(), right.data(), BlockSize);
        for (size_t i = 0; i < BlockSize; ++i)
        {
            out(i, 0) = m_dry * in(i, 0) + m_wet * left[i];
            out(i, 1) = m_dry * in(i, 1) + m_wet * right[i];
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

    AbacDsp::FdnTank<100000, 32> m_fdnTank;
};