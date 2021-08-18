/*
 ==============================================================================
 
 MainScreen.h
 Created: 31 Aug 2021 11:44:50am
 Author:  Thomas Hézard
 
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
    
    float getFrequencySliderValue() const;
    std::function<void(float)> onFrequencySliderChanged;
    
private:
    juce::Slider frequencySlider_;
    juce::Label frequencyLabel_;
    
    juce::OpenGLContext openGLContext;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainScreen)
};
