#pragma once

#include "AudioFile.h"
#include <span>

namespace AudioUtility
{
class FileOut
{
  public:
    static AudioFile<float> ToAudioFile(std::span<const float> data, float sampleRate = 48000.f)
    {
        AudioFile<float> af;
        af.setNumChannels(1);
        af.setNumSamplesPerChannel(static_cast<int>(data.size()));
        af.samples[0].assign(data.begin(), data.end());
        af.setSampleRate(static_cast<int>(sampleRate));
        af.setBitDepth(24);
        return af;
    }

    static void saveAs(const std::string& filename, std::span<const float> data)
    {
        auto af = ToAudioFile(data);
        af.save(filename);
    }
};
}