#pragma once
/*
 * AUTO GENERATED,
 * NOT A GOOD IDEA TO CHANGE STUFF HERE
 * Keep the file readonly
 */

#include "Analysis/EnvelopeFollower.h"
#include "Analysis/Spectrogram.h"

#include "Audio/FixedSizeProcessor.h"

#include "UiElements.h"

#include "impl/SamplePlayer.h"

#include <juce_audio_processors/juce_audio_processors.h>

class AudioPluginAudioProcessor : public juce::AudioProcessor, public juce::AudioProcessorValueTreeState::Listener
{
  public:
    static constexpr size_t NumSamplesPerBlock = 16;
    AudioPluginAudioProcessor()
        : AudioProcessor(BusesProperties()
#if !JucePlugin_IsMidiEffect
#if !JucePlugin_IsSynth
                             .withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
                             .withOutput("Output", juce::AudioChannelSet::stereo(), true)
#endif
                             )
        , fixedRunner([this](const AbacDsp::AudioBuffer<2, NumSamplesPerBlock>& input,
                             AbacDsp::AudioBuffer<2, NumSamplesPerBlock>& output)
                      { pluginRunner->processBlock(input, output); })
        , m_parameters(*this, nullptr, "PARAMETERS", createParameterLayout())
        , m_avgCpu(8, 0)
        , m_head{0}
        , m_runningWindowCpu(8 * 300)
        , m_envInput{AbacDsp::RmsFollower(10000), AbacDsp::RmsFollower(10000)}
        , m_envOutput{AbacDsp::RmsFollower(10000), AbacDsp::RmsFollower(10000)}
        , m_spectrogram{}
    {
        m_parameters.addParameterListener("type", this);
        m_parameters.addParameterListener("subset", this);
        m_parameters.addParameterListener("solo", this);
        m_parameters.addParameterListener("vol", this);
        m_parameters.addParameterListener("reverbLevelWet", this);
        m_parameters.addParameterListener("reverbDecay", this);
        m_parameters.addParameterListener("reverbShimmer", this);
        m_parameters.addParameterListener("vol1", this);
        m_parameters.addParameterListener("vol2", this);
        m_parameters.addParameterListener("vol3", this);
        m_parameters.addParameterListener("vol4", this);
        m_parameters.addParameterListener("vol5", this);
        m_parameters.addParameterListener("vol6", this);
        m_parameters.addParameterListener("vol7", this);
        m_parameters.addParameterListener("vol8", this);
        m_parameters.addParameterListener("vol9", this);
        m_parameters.addParameterListener("vol10", this);
        m_parameters.addParameterListener("revFeed1", this);
        m_parameters.addParameterListener("revFeed2", this);
        m_parameters.addParameterListener("revFeed3", this);
        m_parameters.addParameterListener("revFeed4", this);
        m_parameters.addParameterListener("revFeed5", this);
        m_parameters.addParameterListener("revFeed6", this);
        m_parameters.addParameterListener("revFeed7", this);
        m_parameters.addParameterListener("revFeed8", this);
        m_parameters.addParameterListener("revFeed9", this);
        m_parameters.addParameterListener("revFeed10", this);
        m_parameters.addParameterListener("pitch1", this);
        m_parameters.addParameterListener("pitch2", this);
        m_parameters.addParameterListener("pitch3", this);
        m_parameters.addParameterListener("pitch4", this);
        m_parameters.addParameterListener("pitch5", this);
        m_parameters.addParameterListener("pitch6", this);
        m_parameters.addParameterListener("pitch7", this);
        m_parameters.addParameterListener("pitch8", this);
        m_parameters.addParameterListener("pitch9", this);
        m_parameters.addParameterListener("pitch10", this);
    }
    ~AudioPluginAudioProcessor() override = default;

    void prepareToPlay(double sampleRate, int samplesPerBlock) override
    {
        pluginRunner = std::make_unique<SamplePlayer<NumSamplesPerBlock>>(static_cast<float>(sampleRate));
        m_sampleRate = static_cast<size_t>(sampleRate);
        for (auto* param : getParameters())
        {
            if (auto* p = dynamic_cast<juce::RangedAudioParameter*>(param))
            {
                const auto normalizedValue = p->getValue();
                p->sendValueChangedMessageToListeners(normalizedValue);
            }
        }
        if (m_newState.isValid())
        {
            m_parameters.replaceState(m_newState);
        }

        juce::ignoreUnused(samplesPerBlock);
    }

