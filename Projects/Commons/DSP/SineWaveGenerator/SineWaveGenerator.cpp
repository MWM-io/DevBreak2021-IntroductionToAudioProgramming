//
//  Created by MWM on 28/07/2021.
//

#include "SineWaveGenerator.h"
#include <cmath>
#include <cassert>

const float twoPi = static_cast<float>(2 * 3.141592653589793238L);

SineWaveGenerator::SineWaveGenerator(float sampleRate, 
                                     float frequency):
sampleRate_(sampleRate),
frequency_(frequency),
phase_(0.0f),
phaseIncrement_(0.0f)
{
    setSampleRate(sampleRate);
    setFrequency(frequency);
}

void SineWaveGenerator::setSampleRate(float sampleRate)
{
    assert(sampleRate > 0.0f);
    
    sampleRate_ = sampleRate;
    setFrequency(frequency_);
}

void SineWaveGenerator::setFrequency(float frequency)
{
    assert(sampleRate_ > 0.0f);
    assert(frequency > 0.0f && frequency < sampleRate_/2.0f);
    
    frequency_ = frequency;
    phaseIncrement_ = twoPi * frequency_ / sampleRate_;
}

float SineWaveGenerator::getFrequency() const
{
    return frequency_;
}

float SineWaveGenerator::getNextValue()
{    
    float value = std::sinf(phase_);
    
    phase_ += phaseIncrement_;
    while (phase_ >= twoPi)
        phase_ -= twoPi;
    
    return value;
}
