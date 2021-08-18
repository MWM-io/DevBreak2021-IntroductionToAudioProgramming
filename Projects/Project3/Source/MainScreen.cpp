/*
  ==============================================================================

    MainScreen.cpp
    Created: 1 Sep 2021 2:05:17pm
    Author:  Mathis Raibaud

  ==============================================================================
*/

#include "MainScreen.h"

MainScreen::MainScreen()
{
    openGLContext_.attachTo (*getTopLevelComponent());
    
#if (!(JUCE_ANDROID || JUCE_IOS))
    addAndMakeVisible (&openButton_);
    openButton_.setButtonText ("Open...");
    openButton_.onClick = [this] { openButtonClicked(); };
#endif

    addAndMakeVisible (&playButton_);
    playButton_.setButtonText ("Play");
    playButton_.onClick = [this] { 
        playButton_.setEnabled(false);
        stopButton_.setEnabled(true);
        if (onPlayButtonClicked != nullptr) 
            onPlayButtonClicked(); 
    };
    playButton_.setColour (juce::TextButton::buttonColourId, juce::Colours::green);
#if (JUCE_ANDROID || JUCE_IOS)
    playButton_.setEnabled (true);
#else
    playButton_.setEnabled (false);
#endif

    addAndMakeVisible (&stopButton_);
    stopButton_.setButtonText ("Stop");
    stopButton_.onClick = [this] { 
        playButton_.setEnabled(true);
        stopButton_.setEnabled(false);
        if (onStopButtonClicked != nullptr) 
            onStopButtonClicked();
    };
    stopButton_.setColour (juce::TextButton::buttonColourId, juce::Colours::red);
    stopButton_.setEnabled (false);
    
    addAndMakeVisible(&frequencySlider_);
    frequencySlider_.setRange({1, 1000}, 0.001);
    frequencySlider_.setSkewFactorFromMidPoint(20);
    frequencySlider_.setValue(4.5);
    frequencySlider_.onValueChange = [&]() {  
        if (onFrequencySliderChanged != nullptr)
            onFrequencySliderChanged(frequencySlider_.getValue());
    };
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
    gainSlider_.setValue(75);
    gainSlider_.onValueChange = [&]() { 
        if (onGainSliderChanged != nullptr)
            onGainSliderChanged(gainSlider_.getValue()/100);
    };
    gainSlider_.setTextValueSuffix(" %");
    gainSlider_.setColour(juce::Slider::ColourIds::thumbColourId, juce::Colours::white);
    gainSlider_.setColour(juce::Slider::ColourIds::rotarySliderOutlineColourId, juce::Colour(69, 69, 69));
    gainSlider_.setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colour(232, 232, 232));
    gainSlider_.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    
    addAndMakeVisible(&gainLabel_);
    gainLabel_.setText("Gain", juce::dontSendNotification);
    gainLabel_.setJustificationType(juce::Justification::centred);
    gainLabel_.attachToComponent(&gainSlider_, false);
    
    setSize (700, 300);
}

MainScreen::~MainScreen()
{
    openGLContext_.detach();
}

void MainScreen::paint(juce::Graphics& g)
{
    g.fillAll (juce::Colour(21, 28, 31));
}

void MainScreen::resized()
{
#if (!(JUCE_ANDROID || JUCE_IOS))
    openButton_.setBounds(0, 0, getWidth()/3, getHeight()/10);
    playButton_.setBounds(getWidth()/3, 0, getWidth()/3, getHeight()/10);
    stopButton_.setBounds(2*getWidth()/3, 0, getWidth()/3, getHeight()/10);
#else
    playButton_.setBounds(0, 0, getWidth()/2, getHeight()/10);
    stopButton_.setBounds(getWidth()/2, 0, getWidth()/2, getHeight()/10);
#endif

    frequencySlider_.setSize(getWidth()/2, getHeight()/2);
    frequencySlider_.setCentrePosition(getWidth()/4, getHeight()/2);
    frequencySlider_.setTextBoxStyle(juce::Slider::TextBoxBelow, true, frequencySlider_.getWidth()/4, frequencySlider_.getHeight()/8);

    gainSlider_.setSize(getWidth()/2, getHeight()/2);
    gainSlider_.setCentrePosition(3*getWidth()/4, getHeight()/2);
    gainSlider_.setTextBoxStyle(juce::Slider::TextBoxBelow, true, gainSlider_.getWidth()/4, frequencySlider_.getHeight()/8);
}

void MainScreen::setPlayButtonEnabled(bool enabled)
{
    playButton_.setEnabled(enabled);
}

void MainScreen::setStopButtonEnabled(bool enabled)
{
    stopButton_.setEnabled(enabled);
}

#if (!(JUCE_ANDROID || JUCE_IOS))
void MainScreen::openButtonClicked()
{
    juce::FileChooser chooser ("Select a Wave file to play...",
                               {},
                               "*.mp3;*.wav");

    if (chooser.browseForFileToOpen())
    {
        auto file = chooser.getResult();
        if (onAudioFileChoosed != nullptr)
            onAudioFileChoosed(file);
    }
}
#endif
