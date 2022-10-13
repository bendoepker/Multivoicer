/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MultivoicerAudioProcessorEditor::MultivoicerAudioProcessorEditor (MultivoicerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 400);

    //MASTER VOICE VOLUME SLIDER ATTRIBUTES
    masterVoiceVolumeSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    masterVoiceVolumeSlider.setRange(0.0, 100.0, 1.0);
    masterVoiceVolumeSlider.setValue(100.0);
    masterVoiceVolumeSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);

    //MASTER VOICE PAN SLIDER ATTRIBUTES
    masterVoicePanSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    masterVoicePanSlider.setRange(0.0, 100.0, 1.0);
    masterVoicePanSlider.setValue(50.0);
    masterVoicePanSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);

    //VOICE ONE VOLUME SLIDER ATTRIBUTES
    voiceOneVolumeSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    voiceOneVolumeSlider.setRange(0.0, 100.0, 1.0);
    voiceOneVolumeSlider.setValue(50.0);
    voiceOneVolumeSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);

    //VOICE ONE PAN SLIDER ATTRIBUTES
    voiceOnePanSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    voiceOnePanSlider.setRange(0.0, 100.0, 1.0);
    voiceOnePanSlider.setValue(50.0);
    voiceOnePanSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);

    //VOICE TWO VOLUME SLIDER ATTRIBUTES
    voiceTwoVolumeSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    voiceTwoVolumeSlider.setRange(0.0, 100.0, 1.0);
    voiceTwoVolumeSlider.setValue(75.0);
    voiceTwoVolumeSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);

    //VOICE TWO PAN SLIDER ATTRIBUTES
    voiceTwoPanSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    voiceTwoPanSlider.setRange(0.0, 100.0, 1.0);
    voiceTwoPanSlider.setValue(50.0);
    voiceTwoPanSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);

    //VOICE THREE VOLUME SLIDER ATTRIBUTES
    voiceThreeVolumeSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    voiceThreeVolumeSlider.setRange(0.0, 100.0, 1.0);
    voiceThreeVolumeSlider.setValue(75.0);
    voiceThreeVolumeSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);

    //VOICE THREE PAN SLIDER ATTRIBUTES
    voiceThreePanSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    voiceThreePanSlider.setRange(0.0, 100.0, 1.0);
    voiceThreePanSlider.setValue(50.0);
    voiceThreePanSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);

    //VOICE FOUR VOLUME SLIDER ATTRIBUTES
    voiceFourVolumeSlider.setSliderStyle(juce::Slider::LinearBarVertical);
    voiceFourVolumeSlider.setRange(0.0, 100.0, 1.0);
    voiceFourVolumeSlider.setValue(50.0);
    voiceFourVolumeSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);

    //VOICE FOUR PAN SLIDER ATTRIBUTES
    voiceFourPanSlider.setSliderStyle(juce::Slider::RotaryVerticalDrag);
    voiceFourPanSlider.setRange(0.0, 100.0, 1.0);
    voiceFourPanSlider.setValue(50.0);
    voiceFourPanSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);

    //ADDING CHILD COMPONENTS TO PARENT WINDOW
    addAndMakeVisible(&masterVoiceVolumeSlider);
    addAndMakeVisible(&masterVoicePanSlider);
    addAndMakeVisible(&voiceOneVolumeSlider);
    addAndMakeVisible(&voiceOnePanSlider);
    addAndMakeVisible(&voiceTwoVolumeSlider);
    addAndMakeVisible(&voiceTwoPanSlider);
    addAndMakeVisible(&voiceThreeVolumeSlider);
    addAndMakeVisible(&voiceThreePanSlider);
    addAndMakeVisible(&voiceFourVolumeSlider);
    addAndMakeVisible(&voiceFourPanSlider);
    addAndMakeVisible(&masterVolumeLevelLabel);

    masterVoiceVolumeSlider.addListener(this);
}

MultivoicerAudioProcessorEditor::~MultivoicerAudioProcessorEditor()
{
}

//==============================================================================
void MultivoicerAudioProcessorEditor::paint (juce::Graphics& g)
{
    //BACKGROUND
    g.fillAll (juce::Colours::darkgrey);

    //?VOICE TEXT
    g.setColour (juce::Colours::black);
    g.drawFittedText("Voice 1", 75, 140, 50, 20, juce::Justification::centred, 1);
    g.drawFittedText("Voice 2", 175, 140, 50, 20, juce::Justification::centred, 1);
    g.drawFittedText("Master Voice", 250, 140, 100, 20, juce::Justification::centred, 1);
    g.drawFittedText("Voice 3", 375, 140, 50, 20, juce::Justification::centred, 1);
    g.drawFittedText("Voice 4", 475, 140, 50, 20, juce::Justification::centred, 1);

}

void MultivoicerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    //VOLUME SLIDER PLACEMENTS
    voiceOneVolumeSlider.setBounds(90, 180, 20, 100);
    voiceTwoVolumeSlider.setBounds(190, 180, 20, 100);
    masterVoiceVolumeSlider.setBounds(290, 180, 20, 100);
    voiceThreeVolumeSlider.setBounds(390, 180, 20, 100);
    voiceFourVolumeSlider.setBounds(490, 180, 20, 100);

    //PAN SLIDER PLACEMENTS
    voiceOnePanSlider.setBounds(75, 300, 50, 50);
    voiceTwoPanSlider.setBounds(175, 300, 50, 50);
    masterVoicePanSlider.setBounds(275, 300, 50, 50);
    voiceThreePanSlider.setBounds(375, 300, 50, 50);
    voiceFourPanSlider.setBounds(475, 300, 50, 50);

    masterVolumeLevelLabel.setBounds(0, 0, 100, 100);
}
