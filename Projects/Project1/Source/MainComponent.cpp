#include "MainComponent.h"


//==============================================================================
MainComponent::MainComponent() :
audio_engine_(),
main_screen_()
{
    setSize (700, 300);
    main_screen_.setSize(700, 300);
    main_screen_.onFrequencySliderChanged = [&](float frequency) {
        audio_engine_.setSineWaveFrequency(frequency);
    };
    addAndMakeVisible(&main_screen_);
    
    audio_engine_.setSineWaveFrequency(main_screen_.getFrequencySliderValue());
    
    setAudioChannels (0, 2);
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}


//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    main_screen_.paint(g);
}

void MainComponent::resized()
{
    main_screen_.setSize(getWidth(), getHeight());
    main_screen_.resized();
}


//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    audio_engine_.prepareResources(samplesPerBlockExpected, sampleRate);
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    auto buffer = *bufferToFill.buffer;
    audio_engine_.generateAudioData(buffer.getArrayOfWritePointers(), buffer.getNumChannels(), buffer.getNumSamples());
}

void MainComponent::releaseResources()
{
    audio_engine_.releaseResources();
}
