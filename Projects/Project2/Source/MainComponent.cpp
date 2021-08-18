#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    addAndMakeVisible(&main_screen_);
    main_screen_.onFrequencySliderChanged = [&](float frequency) { audio_engine_.setSineWaveFrequency(frequency); };
    main_screen_.onGainSliderChanged = [&](float gain) { audio_engine_.setGain(gain); };
    audio_engine_.setSineWaveFrequency(main_screen_.getFrequencySliderValue());
    audio_engine_.setGain(main_screen_.getGainSliderValue());
    
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
    main_screen_.paint(g);
}

void MainComponent::resized()
{
    main_screen_.setBounds(getBounds());
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
