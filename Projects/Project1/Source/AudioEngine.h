/*
 ==============================================================================
 
 AudioEngine.h
 Created: 30 Aug 2021 10:45:03am
 Author:  Thomas Hézard
 
 ==============================================================================
 */

#pragma once

#include "../../Commons/DSP/SineWaveGenerator/SineWaveGenerator.h"


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
    
private:
    SineWaveGenerator sineWaveGenerator_;
    
};
