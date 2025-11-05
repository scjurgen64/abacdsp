#pragma once
/*
 * AUTO GENERATED,
 * NOT A GOOD IDEA TO CHANGE STUFF HERE
 * Keep the file readonly
 */

#include "SamplePlayerProcessor.h"

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
        const auto colWidth = area.getWidth() / 10;
        const auto rowHeight = area.getHeight() / 3;
        areas[0] = area.removeFromLeft(colWidth * 1).reduced(Constants::Margins::small);
        auto keepArea = area;
        areas[1] = area.removeFromTop(rowHeight * 1).reduced(Constants::Margins::small);
        areas[2] = area.reduced(Constants::Margins::small);

        {
            juce::FlexBox box;
            box.flexWrap = juce::FlexBox::Wrap::noWrap;
            box.flexDirection = juce::FlexBox::Direction::column;
            box.justifyContent = juce::FlexBox::JustifyContent::spaceAround;
            box.items.add(juce::FlexItem(volDial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(reverbLevelDial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(levelGauge).withHeight(100).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(cpuGauge).withHeight(100).withMargin(knobMarginSmall));
            box.performLayout(areas[0].toFloat());
        }
        {
            juce::FlexBox box;
            box.flexWrap = juce::FlexBox::Wrap::noWrap;
            box.flexDirection = juce::FlexBox::Direction::row;
            box.justifyContent = juce::FlexBox::JustifyContent::spaceAround;
            box.items.add(juce::FlexItem(vol1Dial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(vol2Dial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(vol3Dial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(vol4Dial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(vol5Dial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(vol6Dial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(vol7Dial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(vol8Dial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(vol9Dial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(vol10Dial).withFlex(1).withMargin(knobMarginSmall));
            box.performLayout(areas[1].toFloat());
        }
        {
            juce::FlexBox box;
            box.flexWrap = juce::FlexBox::Wrap::noWrap;
            box.flexDirection = juce::FlexBox::Direction::row;
            box.justifyContent = juce::FlexBox::JustifyContent::spaceAround;
            box.items.add(juce::FlexItem(spectrogramGauge).withFlex(1).withMargin(knobMarginSmall));
            box.performLayout(areas[2].toFloat());
        }
    }
#pragma GCC diagnostic pop

    void timerCallback() override
    {
        cpuGauge.update(processorRef.getCpuLoad());
        levelGauge.update(processorRef.getInputDbLoad(), processorRef.getOutputDbLoad());
        spectrogramGauge.update(processorRef.getSpectrogram());
    }

    void initWidgets()
    {
        addAndMakeVisible(volDial);
        volDial.reset(valueTreeState, "vol");
        volDial.setLabelText(juce::String::fromUTF8("Vol"));
        addAndMakeVisible(reverbLevelDial);
        reverbLevelDial.reset(valueTreeState, "reverbLevel");
        reverbLevelDial.setLabelText(juce::String::fromUTF8("Reverb"));
        addAndMakeVisible(vol1Dial);
        vol1Dial.reset(valueTreeState, "vol1");
        vol1Dial.setLabelText(juce::String::fromUTF8("Vol 1"));
        addAndMakeVisible(vol2Dial);
        vol2Dial.reset(valueTreeState, "vol2");
        vol2Dial.setLabelText(juce::String::fromUTF8("Vol 2"));
        addAndMakeVisible(vol3Dial);
        vol3Dial.reset(valueTreeState, "vol3");
        vol3Dial.setLabelText(juce::String::fromUTF8("Vol 3"));
        addAndMakeVisible(vol4Dial);
        vol4Dial.reset(valueTreeState, "vol4");
        vol4Dial.setLabelText(juce::String::fromUTF8("Vol 4"));
        addAndMakeVisible(vol5Dial);
        vol5Dial.reset(valueTreeState, "vol5");
        vol5Dial.setLabelText(juce::String::fromUTF8("Vol 5"));
        addAndMakeVisible(vol6Dial);
        vol6Dial.reset(valueTreeState, "vol6");
        vol6Dial.setLabelText(juce::String::fromUTF8("Vol 6"));
        addAndMakeVisible(vol7Dial);
        vol7Dial.reset(valueTreeState, "vol7");
        vol7Dial.setLabelText(juce::String::fromUTF8("Vol 7"));
        addAndMakeVisible(vol8Dial);
        vol8Dial.reset(valueTreeState, "vol8");
        vol8Dial.setLabelText(juce::String::fromUTF8("Vol 8"));
        addAndMakeVisible(vol9Dial);
        vol9Dial.reset(valueTreeState, "vol9");
        vol9Dial.setLabelText(juce::String::fromUTF8("Vol 9"));
        addAndMakeVisible(vol10Dial);
        vol10Dial.reset(valueTreeState, "vol10");
        vol10Dial.setLabelText(juce::String::fromUTF8("Vol 10"));
        addAndMakeVisible(cpuGauge);
        cpuGauge.setLabelText(juce::String::fromUTF8("CPU"));
        addAndMakeVisible(levelGauge);
        levelGauge.setLabelText(juce::String::fromUTF8("Level"));
        addAndMakeVisible(spectrogramGauge);
        spectrogramGauge.setLabelText(juce::String::fromUTF8("Spectrogram"));
    }

  private:
    AudioPluginAudioProcessor& processorRef;
    juce::AudioProcessorValueTreeState& valueTreeState;
    GuiLookAndFeel m_laf;
    juce::Colour backgroundApp;

    CustomRotaryDial volDial{this};
    CustomRotaryDial reverbLevelDial{this};
    CustomRotaryDial vol1Dial{this};
    CustomRotaryDial vol2Dial{this};
    CustomRotaryDial vol3Dial{this};
    CustomRotaryDial vol4Dial{this};
    CustomRotaryDial vol5Dial{this};
    CustomRotaryDial vol6Dial{this};
    CustomRotaryDial vol7Dial{this};
    CustomRotaryDial vol8Dial{this};
    CustomRotaryDial vol9Dial{this};
    CustomRotaryDial vol10Dial{this};
    CpuGauge cpuGauge{};
    Gauge levelGauge{};
    SpectrogramDisplay spectrogramGauge{};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioPluginAudioProcessorEditor)
};
