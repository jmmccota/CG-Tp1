#pragma once
#include <fmod.hpp>
#include <fmod_errors.h>
#include <iostream>
#include <vector>

class FMOD_Audio
{
protected:
	FMOD::Sound *sound;
	FMOD::Channel *channel;
public:
	FMOD_Audio(FMOD::System *system, char *file, bool loop);
	FMOD_Audio();
	~FMOD_Audio();

	//Getters
	FMOD::Channel *getChannel();
	FMOD::Sound *getSound();

	//Play Once
	void playStreamAudio(FMOD::System *system, char *file, bool loop);
	//Save in memory
	void playMemoryAudio(FMOD::System *system);
};

