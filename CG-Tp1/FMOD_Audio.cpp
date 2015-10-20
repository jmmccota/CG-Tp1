#include "FMOD_Audio.hpp"


FMOD_Audio::FMOD_Audio(FMOD::System *system, char *file, bool loop)
{

	system->createSound(file, FMOD_DEFAULT, 0, &sound);
	if (loop) {
		sound->setMode(FMOD_LOOP_NORMAL);
	}

	bool isPlaying;

	system->playSound(FMOD_CHANNEL_FREE, sound, true, &channel[0]);
	system->update();
}

FMOD_Audio::FMOD_Audio()
{
}

FMOD::Channel * FMOD_Audio::getChannel()
{
	return this->channel[0];
}

FMOD::Sound * FMOD_Audio::getSound()
{
	return this->sound;
}

void FMOD_Audio::playStreamAudio(FMOD::System *system, char *file, bool loop)
{
	system->createStream(file, FMOD_HARDWARE, 0, &sound);
	system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel[0]);

	if (loop) {
		this->sound->setMode(FMOD_LOOP_NORMAL);
	}

}

void FMOD_Audio::playMemoryAudio(FMOD::System *system)
{
	bool isPaused = false;
	channel[0]->getPaused(&isPaused);

	if (!isPaused) {
		system->playSound(FMOD_CHANNEL_REUSE, sound, false, &channel[0]);
	}
	else {
		channel[0]->setPaused(false);
	}
}

void FMOD_Audio::playMemoryAudio(FMOD::System * system, bool giveMoreChannel)
{
	bool isPaused = false;
	channel[0]->getPaused(&isPaused);

	if (giveMoreChannel) {

	}

	if (!isPaused) {
		system->playSound(FMOD_CHANNEL_REUSE, sound, false, &channel[0]);
	}
	else {
		channel[0]->setPaused(false);
	}
}

void FMOD_Audio::stopAudio()
{
	channel[0]->setPaused(true);
}

void FMOD_Audio::setVolume(float volume)
{
	if (volume >= 0 && volume <= 100) {
		for (int i = 0; i < channel.size(); i++) {
			channel[i]->setVolume(volume / 100);
		}
	}
}

bool FMOD_Audio::getChannelState()
{
	bool isPlaying = false;
	channel[0]->isPlaying(&isPlaying);
	return isPlaying;
}

FMOD_Audio::~FMOD_Audio()
{
	sound->release();
	for (int i = 0; i < channel.size(); i++) {
		channel[i] = 0;
	}
}
