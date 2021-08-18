//
//  Created by MWM on 28/07/2021.
//

#pragma once

/// A utility class for values that need smoothing to avoid audio glitches. 
class SmoothedValue 
{
public:
    
    /// Constructor.
    /// @param value The initial value.
    SmoothedValue(float value,
                  float sampleRate = 48000.0f,
                  float rampLengthInSeconds = 0.01f);
    
    /// Sets a new sample rate and ramp length.
    /// @param sampleRate The new sample rate. Must be positive.
    /// @param rampLengthInSeconds The time in which the current value reaches the target value. Must be positive.
    void reset(float sampleRate, float rampLengthInSeconds);
    
    /// Sets the target value.
    /// @param value The new target value.
    void setTargetValue(float value);
    
    /// Returns the target value.
    float getTargetValue() const;
    
    /// Returns the current value.
    float getCurrentValue() const;
    
    /// Computes the next value.
    float getNextValue();
    
private:
    
    float current_;
    float target_;
    float step_;
    int rampLenthInSamples_;
    
};
