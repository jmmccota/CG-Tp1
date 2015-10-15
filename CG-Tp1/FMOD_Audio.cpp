#include "FMOD_Audio.hpp"


FMOD_Audio::FMOD_Audio(FMOD::System *system, char *file, bool loop)
{

	system->createSound(file, FMOD_DEFAULT, 0, &sound);
	if (loop) {
		sound->setMode(FMOD_LOOP_NORMAL);
	}

	bool isPlaying;

	system->playSound(FMOD_CHANNEL_FREE, sound, true, &channel);
	system->update();
}

FMOD_Audio::FMOD_Audio()
{
}

FMOD::Channel * FMOD_Audio::getChannel()
{
	return this->channel;
}

FMOD::Sound * FMOD_Audio::getSound()
{
	return this->sound;
}

void FMOD_Audio::playStreamAudio(FMOD::System *system, char *file, bool loop)
{
	system->createStream(file, FMOD_HARDWARE, 0, &sound);
	system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);

	if (loop) {
		this->sound->setMode(FMOD_LOOP_NORMAL);
	}

}

void FMOD_Audio::playMemoryAudio(FMOD::System *system)
{
	bool isPaused = false;
	channel->getPaused(&isPaused);

	if (!isPaused) {
		system->playSound(FMOD_CHANNEL_REUSE, sound, false, &channel);
	}
	else {
		channel->setPaused(false);
	}
}


FMOD_Audio::~FMOD_Audio()
{
}
