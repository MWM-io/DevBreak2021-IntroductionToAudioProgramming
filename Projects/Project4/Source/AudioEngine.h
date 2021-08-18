/*
  ==============================================================================

    AudioEngine.h
    Created: 1 Sep 2021 6:24:22pm
    Author:  Mathis Raibaud

  ==============================================================================
*/

#pragma once

#include "../../Commons/DSP/RingModulator/RingModulator.h"
#include "../../Commons/DSP/Gain/SmoothedGain.h"


class AudioEngine {
    
public:
    
    // =========================================
    // CONSTRUCTOR & DESTRUCTOR
    
    /// Default constructor
    AudioEngine() = default;
    
    /// Default destructor
    ~AudioEngine() = default;
    
    // =========================================
    // AUDIO LIFE CYCLE
    
    /// Prepare resources
    /// Inform audio modules of samples per block and sample rate values, 
    /// so that they can prepare (allocate buffers etc.) their resources
    /// to get ready to generate/process audio data.
    /// @param maxSamplesPerBlock Max value of `numSamples` in a `generateAudioData` call.
    /// @param sampleRate Sample rate of audio data.
    void prepareResources(int maxSamplesPerBlock, double sampleRate);
    
    /// Release resources
    /// Inform audio modules that they can release their resources before
    /// the app terminates or before a change in sample rate or samples 
    /// per block values.
    void releaseResources();
    
    /// Process a block of audio data.
    /// @param ioAudioData Audio buffer to process, 2D array of size [numChannels, numSamples].
    /// @param inputNumChannels Number of input channels.
    /// @param outputNumChannels Number of output channels.
    /// @param numSamples Number of samples in each channel.
    void processAudioData(float** ioAudioData, 
                          int inputNumChannels,
                          int outputNumChannels,
                          int numSamples);
    
    // =========================================
    // CONTROLS
    
    /// Sets the frequency of the sinus.
    /// @param frequency The new frequency of the sinus. Must be positive and below sampleRate/2.
    void setRingModulatorFrequency(float frequency);
    
    /// Returns the frequency of the sinus.
    float getRingModulatorFrequency() const;
    
    /// Sets the value of the gain.
    /// @param gain The new gain. Must be positive or null.
    void setGain(float gain);
    
    /// Returns the value of the gain.
    float getGain() const;
    
private:
    RingModulator ringModulator_;
    SmoothedGain gain_;
};
