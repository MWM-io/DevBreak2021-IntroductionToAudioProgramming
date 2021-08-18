//
//  Created by MWM on 28/07/2021.
//

#pragma once

#include "../Utility/SmoothedValue.h"

/// A class that applies a linear gain on audio data. The value of the gain is smoothed to avoid audio glitches. 
class SmoothedGain 
{
public:
    
    /// Constructor.
    /// @param gain The initial gain. Must be positive or null.
    SmoothedGain(float gain = 1.0f,
                 float sampleRate = 48000.0f,
                 float rampLengthInSeconds = 0.01f);
    
    /// Sets a new sample rate and ramp length.
    /// @param sampleRate The new sample rate. Must be positive.
    /// @param rampLengthInSeconds The time in which the gain reaches its target value. Must be positive.
    void reset(float sampleRate, 
               float rampLengthInSeconds);
    
    /// Sets the value of the gain.
    /// @param gain The new gain. Must be positive or null.
    void setGain(float gain);
    
    /// Returns the value of the gain.
    float getGain() const;
    
    /// Process a block of audio data.
    /// @param ioAudioData Audio buffer to process, 2D array of size [numChannels, numSamples].
    /// @param numChannels Number of channels.
    /// @param numSamples Number of smaples in each channel.
    void processAudioData(float** ioAudioData, 
                          int numChannels, 
                          int numSamples);
    
private:
    
    SmoothedValue gain_;
};