    void releaseResources() override
    {
        pluginRunner = nullptr;
    }

    bool isBusesLayoutSupported(const BusesLayout& layouts) const override
    {
#if JucePlugin_IsMidiEffect
        juce::ignoreUnused(layouts);
        return true;
#else
        /* This is the place where you check if the layout is supported.
         * In this template code we only support mono or stereo.
         */
        if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono() &&
            layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        {
            return false;
        }

        /* This checks if the input layout matches the output layout */
#if !JucePlugin_IsSynth
        if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        {
            return false;
        }
#endif
        return true;
#endif
    }

    juce::AudioProcessorEditor* createEditor() override;

    bool hasEditor() const override
    {
        return true;
    }

    const juce::String getName() const override
    {
        return JucePlugin_Name;
    }

    bool acceptsMidi() const override
    {
#if JucePlugin_WantsMidiInput
        return true;
#else
        return false;
#endif
    }

    bool producesMidi() const override
    {
#if JucePlugin_ProducesMidiOutput
        return true;
#else
        return false;
#endif
    }

    bool isMidiEffect() const override
    {
#if JucePlugin_IsMidiEffect
        return true;
#else
        return false;
#endif
    }

    double getTailLengthSeconds() const override
    {
        return 2.0;
    }

    int getNumPrograms() override
    {
        return 1;
        /* NB: some hosts don't cope very well if you tell them there are 0 programs,
                   so this should be at least 1, even if you're not really implementing programs.
        */
    }

    int getCurrentProgram() override
    {
        return 0;
    }

    void setCurrentProgram(const int index) override
    {
        m_program = index;
    }

    const juce::String getProgramName(const int index) override
    {
        switch (index)
        {
            case 0:
                return {"Program 0"};
            case 1:
                return {"Program 1"};
            case 2:
                return {"Program 2"};
            default:
                return {"Program unknown"};
        }
    }

    void changeProgramName(int index, const juce::String& newName) override
    {
        juce::ignoreUnused(index, newName);
    }

    void getStateInformation(juce::MemoryBlock& destData) override
    {
        auto state = m_parameters.copyState();
        std::unique_ptr<juce::XmlElement> xml(state.createXml());
        if (xml != nullptr)
        {
            copyXmlToBinary(*xml, destData);
        }
    }

