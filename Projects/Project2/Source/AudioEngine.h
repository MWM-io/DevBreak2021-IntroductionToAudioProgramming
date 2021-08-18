/*
  ==============================================================================

    AudioEngine.h
    Created: 1 Sep 2021 11:00:04am
    Author:  Mathis Raibaud

  ==============================================================================
*/

#pragma once

#include "../../Commons/DSP/SineWaveGenerator/SineWaveGenerator.h"
#include "../../Commons/DSP/Gain/Gain.h"


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
    
    /// ### Prepare resources
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
    
    /// Generate a block of audio data.
    /// @param outputAudioData Audio buffer to fill, 2D array of size [numChannels, numSamples].
    /// @param numChannels Number of channels.
    /// @param numSamples Number of samples in each channel.
    void generateAudioData(float** outputAudioData, 
                           int numChannels, 
                           int numSamples);
    
    // =========================================
    // CONTROLS
    
    /// Sets the frequency of the sine wave.
    /// @param frequency The new frequency of the sine wave. Must be positive and below sampleRate/2.
    void setSineWaveFrequency(float frequency);
    
    /// Returns the frequency of the sine wave.
    float getSineWaveFrequency() const;
    
    /// Sets the value of the gain.
    /// @param gain The new gain. Must be positive or null.
    void setGain(float gain);
    
    /// Returns the value of the gain.
    float getGain() const;
    
private:
    SineWaveGenerator sineWaveGenerator_;
    Gain gain_;
    
};

