This project is serving as a learning tool which I am using to learn C++ as well as the JUCE framework for audio DSP processing.

Project Purpose/Goal: This plugin/application will take inputs from a user (as specified below), and by using the midi data, it will create a duplicate audio signal as the inputted signal and transpose it to a new pitch and pan / change the volume of the signal, and output it alongside the original signal, creating a harmonized signal with the original signal.

Project Outline:
Inputs:
 - Audio Signal
 - MIDI Data
 - Volume and Pan Controls for each audio signal (From Plugin UI)

Outputs:
 - AUDIO: The original audio signal (panned and volume corrected to user inputs)
 - AUDIO: 1-4 New Audio Signals created from pitch shifting the original audio signal according to the midi data (panned and volume corrected to user inputs)
 - VISUAL: Audio Level Meter of each audio output

*This repository only contains the shared code for a JUCE Standalone/VST3 Plugin*
*In order to be run, the JUCE library must also be installed*
