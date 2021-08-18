//
//  Created by MWM on 28/07/2021.
//

#include "Gain.h"
#include <cassert>

Gain::Gain(float gain)
{
    setGain(gain);
}

void Gain::setGain(float gain)
{
    assert(gain >= 0.0f);
    gain_ = gain;    
}

float Gain::getGain() const
{
    return gain_;
}

void Gain::processAudioData(float** ioAudioData,
                            int numChannels,
                            int numSamples)
{
    for (auto sample = 0; sample < numSamples; ++sample) 
    {
        for (auto channel = 0; channel < numChannels; ++channel) 
        {
            ioAudioData[channel][sample] *= gain_;
        }
    }
}