    void setStateInformation(const void* data, int sizeInBytes) override
    {
        std::unique_ptr xmlState(getXmlFromBinary(data, sizeInBytes));

        if (xmlState != nullptr)
        {
            if (xmlState->hasTagName(m_parameters.state.getType()))
            {
                m_newState = juce::ValueTree::fromXml(*xmlState);
            }
        }
    }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-float-conversion"
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
    {
        std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;
        params.push_back(std::make_unique<juce::AudioParameterChoice>(
            juce::ParameterID("type", 1), "Type",
            juce::StringArray{"DOLPHINS", "WIND", "RAINFOREST", "FOREST", "RAIN", "THUNDER", "TANPURA", "STREAM",
                              "OCEAN", "BOWLS", "CAFE", "RPGFOREST"},
            0));
        params.push_back(std::make_unique<juce::AudioParameterChoice>(
            juce::ParameterID("subset", 1), "Subset",
            juce::StringArray{"#1", "#2", "#3", "#4", "#5", "#6", "#7", "#8", "#9", "#10"}, 0));
        params.push_back(std::make_unique<juce::AudioParameterChoice>(
            juce::ParameterID("solo", 1), "Solo",
            juce::StringArray{"None", "Track 1", "Track 2", "Track 3", "Track 4", "Track 5", "Track 6", "Track 7",
                              "Track 8", "Track 9", "Track 10"},
            0));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("vol", 1), "Vol", juce::NormalisableRange<float>(-100, 12, 0.1, 1, false), 0,
            juce::String("Vol"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 1) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("reverbLevelWet", 1), "Reverb Wet", juce::NormalisableRange<float>(-120, 0, 1, 1, false),
            -120, juce::String("Reverb Wet"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("reverbDecay", 1), "Rev Decay",
            juce::NormalisableRange<float>(100, 100000, 1, 0.2, false), 1000, juce::String("Rev Decay"),
            juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " ms"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("reverbShimmer", 1), "Rev Shimmer", juce::NormalisableRange<float>(0, 100, 1, 1, false),
            0, juce::String("Rev Shimmer"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " %"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("vol1", 1), "Vol 1", juce::NormalisableRange<float>(-100, 0, 0.1, 1, false), -12,
            juce::String("Vol 1"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 1) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("vol2", 1), "Vol 2", juce::NormalisableRange<float>(-100, 0, 0.1, 1, false), -12,
            juce::String("Vol 2"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 1) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("vol3", 1), "Vol 3", juce::NormalisableRange<float>(-100, 0, 0.1, 1, false), -12,
            juce::String("Vol 3"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 1) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("vol4", 1), "Vol 4", juce::NormalisableRange<float>(-100, 0, 0.1, 1, false), -12,
            juce::String("Vol 4"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 1) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("vol5", 1), "Vol 5", juce::NormalisableRange<float>(-100, 0, 0.1, 1, false), -12,
            juce::String("Vol 5"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 1) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("vol6", 1), "Vol 6", juce::NormalisableRange<float>(-100, 0, 0.1, 1, false), -12,
            juce::String("Vol 6"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 1) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("vol7", 1), "Vol 7", juce::NormalisableRange<float>(-100, 0, 0.1, 1, false), -12,
            juce::String("Vol 7"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 1) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("vol8", 1), "Vol 8", juce::NormalisableRange<float>(-100, 0, 0.1, 1, false), -12,
            juce::String("Vol 8"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 1) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("vol9", 1), "Vol 9", juce::NormalisableRange<float>(-100, 0, 0.1, 1, false), -12,
            juce::String("Vol 9"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 1) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("vol10", 1), "Vol 10", juce::NormalisableRange<float>(-100, 0, 0.1, 1, false), -12,
            juce::String("Vol 10"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 1) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("revFeed1", 1), "Rev 1", juce::NormalisableRange<float>(-100, 0, 1, 1, false), -100,
            juce::String("Rev 1"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("revFeed2", 1), "Rev 2", juce::NormalisableRange<float>(-100, 0, 1, 1, false), -100,
            juce::String("Rev 2"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("revFeed3", 1), "Rev 3", juce::NormalisableRange<float>(-100, 0, 1, 1, false), -100,
            juce::String("Rev 3"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("revFeed4", 1), "Rev 4", juce::NormalisableRange<float>(-100, 0, 1, 1, false), -100,
            juce::String("Rev 4"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("revFeed5", 1), "Rev 5", juce::NormalisableRange<float>(-100, 0, 1, 1, false), -100,
            juce::String("Rev 5"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("revFeed6", 1), "Rev 6", juce::NormalisableRange<float>(-100, 0, 1, 1, false), -100,
            juce::String("Rev 6"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("revFeed7", 1), "Rev 7", juce::NormalisableRange<float>(-100, 0, 1, 1, false), -100,
            juce::String("Rev 7"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("revFeed8", 1), "Rev 8", juce::NormalisableRange<float>(-100, 0, 1, 1, false), -100,
            juce::String("Rev 8"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("revFeed9", 1), "Rev 9", juce::NormalisableRange<float>(-100, 0, 1, 1, false), -100,
            juce::String("Rev 9"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("revFeed10", 1), "Rev 10", juce::NormalisableRange<float>(-100, 0, 1, 1, false), -100,
            juce::String("Rev 10"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " dB"; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("pitch1", 1), "Pch 1", juce::NormalisableRange<float>(-48, 48, 1, 1, false), 0,
            juce::String("Pch 1"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " "; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("pitch2", 1), "Pch 2", juce::NormalisableRange<float>(-48, 48, 1, 1, false), 0,
            juce::String("Pch 2"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " "; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("pitch3", 1), "Pch 3", juce::NormalisableRange<float>(-48, 48, 1, 1, false), 0,
            juce::String("Pch 3"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " "; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("pitch4", 1), "Pch 4", juce::NormalisableRange<float>(-48, 48, 1, 1, false), 0,
            juce::String("Pch 4"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " "; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("pitch5", 1), "Pch 5", juce::NormalisableRange<float>(-48, 48, 1, 1, false), 0,
            juce::String("Pch 5"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " "; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("pitch6", 1), "Pch 6", juce::NormalisableRange<float>(-48, 48, 1, 1, false), 0,
            juce::String("Pch 6"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " "; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("pitch7", 1), "Pch 7", juce::NormalisableRange<float>(-48, 48, 1, 1, false), 0,
            juce::String("Pch 7"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " "; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("pitch8", 1), "Pch 8", juce::NormalisableRange<float>(-48, 48, 1, 1, false), 0,
            juce::String("Pch 8"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " "; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("pitch9", 1), "Pch 9", juce::NormalisableRange<float>(-48, 48, 1, 1, false), 0,
            juce::String("Pch 9"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " "; }));
        params.push_back(std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID("pitch10", 1), "Pch 10", juce::NormalisableRange<float>(-48, 48, 1, 1, false), 0,
            juce::String("Pch 10"), juce::AudioProcessorParameter::genericParameter,
            [](float value, float) { return juce::String(value, 0) + " "; }));

        return {params.begin(), params.end()};
    }
#pragma GCC diagnostic pop

    void parameterChanged(const juce::String& parameterID, float newValue) override
    {
        if (pluginRunner == nullptr)
        {
            return;
        }
        static const std::map<juce::String, std::function<void(AudioPluginAudioProcessor&, float)>> parameterMap{
            {"type", [](const AudioPluginAudioProcessor& p, const float v)
             { p.pluginRunner->setType(static_cast<size_t>(v)); }},
            {"subset", [](const AudioPluginAudioProcessor& p, const float v)
             { p.pluginRunner->setSubset(static_cast<size_t>(v)); }},
            {"solo", [](const AudioPluginAudioProcessor& p, const float v)
             { p.pluginRunner->setSolo(static_cast<size_t>(v)); }},
            {"vol", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setVol(v); }},
            {"reverbLevelWet",
             [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setReverbLevelWet(v); }},
            {"reverbDecay",
             [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setReverbDecay(v); }},
            {"reverbShimmer",
             [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setReverbShimmer(v); }},
            {"vol1", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setVol1(v); }},
            {"vol2", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setVol2(v); }},
            {"vol3", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setVol3(v); }},
            {"vol4", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setVol4(v); }},
            {"vol5", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setVol5(v); }},
            {"vol6", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setVol6(v); }},
            {"vol7", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setVol7(v); }},
            {"vol8", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setVol8(v); }},
            {"vol9", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setVol9(v); }},
            {"vol10", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setVol10(v); }},
            {"revFeed1", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setRevFeed1(v); }},
            {"revFeed2", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setRevFeed2(v); }},
            {"revFeed3", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setRevFeed3(v); }},
            {"revFeed4", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setRevFeed4(v); }},
            {"revFeed5", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setRevFeed5(v); }},
            {"revFeed6", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setRevFeed6(v); }},
            {"revFeed7", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setRevFeed7(v); }},
            {"revFeed8", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setRevFeed8(v); }},
            {"revFeed9", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setRevFeed9(v); }},
            {"revFeed10", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setRevFeed10(v); }},
            {"pitch1", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setPitch1(v); }},
            {"pitch2", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setPitch2(v); }},
            {"pitch3", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setPitch3(v); }},
            {"pitch4", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setPitch4(v); }},
            {"pitch5", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setPitch5(v); }},
            {"pitch6", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setPitch6(v); }},
            {"pitch7", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setPitch7(v); }},
            {"pitch8", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setPitch8(v); }},
            {"pitch9", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setPitch9(v); }},
            {"pitch10", [](const AudioPluginAudioProcessor& p, const float v) { p.pluginRunner->setPitch10(v); }},

        };
        if (auto it = parameterMap.find(parameterID); it != parameterMap.end())
        {
            it->second(*this, newValue);
        }
    }

    void computeCpuLoad(std::chrono::nanoseconds elapsed, size_t numSamples)
    {
        samplesProcessed += numSamples;
        elapsedTotalNanoSeconds += static_cast<size_t>(elapsed.count());
        constexpr float secondsPoll = 0.5f;
        if (samplesProcessed > m_sampleRate * secondsPoll)
        {
            const auto pRate = static_cast<float>(100.0 * static_cast<double>(elapsedTotalNanoSeconds) /
                                                  (secondsPoll * 1'000'000'000.0));
            m_runningWindowCpu += static_cast<size_t>(pRate * 100.f);
            m_runningWindowCpu -= m_avgCpu[m_head];
            m_avgCpu[m_head++] = static_cast<size_t>(pRate * 100.f);
            m_head = m_head % m_avgCpu.size();
            m_cpuLoad.store(m_runningWindowCpu * 0.01f / m_avgCpu.size());
            elapsedTotalNanoSeconds = 0;
            samplesProcessed = 0;
        }
    }


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"

    void processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) override
    {
        juce::ScopedNoDenormals noDenormals;
        const auto beginTime = std::chrono::high_resolution_clock::now();

        if (!midiMessages.isEmpty())
        {
            for (const auto& msg : midiMessages)
            {
                pluginRunner->processMidi(msg.data);
            }
        }
        for (int c = 0; c < std::min(2, buffer.getNumChannels()); ++c)
        {
            m_envInput[c].feed(buffer.getReadPointer(c), buffer.getNumSamples());
            m_inputDb[c].store(std::log10(m_envInput[c].getRms()) * 20.f);
        }
        if ((getTotalNumInputChannels() == 2) && (getTotalNumOutputChannels() == 2))
        {
            fixedRunner.processBlock(buffer);
        }
        for (int c = 0; c < std::min(2, buffer.getNumChannels()); ++c)
        {
            m_envOutput[c].feed(buffer.getReadPointer(c), buffer.getNumSamples());
            m_outputDb[c].store(std::log10(m_envOutput[c].getRms()) * 20.f);
        }
        m_spectrogram.processBlock(buffer.getWritePointer(0), buffer.getNumSamples());
        const auto endTime = std::chrono::high_resolution_clock::now();
        computeCpuLoad(std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - beginTime),
                       static_cast<size_t>(buffer.getNumSamples()));
    }

