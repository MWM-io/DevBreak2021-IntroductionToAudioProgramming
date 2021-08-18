/*
  ==============================================================================

    MainScreen.cpp
    Created: 1 Sep 2021 10:59:47am
    Author:  Mathis Raibaud

  ==============================================================================
*/

#include "MainScreen.h"

MainScreen::MainScreen() 
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
        
    addAndMakeVisible(&gainSlider_);
    gainSlider_.setRange({0, 100}, 0.1);
    gainSlider_.setValue(75);
    gainSlider_.setTextValueSuffix(" %");
    gainSlider_.setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::white);
    gainSlider_.setColour(juce::Slider::ColourIds::rotarySliderOutlineColourId, juce::Colour(69, 69, 69));
    gainSlider_.setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colour(232, 232, 232));
    gainSlider_.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    gainSlider_.onValueChange = [&]() {
        if (onGainSliderChanged != nullptr)
            onGainSliderChanged(gainSlider_.getValue()/100.0f);
    };
    
    addAndMakeVisible(&gainLabel_);
    gainLabel_.setText("Gain", juce::dontSendNotification);
    gainLabel_.setJustificationType(juce::Justification::centred);
    gainLabel_.attachToComponent(&gainSlider_, false);

}

MainScreen::~MainScreen()
{
    openGLContext.detach();
}

float MainScreen::getFrequencySliderValue() const {
    
    return frequencySlider_.getValue();
}

float MainScreen::getGainSliderValue() const {
    
    return gainSlider_.getValue()/100.0f;
}

void MainScreen::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(21, 28, 31));
}

void MainScreen::resized()
{
    frequencySlider_.setSize(getWidth()/2, getHeight()/2);
    frequencySlider_.setCentrePosition(getWidth()/4, getHeight()/2);
    frequencySlider_.setTextBoxStyle(juce::Slider::TextBoxBelow, true, frequencySlider_.getWidth()/4, frequencySlider_.getHeight()/8);
    
    gainSlider_.setSize(getWidth()/2, getHeight()/2);
    gainSlider_.setCentrePosition(3*getWidth()/4, getHeight()/2);
    gainSlider_.setTextBoxStyle(juce::Slider::TextBoxBelow, true, gainSlider_.getWidth()/4, frequencySlider_.getHeight()/8);
}
