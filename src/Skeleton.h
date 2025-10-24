#pragma once

#include <algorithm>
#include <array>
#include <vector>

namespace AbacDsp
{

class Skeleton
{
  public:
    Skeleton(const float sampleRate)
        : m_sampleRate(sampleRate)
    {
    }

    float step(const float in)
    {
        return in;
    }

    void processBlock(const float* source, float* target, const size_t numSamples)
    {
        std::transform(source, source + numSamples, target, [this](const float in) { return step(in); });
    }

  private:
    float m_sampleRate;
};

}
