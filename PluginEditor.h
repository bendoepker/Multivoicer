/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*
*/
class MultivoicerAudioProcessorEditor : public juce::AudioProcessorEditor,
                                               juce::Slider::Listener
{
public:
    MultivoicerAudioProcessorEditor (MultivoicerAudioProcessor&);
    ~MultivoicerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void sliderValueChanged(juce::Slider* slider) override //ACTIVATING THE SLIDER LISTENER CALLBACK FUNCTIONS SO THAT VALUES ARE OUTPUTTED TO THEIR VARIABLES
    {
        //VOLUME SLIDERS TO VARIABLES
        if (slider == &masterVoiceVolumeSlider) masterVoiceVolumeLevel = masterVoiceVolumeSlider.getValue();
        else if (slider == &voiceOneVolumeSlider) voiceOneVolumeLevel = voiceOneVolumeSlider.getValue();
        else if (slider == &voiceTwoVolumeSlider) voiceTwoVolumeLevel = voiceTwoVolumeSlider.getValue();
        else if (slider == &voiceThreeVolumeSlider) voiceThreeVolumeLevel = voiceThreeVolumeSlider.getValue();
        else if (slider == &voiceFourVolumeSlider) voiceFourVolumeLevel = voiceFourVolumeSlider.getValue();

        //PAN SLIDERS TO VARIABLES
        else if (slider == &masterVoicePanSlider) masterVoicePanLevel = masterVoicePanSlider.getValue();
        else if (slider == &voiceOnePanSlider) voiceOnePanLevel = voiceOnePanSlider.getValue();
        else if (slider == &voiceTwoPanSlider) voiceTwoPanLevel = voiceTwoPanSlider.getValue();
        else if (slider == &voiceThreePanSlider) voiceThreePanLevel = voiceThreePanSlider.getValue();
        else if (slider == &voiceFourPanSlider) voiceFourPanLevel = voiceFourPanSlider.getValue();
    }

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MultivoicerAudioProcessor& audioProcessor;
    //void sliderValueChanged(juce::Slider slider) override;

    //VOLUME SLIDER OBJECTS
    juce::Slider masterVoiceVolumeSlider;
    juce::Slider voiceOneVolumeSlider;
    juce::Slider voiceTwoVolumeSlider;
    juce::Slider voiceThreeVolumeSlider;
    juce::Slider voiceFourVolumeSlider;

    //VOLUME VALUE VARIABLES
    double masterVolumeLevel;
    double masterVoiceVolumeLevel;
    double voiceOneVolumeLevel;
    double voiceTwoVolumeLevel;
    double voiceThreeVolumeLevel;
    double voiceFourVolumeLevel;

    //PAN SLIDER OBJECTS
    juce::Slider masterVoicePanSlider;
    juce::Slider voiceOnePanSlider;
    juce::Slider voiceTwoPanSlider;
    juce::Slider voiceThreePanSlider;
    juce::Slider voiceFourPanSlider;

    //PAN VALUE VARIABLES
    double masterVoicePanLevel;
    double voiceOnePanLevel;
    double voiceTwoPanLevel;
    double voiceThreePanLevel;
    double voiceFourPanLevel;

    //TEMPORARY LABEL COMPONENTS
    juce::Label masterVolumeLevelLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MultivoicerAudioProcessorEditor)
};
