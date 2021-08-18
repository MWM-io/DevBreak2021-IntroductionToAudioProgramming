/*
  ==============================================================================

    AudioEngine.h
    Created: 1 Sep 2021 2:05:28pm
    Author:  Mathis Raibaud

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../../Commons/DSP/AudioFilePlayer/AudioFilePlayer.h"
#include "../../Commons/DSP/RingModulator/RingModulator.h"
#include "../../Commons/DSP/Gain/SmoothedGain.h"


class AudioEngine {
    
public:
    
    // =========================================
    // CONSTRUCTOR & DESTRUCTOR
    
    /// Constructor
    AudioEngine();
    
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
    
    /// Loads an audio file.
    void Load(const juce::File& file);
        
    /// Starts the playback of the audio file (if a file has been loaded).
    void Play();
    
    /// You can assign a lambda to this callback object to have it called when the playback has started.
    std::function<void()> didPlay;
    
    /// Stops the playback of the audio file.
    void Stop();
    
    /// You can assign a lambda to this callback object to have it called when the playback has stopped.
    /// Note that didStop can be called when you call Stop() or when playback reaches the end of the audio file. 
    std::function<void()> didStop;
    
    /// Sets the frequency of the sinus.
    /// @param frequency The new frequency of the sinus. Must be positive and below sampleRate/2.
    void setRingModulatorFrequency(float frequency);
    
    /// Returns the frequency of the sinus.
    float getRingModulatorFrequency() const;
    
    /// Sets the value of the gain.
    /// @param gain The new gain. Must be positive or null.
    void setGain(float gain);
    
    /// Returns the value of the gain.
    float getGain() const;

private:
    AudioFilePlayer player_;
    RingModulator ringModulator_;
    SmoothedGain gain_;
    
};
