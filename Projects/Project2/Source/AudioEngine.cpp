/*
  ==============================================================================

    AudioEngine.cpp
    Created: 1 Sep 2021 11:00:04am
    Author:  Mathis Raibaud

  ==============================================================================
*/

#include "AudioEngine.h"


void AudioEngine::prepareResources(int maxSamplesPerBlock, double sampleRate) 
{
    sineWaveGenerator_.setSampleRate(sampleRate);
}

void AudioEngine::releaseResources() 
{
    
}

void AudioEngine::generateAudioData(float **outputAudioData, int numChannels, int numSamples) {
    
    for (int sample = 0; sample < numSamples; ++sample)
    {
        float sinusValue = sineWaveGenerator_.getNextValue();
        for (int channel = 0; channel < numChannels; ++channel)
            outputAudioData[channel][sample] = sinusValue;
    }
    
    gain_.processAudioData(outputAudioData, 
                           numChannels, 
                           numSamples);

}

void AudioEngine::setSineWaveFrequency(float frequency) 
{    
    sineWaveGenerator_.setFrequency(frequency);
}

float AudioEngine::getSineWaveFrequency() const 
{    
    return sineWaveGenerator_.getFrequency();
}

void AudioEngine::setGain(float gain)
{
    gain_.setGain(gain);
}

float AudioEngine::getGain() const
{
    return gain_.getGain();
}


