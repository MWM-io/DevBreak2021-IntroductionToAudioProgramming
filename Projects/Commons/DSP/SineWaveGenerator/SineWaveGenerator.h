//
//  Created by MWM on 28/07/2021.
//


#ifndef SINEWAVEGENERATOR_H
#define SINEWAVEGENERATOR_H

/// A sine wave generator class.
class SineWaveGenerator 
{
public:
    
    /// Constructor.
    /// @param sampleRate The initial sample rate of the sine wave. Must be positive.
    /// @param frequency The inital frequency of the sine wave. Must be positive and below sampleRate/2.
    SineWaveGenerator(float sampleRate = 48000.0f, 
                      float frequency = 440.0f);
    
    /// Sets the sample rate.
    /// @param sampleRate The new sample rate of the sine wave. Must be positive.
    void setSampleRate(float sampleRate);
    
    /// Sets the frequency of the sine wave.
    /// @param frequency The new frequency of the sine wave. Must be positive and below sampleRate/2.
    void setFrequency(float frequency);
    
    /// Returns the frequency of the sine wave.
    float getFrequency() const;
    
    /// Returns the result of processing a single sample.
    float getNextValue();
    
private:
    
    float sampleRate_;
    float frequency_;
    float phase_;
    float phaseIncrement_;
    
};

#endif //SINEWAVEGENERATOR_H

