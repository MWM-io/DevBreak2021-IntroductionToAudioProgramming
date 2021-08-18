/*
  ==============================================================================

    MainScreen.h
    Created: 1 Sep 2021 2:05:17pm
    Author:  Mathis Raibaud

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <functional>

//==============================================================================
/*
*/
class MainScreen : public juce::Component
{
public:
    MainScreen();
    ~MainScreen() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    std::function<void()> onPlayButtonClicked;
    std::function<void()> onStopButtonClicked;
    std::function<void(const juce::File&)> onAudioFileChoosed;
    
    void setPlayButtonEnabled(bool enabled);
    void setStopButtonEnabled(bool enabled);
    
    std::function<void(float)> onFrequencySliderChanged;
    std::function<void(float)> onGainSliderChanged;

private:
#if (!(JUCE_ANDROID || JUCE_IOS))
    void openButtonClicked();
#endif
    
#if (!(JUCE_ANDROID || JUCE_IOS))
    juce::TextButton openButton_;
#endif
    juce::TextButton playButton_;
    juce::TextButton stopButton_;
    
    juce::Slider frequencySlider_;
    juce::Label frequencyLabel_;
    
    juce::Slider gainSlider_;
    juce::Label gainLabel_;
    
    juce::OpenGLContext openGLContext_;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainScreen)
};
