//
//  Created by MWM on 28/07/2021.
//


/// A class that applies a linear gain on audio data.
class Gain 
{
public:
    
    /// Constructor.
    /// @param gain The initial gain. Must be positive or null.
    Gain(float gain = 1.0f);
        
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
    
    float gain_;
    
};
