#pragma once
/*
 * AUTO GENERATED,
 * NOT A GOOD IDEA TO CHANGE STUFF HERE
 * Keep the file readonly
 */

#include "DelayProcessor.h"

#include "UiElements.h"

//==============================================================================
class AudioPluginAudioProcessorEditor : public juce::AudioProcessorEditor, juce::Timer
{
  public:
    explicit AudioPluginAudioProcessorEditor(AudioPluginAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
        : AudioProcessorEditor(&p)
        , processorRef(p)
        , valueTreeState(vts)
        , backgroundApp(juce::Colour(Constants::Colors::bg_App))
    {
        setLookAndFeel(&m_laf);
        initWidgets();
        setResizable(true, true);
        setResizeLimits(Constants::InitJuce::WindowWidth, Constants::InitJuce::WindowHeight, 4000, 3000);
        setSize(Constants::InitJuce::WindowWidth, Constants::InitJuce::WindowHeight);
        startTimerHz(Constants::InitJuce::TimerHertz);
    }

    ~AudioPluginAudioProcessorEditor() override
    {
        setLookAndFeel(nullptr);
    }

    void paint(juce::Graphics& g) override
    {
        g.fillAll(backgroundApp);
    }
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-conversion"
    void resized() override
    {
        auto area = getLocalBounds().reduced(static_cast<int>(Constants::Margins::big));

        // auto generated
        // const juce::FlexItem::Margin knobMargin = juce::FlexItem::Margin(Constants::Margins::small);
        const juce::FlexItem::Margin knobMarginSmall = juce::FlexItem::Margin(Constants::Margins::medium);
        std::vector<juce::Rectangle<int>> areas(3);
        const auto colWidth = area.getWidth() / 15;
        areas[0] = area.removeFromLeft(colWidth * 1).reduced(Constants::Margins::small);
        areas[1] = area.removeFromLeft(colWidth * 1).reduced(Constants::Margins::small);
        areas[2] = area.reduced(Constants::Margins::small);

        {
            juce::FlexBox box;
            box.flexWrap = juce::FlexBox::Wrap::noWrap;
            box.flexDirection = juce::FlexBox::Direction::column;
            box.justifyContent = juce::FlexBox::JustifyContent::spaceAround;
            box.items.add(juce::FlexItem(gainDial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(dryDial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(wetDial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(levelGauge).withHeight(100).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(cpuGauge).withHeight(100).withMargin(knobMarginSmall));
            box.performLayout(areas[0].toFloat());
        }
        {
            juce::FlexBox box;
            box.flexWrap = juce::FlexBox::Wrap::noWrap;
            box.flexDirection = juce::FlexBox::Direction::column;
            box.justifyContent = juce::FlexBox::JustifyContent::spaceAround;
            box.items.add(juce::FlexItem(timeInMsDial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(feedbackDial).withFlex(1).withMargin(knobMarginSmall));
            box.performLayout(areas[1].toFloat());
        }
        {
            juce::FlexBox box;
            box.flexWrap = juce::FlexBox::Wrap::noWrap;
            box.flexDirection = juce::FlexBox::Direction::column;
            box.justifyContent = juce::FlexBox::JustifyContent::spaceAround;
            box.items.add(juce::FlexItem(spectrogramGauge).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(signalGauge).withFlex(1).withMargin(knobMarginSmall));
            box.performLayout(areas[2].toFloat());
        }
    }
#pragma GCC diagnostic pop

    void timerCallback() override
    {
        cpuGauge.update(processorRef.getCpuLoad());
        levelGauge.update(processorRef.getInputDbLoad(), processorRef.getOutputDbLoad());
        spectrogramGauge.update(processorRef.getSpectrogram());
        signalGauge.update(processorRef.getWaveDataToShow());
    }

    void initWidgets()
    {
        addAndMakeVisible(gainDial);
        gainDial.reset(valueTreeState, "gain");
        gainDial.setLabelText(juce::String::fromUTF8("Gain"));
        addAndMakeVisible(dryDial);
        dryDial.reset(valueTreeState, "dry");
        dryDial.setLabelText(juce::String::fromUTF8("Dry"));
        addAndMakeVisible(wetDial);
        wetDial.reset(valueTreeState, "wet");
        wetDial.setLabelText(juce::String::fromUTF8("Wet"));
        addAndMakeVisible(timeInMsDial);
        timeInMsDial.reset(valueTreeState, "timeInMs");
        timeInMsDial.setLabelText(juce::String::fromUTF8("Time"));
        addAndMakeVisible(feedbackDial);
        feedbackDial.reset(valueTreeState, "feedback");
        feedbackDial.setLabelText(juce::String::fromUTF8("Feedback"));
        addAndMakeVisible(cpuGauge);
        cpuGauge.setLabelText(juce::String::fromUTF8("CPU"));
        addAndMakeVisible(levelGauge);
        levelGauge.setLabelText(juce::String::fromUTF8("Level"));
        addAndMakeVisible(spectrogramGauge);
        spectrogramGauge.setLabelText(juce::String::fromUTF8("Spectrogram"));
        addAndMakeVisible(signalGauge);
        signalGauge.setLabelText(juce::String::fromUTF8("Signal"));
    }

  private:
    AudioPluginAudioProcessor& processorRef;
    juce::AudioProcessorValueTreeState& valueTreeState;
    GuiLookAndFeel m_laf;
    juce::Colour backgroundApp;

    CustomRotaryDial gainDial{this};
    CustomRotaryDial dryDial{this};
    CustomRotaryDial wetDial{this};
    CustomRotaryDial timeInMsDial{this};
    CustomRotaryDial feedbackDial{this};
    CpuGauge cpuGauge{};
    Gauge levelGauge{};
    SpectrogramDisplay spectrogramGauge{};
    WaveformGauge signalGauge{};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioPluginAudioProcessorEditor)
};
