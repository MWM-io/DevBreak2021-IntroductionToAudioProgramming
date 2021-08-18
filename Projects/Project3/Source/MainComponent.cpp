#include "MainComponent.h"


//==============================================================================
MainComponent::MainComponent()
{

    addAndMakeVisible(&mainScreen_);
    
    mainScreen_.onAudioFileChoosed = [&](const juce::File& file) {
        audioEngine_.Load(file);
        mainScreen_.setPlayButtonEnabled(true);
    };
    
    mainScreen_.onPlayButtonClicked = [&]() {
        audioEngine_.Play();
    };
    
    mainScreen_.onStopButtonClicked = [&]() {
        audioEngine_.Stop();
    };
    
    mainScreen_.onFrequencySliderChanged = [&](float frequency) {
        audioEngine_.setRingModulatorFrequency(frequency);
    };
    
    mainScreen_.onGainSliderChanged = [&](float gain) {
        audioEngine_.setGain(gain);
    };
    
    audioEngine_.didPlay = [&] {
        mainScreen_.setPlayButtonEnabled(false);
        mainScreen_.setStopButtonEnabled(true);
    };
    
    audioEngine_.didStop = [&] {
        mainScreen_.setPlayButtonEnabled(true);
        mainScreen_.setStopButtonEnabled(false);
    };
    
    setSize (700, 300);

    setAudioChannels (0, 2);
}

MainComponent::~MainComponent()
{
    shutdownAudio();
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(21, 28, 31));
}

void MainComponent::resized()
{    
    mainScreen_.setBounds(getBounds());
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    audioEngine_.prepareResources(samplesPerBlockExpected, sampleRate);
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    auto buffer = *bufferToFill.buffer;
    audioEngine_.generateAudioData(buffer.getArrayOfWritePointers(), buffer.getNumChannels(), buffer.getNumSamples());
}

void MainComponent::releaseResources()
{
    audioEngine_.releaseResources();
}
