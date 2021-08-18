/*
 ==============================================================================
 
 MainScreen.cpp
 Created: 31 Aug 2021 11:44:50am
 Author:  Thomas Hézard
 
 ==============================================================================
 */

#include <JuceHeader.h>
#include "MainScreen.h"

//==============================================================================
MainScreen::MainScreen() : 
onFrequencySliderChanged(nullptr), 
frequencySlider_(), 
frequencyLabel_(), 
openGLContext()
{
    openGLContext.attachTo (*getTopLevelComponent());
    
    addAndMakeVisible(&frequencySlider_);
    frequencySlider_.setRange({100, 1500}, 0.1);
    frequencySlider_.setValue(220);
    frequencySlider_.setSkewFactorFromMidPoint(300);
    frequencySlider_.setTextValueSuffix(" Hz");
    frequencySlider_.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    frequencySlider_.setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::white);
    frequencySlider_.setColour(juce::Slider::ColourIds::rotarySliderOutlineColourId, juce::Colour(69, 69, 69));
    frequencySlider_.setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colour(232, 232, 232));
    frequencySlider_.onValueChange = [&]() {
        if (onFrequencySliderChanged != nullptr)
            onFrequencySliderChanged(frequencySlider_.getValue());
    };
    
    addAndMakeVisible(&frequencyLabel_);
    frequencyLabel_.setText("Frequency", juce::dontSendNotification);
    frequencyLabel_.setJustificationType(juce::Justification::centred);
    frequencyLabel_.attachToComponent(&frequencySlider_, false);
    
    setSize (700, 300);
}

MainScreen::~MainScreen()
{
    openGLContext.detach();
}

void MainScreen::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(21, 28, 31));
}

void MainScreen::resized()
{
    frequencySlider_.setSize(getWidth()/2, getHeight()/2);
    frequencySlider_.setCentrePosition(getWidth()/2, getHeight()/2);
    frequencySlider_.setTextBoxStyle(juce::Slider::TextBoxBelow, true, frequencySlider_.getWidth()/4, frequencySlider_.getHeight()/8);
}

float MainScreen::getFrequencySliderValue() const
{
    return frequencySlider_.getValue();
}
