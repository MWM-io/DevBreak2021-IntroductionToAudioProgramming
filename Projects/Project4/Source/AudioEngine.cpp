/*
  ==============================================================================

    AudioEngine.cpp
    Created: 1 Sep 2021 6:24:22pm
    Author:  Mathis Raibaud

  ==============================================================================
*/

#include "AudioEngine.h"

void AudioEngine::prepareResources(int maxSamplesPerBlock, double sampleRate)
{
    ringModulator_.setSampleRate(sampleRate);
    gain_.reset(sampleRate, 0.01f);
}

void AudioEngine::releaseResources()
{
    
}

void AudioEngine::processAudioData(float **ioAudioData, int inputNumChannels, int outputNumChannels, int numSamples)
{
    // TO DO
    // Apply the gain and the ringModulator to the ioAudioData
    // Be careful: the input is mono and we want a stereo output !
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
