//
//  Created by MWM on 28/07/2021.
//

#include "SmoothedGain.h"
#include <cassert>

SmoothedGain::SmoothedGain(float gain,
                           float sampleRate,
                           float rampLengthInSeconds):
gain_(gain)
{
    setGain(gain);
    reset(sampleRate, rampLengthInSeconds);
}

void SmoothedGain::reset(float sampleRate, float rampLengthInSeconds)
{
    gain_.reset(sampleRate, rampLengthInSeconds);
}

void SmoothedGain::setGain(float gain)
{
    assert(gain >= 0.0f);
    gain_.setTargetValue(gain);    
}

float SmoothedGain::getGain() const
{
    return gain_.getTargetValue();
}

void SmoothedGain::processAudioData(float **ioAudioData, int numChannels, int numSamples)
{
    for (auto sample = 0; sample < numSamples; ++sample)
    {
        auto gain = gain_.getNextValue();
        for (auto channel = 0; channel < numChannels; ++channel)
            ioAudioData[channel][sample] *= gain;
    }
}
