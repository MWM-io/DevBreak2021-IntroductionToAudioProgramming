//
//  Created by MWM on 28/07/2021.
//

#include "SmoothedValue.h"
#include <cmath>
#include <cassert>

SmoothedValue::SmoothedValue(float value,
                             float sampleRate,
                             float rampLengthInSeconds)
{
    reset(sampleRate, rampLengthInSeconds);
}

void SmoothedValue::reset(float sampleRate, float rampLengthInSeconds)
{
    assert(sampleRate > 0.0f);
    assert(rampLengthInSeconds > 0.0f);
    
    current_ = target_;
    rampLenthInSamples_ = std::roundf(sampleRate * rampLengthInSeconds);
}

void SmoothedValue::setTargetValue(float value)
{
    target_ = value;
    step_ = (target_ - current_) / rampLenthInSamples_;
}

float SmoothedValue::getTargetValue() const
{
    return target_;
}

float SmoothedValue::getCurrentValue() const
{
    return current_;
}

float SmoothedValue::getNextValue()
{
    const auto target = target_;
    const auto step = step_;
    
    if (current_ == target_)
        return current_;
    
    if (fabsf(current_ - target) < fabsf(step))
        return current_ = target;
    
    return current_ += step;
}