#pragma GCC diagnostic pop

    [[nodiscard]] float getCpuLoad() const
    {
        return m_cpuLoad.load();
    }

    [[nodiscard]] std::pair<float, float> getInputDbLoad() const
    {
        return {m_inputDb[0].load(), m_inputDb[1].load()};
    }

    [[nodiscard]] std::pair<float, float> getOutputDbLoad() const
    {
        return {m_outputDb[0].load(), m_outputDb[1].load()};
    }
    [[nodiscard]] AbacDsp::SpectrumImageSet getSpectrogram() const
    {
        return m_spectrogram.getImageSet();
    }

    float m_maxValue{0.f};
    size_t elapsedTotalNanoSeconds{0};
    size_t samplesProcessed = 0;

  private:
    size_t m_sampleRate{48000};

    static bool isChanged(const float a, const float b)
    {
        return std::abs(a - b) > 1E-8f;
    }

    int m_program{0};
    juce::ValueTree m_newState;

    AbacDsp::FixedSizeProcessor<2, NumSamplesPerBlock, juce::AudioBuffer<float>> fixedRunner;
    std::unique_ptr<SamplePlayer<NumSamplesPerBlock>> pluginRunner;
    juce::AudioProcessorValueTreeState m_parameters;
    // CPU-Load
    std::atomic<float> m_cpuLoad;
    std::vector<size_t> m_avgCpu;
    size_t m_head{};
    size_t m_runningWindowCpu;
    // VU-Meter
    std::atomic<float> m_inputDb[2];
    std::atomic<float> m_outputDb[2];
    std::array<AbacDsp::RmsFollower, 2> m_envInput;
    std::array<AbacDsp::RmsFollower, 2> m_envOutput;
    AbacDsp::SimpleSpectrogram m_spectrogram;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioPluginAudioProcessor)
};
