/*
  ==============================================================================

    AudioEngine.h
    Created: 1 Sep 2021 11:00:04am
    Author:  Mathis Raibaud

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <functional>

//==============================================================================
/*
*/
class MainScreen  : public juce::Component
{
public:
    MainScreen();
    ~MainScreen() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    std::function<void(float)> onFrequencySliderChanged;
    std::function<void(float)> onGainSliderChanged;
    
    float getFrequencySliderValue() const;
    float getGainSliderValue() const;

private:
    juce::Slider frequencySlider_;
    juce::Label frequencyLabel_;
    
    juce::Slider gainSlider_;
    juce::Label gainLabel_;
    
    juce::OpenGLContext openGLContext;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainScreen)
};
