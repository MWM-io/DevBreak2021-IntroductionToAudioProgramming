/*
  ==============================================================================

    MainScreen.cpp
    Created: 1 Sep 2021 6:24:13pm
    Author:  Mathis Raibaud

  ==============================================================================
*/

#include "MainScreen.h"

MainScreen::MainScreen()
{    
    openGLContext.attachTo (*getTopLevelComponent());
    
    addAndMakeVisible(&frequencySlider_);
    frequencySlider_.setRange({1, 1000}, 0.001);
    frequencySlider_.onValueChange = [&]() {
        if (onFrequencySliderChanged != nullptr)
            onFrequencySliderChanged(frequencySlider_.getValue());
    };
    frequencySlider_.setValue(4.5);
    frequencySlider_.setSkewFactorFromMidPoint(20);
    frequencySlider_.setTextValueSuffix(" Hz");
    frequencySlider_.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    frequencySlider_.setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::white);
    frequencySlider_.setColour(juce::Slider::ColourIds::rotarySliderOutlineColourId, juce::Colour(69, 69, 69));
    frequencySlider_.setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colour(232, 232, 232));
    
    addAndMakeVisible(&frequencyLabel_);
    frequencyLabel_.setText("Frequency", juce::dontSendNotification);
    frequencyLabel_.setJustificationType(juce::Justification::centred);
    frequencyLabel_.attachToComponent(&frequencySlider_, false);
        
    addAndMakeVisible(&gainSlider_);
    gainSlider_.setRange({0, 100}, 0.1);
    gainSlider_.onValueChange = [&]() {
        if (onGainSliderChanged != nullptr)
            onGainSliderChanged(gainSlider_.getValue()/100);
    };
    gainSlider_.setValue(0);
    gainSlider_.setTextValueSuffix(" %");
    gainSlider_.setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::white);
    gainSlider_.setColour(juce::Slider::ColourIds::rotarySliderOutlineColourId, juce::Colour(69, 69, 69));
    gainSlider_.setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colour(232, 232, 232));
    gainSlider_.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    
    addAndMakeVisible(&gainLabel_);
    gainLabel_.setText("Gain", juce::dontSendNotification);
    gainLabel_.setJustificationType(juce::Justification::centred);
    gainLabel_.attachToComponent(&gainSlider_, false);

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
    frequencySlider_.setCentrePosition(getWidth()/4, getHeight()/2);
    frequencySlider_.setTextBoxStyle(juce::Slider::TextBoxBelow, true, frequencySlider_.getWidth()/4, frequencySlider_.getHeight()/8);
    
    gainSlider_.setSize(getWidth()/2, getHeight()/2);
    gainSlider_.setCentrePosition(3*getWidth()/4, getHeight()/2);
    gainSlider_.setTextBoxStyle(juce::Slider::TextBoxBelow, true, gainSlider_.getWidth()/4, gainSlider_.getHeight()/8);
}
