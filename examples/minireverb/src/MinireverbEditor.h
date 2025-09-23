#pragma once
/*
 * AUTO GENERATED,
 * NOT A GOOD IDEA TO CHANGE STUFF HERE
 * Keep the file readonly
 */

#include "MinireverbProcessor.h"

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

        std::vector<juce::Rectangle<int>> areas(5);
        const auto colWidth = area.getWidth() / 13;
        const auto rowHeight = area.getHeight() / 6;
        areas[0] = area.removeFromLeft(colWidth * 1).reduced(Constants::Margins::small);
        auto keepArea = area;
        areas[1] = area.removeFromTop(rowHeight * 2).reduced(Constants::Margins::small);
        areas[2] = area.removeFromTop(rowHeight * 1).reduced(Constants::Margins::small);
        areas[3] = area.removeFromTop(rowHeight * 1).reduced(Constants::Margins::small);
        areas[4] = area.reduced(Constants::Margins::small);

        {
            juce::FlexBox box;
            box.flexWrap = juce::FlexBox::Wrap::noWrap;
            box.flexDirection = juce::FlexBox::Direction::column;
            box.justifyContent = juce::FlexBox::JustifyContent::spaceAround;
            box.items.add(juce::FlexItem(levelGauge).withHeight(500).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(cpuGauge).withHeight(200).withMargin(knobMarginSmall));
            box.performLayout(areas[0].toFloat());
        }
        {
            juce::FlexBox box;
            box.flexWrap = juce::FlexBox::Wrap::noWrap;
            box.flexDirection = juce::FlexBox::Direction::row;
            box.justifyContent = juce::FlexBox::JustifyContent::spaceAround;
            box.items.add(juce::FlexItem(decayDial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(spectrogramGauge).withWidth(600).withMargin(knobMarginSmall));
            box.performLayout(areas[1].toFloat());
        }
        {
            juce::FlexBox box;
            box.flexWrap = juce::FlexBox::Wrap::noWrap;
            box.flexDirection = juce::FlexBox::Direction::row;
            box.justifyContent = juce::FlexBox::JustifyContent::spaceAround;
            box.items.add(juce::FlexItem(lowSizeDial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(highSizeDial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(uniqueDelaySwitch)
                              .withWidth(Constants::Text::labelWidth)
                              .withHeight(Constants::Text::labelHeight)
                              .withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(bulgeDial).withFlex(1).withMargin(knobMarginSmall));
            box.performLayout(areas[2].toFloat());
        }
        {
            juce::FlexBox box;
            box.flexWrap = juce::FlexBox::Wrap::noWrap;
            box.flexDirection = juce::FlexBox::Direction::row;
            box.justifyContent = juce::FlexBox::JustifyContent::spaceAround;
            box.items.add(juce::FlexItem(allPassUpDial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(allPassDownDial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(allPassCountDrop)
                              .withWidth(Constants::Text::labelWidth)
                              .withHeight(Constants::Text::labelHeight)
                              .withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(lowPassDial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(highPassDial).withFlex(1).withMargin(knobMarginSmall));
            box.performLayout(areas[3].toFloat());
        }
        {
            juce::FlexBox box;
            box.flexWrap = juce::FlexBox::Wrap::noWrap;
            box.flexDirection = juce::FlexBox::Direction::row;
            box.justifyContent = juce::FlexBox::JustifyContent::spaceAround;
            box.items.add(juce::FlexItem(orderDrop)
                              .withWidth(Constants::Text::labelWidth)
                              .withHeight(Constants::Text::labelHeight)
                              .withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(dryDial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(wetDial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(modulationDepthDial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(modulationSpeedDial).withFlex(1).withMargin(knobMarginSmall));
            box.items.add(juce::FlexItem(modulationCountDrop)
                              .withWidth(Constants::Text::labelWidth)
                              .withHeight(Constants::Text::labelHeight)
                              .withMargin(knobMarginSmall));
            box.performLayout(areas[4].toFloat());
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
        addAndMakeVisible(orderDrop);
        orderDrop.addItemList(valueTreeState.getParameter("order")->getAllValueStrings(), 1);
        orderDropAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(
            valueTreeState, "order", orderDrop);
        addAndMakeVisible(dryDial);
        dryDial.reset(valueTreeState, "dry");
        dryDial.setLabelText(juce::String::fromUTF8("Dry"));
        addAndMakeVisible(wetDial);
        wetDial.reset(valueTreeState, "wet");
        wetDial.setLabelText(juce::String::fromUTF8("Wet"));
        addAndMakeVisible(lowSizeDial);
        lowSizeDial.reset(valueTreeState, "lowSize");
        lowSizeDial.setLabelText(juce::String::fromUTF8("1st size"));
        addAndMakeVisible(highSizeDial);
        highSizeDial.reset(valueTreeState, "highSize");
        highSizeDial.setLabelText(juce::String::fromUTF8("Last size"));
        addAndMakeVisible(uniqueDelaySwitch);
        uniqueDelaySwitchAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(
            valueTreeState, "uniqueDelay", uniqueDelaySwitch);

        addAndMakeVisible(bulgeDial);
        bulgeDial.reset(valueTreeState, "bulge");
        bulgeDial.setLabelText(juce::String::fromUTF8("Bulge"));
        addAndMakeVisible(decayDial);
        decayDial.reset(valueTreeState, "decay");
        decayDial.setLabelText(juce::String::fromUTF8("Decay"));
        addAndMakeVisible(div1Label);
        div1Label.setText(juce::String::fromUTF8("Dispersion"), juce::dontSendNotification);
        addAndMakeVisible(allPassUpDial);
        allPassUpDial.reset(valueTreeState, "allPassUp");
        allPassUpDial.setLabelText(juce::String::fromUTF8("All pass 1st"));
        addAndMakeVisible(allPassDownDial);
        allPassDownDial.reset(valueTreeState, "allPassDown");
        allPassDownDial.setLabelText(juce::String::fromUTF8("All pass last"));
        addAndMakeVisible(allPassCountDrop);
        allPassCountDrop.addItemList(valueTreeState.getParameter("allPassCount")->getAllValueStrings(), 1);
        allPassCountDropAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(
            valueTreeState, "allPassCount", allPassCountDrop);
        addAndMakeVisible(div2Label);
        div2Label.setText(juce::String::fromUTF8("Filters"), juce::dontSendNotification);
        addAndMakeVisible(lowPassDial);
        lowPassDial.reset(valueTreeState, "lowPass");
        lowPassDial.setLabelText(juce::String::fromUTF8("Low pass"));
        addAndMakeVisible(highPassDial);
        highPassDial.reset(valueTreeState, "highPass");
        highPassDial.setLabelText(juce::String::fromUTF8("High pass"));
        addAndMakeVisible(modulationDepthDial);
        modulationDepthDial.reset(valueTreeState, "modulationDepth");
        modulationDepthDial.setLabelText(juce::String::fromUTF8("Mod depth"));
        addAndMakeVisible(modulationSpeedDial);
        modulationSpeedDial.reset(valueTreeState, "modulationSpeed");
        modulationSpeedDial.setLabelText(juce::String::fromUTF8("Mod speed"));
        addAndMakeVisible(modulationCountDrop);
        modulationCountDrop.addItemList(valueTreeState.getParameter("modulationCount")->getAllValueStrings(), 1);
        modulationCountDropAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(
            valueTreeState, "modulationCount", modulationCountDrop);
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

    juce::ComboBox orderDrop{};
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> orderDropAttachment;
    CustomRotaryDial dryDial{this};
    CustomRotaryDial wetDial{this};
    CustomRotaryDial lowSizeDial{this};
    CustomRotaryDial highSizeDial{this};
    juce::ToggleButton uniqueDelaySwitch{juce::String::fromUTF8("Unique delay")};
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> uniqueDelaySwitchAttachment;
    CustomRotaryDial bulgeDial{this};
    CustomRotaryDial decayDial{this};
    juce::Label div1Label{};
    CustomRotaryDial allPassUpDial{this};
    CustomRotaryDial allPassDownDial{this};
    juce::ComboBox allPassCountDrop{};
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> allPassCountDropAttachment;
    juce::Label div2Label{};
    CustomRotaryDial lowPassDial{this};
    CustomRotaryDial highPassDial{this};
    CustomRotaryDial modulationDepthDial{this};
    CustomRotaryDial modulationSpeedDial{this};
    juce::ComboBox modulationCountDrop{};
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> modulationCountDropAttachment;
    CpuGauge cpuGauge{};
    Gauge levelGauge{};
    SpectrogramDisplay spectrogramGauge{};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioPluginAudioProcessorEditor)
};
