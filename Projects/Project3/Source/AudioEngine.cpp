/*
  ==============================================================================

    AudioEngine.cpp
    Created: 1 Sep 2021 2:05:28pm
    Author:  Mathis Raibaud

  ==============================================================================
*/

#include "AudioEngine.h"

AudioEngine::AudioEngine()
{
    player_.didPlay = [&]() { 
        if (didPlay != nullptr)
            didPlay();
    };
    
    player_.didStop = [&]() { 
        if (didStop != nullptr)
            didStop();
    };
        
#if JUCE_ANDROID
    juce::ZipFile apkZip (juce::File::getSpecialLocation (juce::File::invokedExecutableFile));
    auto stream = apkZip.createStreamForEntry (apkZip.getIndexOfFileName ("assets/" + juce::String ("Voice.wav")));
    juce::AudioFormatManager formatManager;
    formatManager.registerBasicFormats();
    auto* reader = formatManager.createReaderFor (std::unique_ptr<juce::InputStream>(stream));
    player_.Load(*reader);
#elif JUCE_IOS
    auto file = juce::File::getSpecialLocation (juce::File::currentExecutableFile).getParentDirectory().getChildFile ("Tracks").getChildFile("Voice.wav");
    player_.Load(file);
#endif
}

void AudioEngine::prepareResources(int maxSamplesPerBlock, double sampleRate) 
{
    player_.prepareResources(maxSamplesPerBlock, sampleRate);
    ringModulator_.setSampleRate(sampleRate);
    gain_.reset(sampleRate, 0.01f);
}

void AudioEngine::releaseResources() 
{
    player_.releaseResources();
}

void AudioEngine::generateAudioData(float **outputAudioData, int numChannels, int numSamples) 
{
    player_.generateAudioData(outputAudioData, numChannels, numSamples);
    ringModulator_.processAudioData(outputAudioData, numChannels, numSamples);
    gain_.processAudioData(outputAudioData, numChannels, numSamples);
}

void AudioEngine::Load(const juce::File &file)
{
    player_.Load(file);
}

void AudioEngine::Play()
{
    player_.Play();
}

void AudioEngine::Stop()
{
    player_.Stop();
}

void AudioEngine::setRingModulatorFrequency(float frequency) 
{    
    ringModulator_.setFrequency(frequency);
}

float AudioEngine::getRingModulatorFrequency() const 
{    
    return ringModulator_.getFrequency();
}

void AudioEngine::setGain(float gain)
{
    gain_.setGain(gain);
}

float AudioEngine::getGain() const
{
    return gain_.getGain();
}
