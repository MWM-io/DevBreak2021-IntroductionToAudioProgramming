//
//  Created by MWM on 28/07/2021.
//

#pragma once

#include <JuceHeader.h>
#include "../SineWaveGenerator/SineWaveGenerator.h"

/// A class that applies a Ring Modulation effect on audio data.
class RingModulator 
{
public:
    
    /// Constructor.
    /// @param sampleRate The initial sample rate. Must be positive.
    /// @param frequency The inital frequency. Must be positive and below sampleRate/2.
    RingModulator(float sampleRate = 48000.0f, 
                  float frequency = 440.0f);
    
    /// Sets the sample rate.
    /// @param sampleRate The new sample rate of the sinus. Must be positive.
    void setSampleRate (float sampleRate);
    
    /// Sets the frequency of the RingModulator.
    /// @param frequency The new frequency. Must be positive and below sampleRate/2.
    void setFrequency(float frequency);
    
    /// Returns the frequency of the RingModulator.
    float getFrequency() const;
    
    /// Process a block of audio data.
    /// @param ioAudioData Audio buffer to process, 2D array of size [numChannels, numSamples].
    /// @param numChannels Number of channels.
    /// @param numSamples Number of smaples in each channel.
    void processAudioData(float** ioAudioData, 
                          int numChannels, 
                          int numSamples);
    
private:
    
    // TO DO: Add all necessary private variables
    
};
