#pragma once

#include "EffectBase.h"
#include "Audio/AudioBuffer.h"
#include "Reverbs/FdnTankSpiced.h"
#include "Reverbs/FdnTankBlockDelayWalsh.h"
#include "Reverbs/FdnTankBlockDelayWalshSIMD.h"


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
        const std::vector<size_t> orderMap{4, 8, 12, 16, 20, 24, 32, 48, 64};
        m_order = value;
        // m_fdnTank.setOrder(orderMap[value]);
    }

    void setDry(const float value)
    {
        m_dry = std::pow(10.f, value / 20.f);
    }

    void setWet(const float value)
    {
        m_wet = std::pow(10.f, value / 20.f);
    }

    void setStereoWidth(const float value)
    {
        // m_width = value;
    }

    void setBaseSize(const float value)
    {
        m_baseSize = value;
        m_fdnTank.setMinSize(value);
        m_fdnTank.setMaxSize(m_baseSize * m_sizeFactor);
    }

    void setSizeFactor(const float value)
    {
        m_sizeFactor = value;
        m_fdnTank.setMaxSize(m_baseSize * m_sizeFactor);
    }

    void setUniqueDelay(const bool value)
    {
        m_fdnTank.setUniqueDelay(value);
    }

    void setBulge(const float value)
    {
        m_fdnTank.setSpreadBulge(value);
    }

    void setDecay(const float value)
    {
        m_fdnTank.setDecay(value);
    }

    void setAllPassUp(const float value)
    {
        // m_fdnTank.setAllpassFirstCutoff(value);
    }
    void setAllPassDown(const float value)
    {
        // m_fdnTank.setAllpassLastCutoff(value);
    }
    void setLowPass(const float value)
    {
        // m_fdnTank.setLowpass(value);
    }
    void setHighPass(const float value)
    {
        // m_fdnTank.setHighpass(value);
    }

    void setModulationCount(const size_t value)
    {
        // m_fdnTank.setModulationCount(value);
    }

    void setLowPassCount(const float value)
    {
        // m_fdnTank.setLowPassCount(value);
    }

    void setHighPassCount(const float value)
    {
        // m_fdnTank.setHighPassCount(value);
    }

    void setModulationDepth(const float value)
    {
        // m_fdnTank.setModulationDepth(value);
    }

    void setModulationSpeed(const float value)
    {
        // m_fdnTank.setModulationSpeed(value);
    }

    void setReversePitch(const float value)
    {
        // m_fdnTank.setReversePitch(value);
    }

    void setPitchStrength(const float value)
    {
        // m_fdnTank.setPitchStrength(value);
    }

    void setPitch1Inplace(const float value)
    {
        // m_fdnTank.setPitch1Inplace(value);
    }

    void setPitch2Inplace(const float value)
    {
        // m_fdnTank.setPitch2Inplace(value);
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
        // m_fdnTank.processBlock(inData.data(), left.data());
        // for (size_t i = 0; i < BlockSize; ++i)
        // {
        //     out(i, 0) = m_dry * in(i, 0) + m_wet * left[i];
        //     out(i, 1) = m_dry * in(i, 1) + m_wet * left[i];
        // }

        m_fdnTank.processBlockSplit(inData.data(), left.data(), right.data());
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
    float m_baseSize{};
    float m_sizeFactor{};

    AbacDsp::FdnTankSpiced<100000, 32, 16> m_fdnTank;
};