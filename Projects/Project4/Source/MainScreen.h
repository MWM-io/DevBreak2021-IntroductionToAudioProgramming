/*
  ==============================================================================

    MainScreen.h
    Created: 1 Sep 2021 6:24:13pm
    Author:  Mathis Raibaud

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../../Commons/DSP/RingModulator/RingModulator.h"
#include "../../Commons/DSP/Gain/SmoothedGain.h"

class MainScreen  : public juce::Component
{
public:
    MainScreen();
    ~MainScreen() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    std::function<void(float)> onFrequencySliderChanged;
    std::function<void(float)> onGainSliderChanged;

private:
    RingModulator ringModulator_;
    juce::Slider frequencySlider_;
    juce::Label frequencyLabel_;
    
    SmoothedGain gain_;
    juce::Slider gainSlider_;
    juce::Label gainLabel_;
        
    juce::OpenGLContext openGLContext;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainScreen)
};
