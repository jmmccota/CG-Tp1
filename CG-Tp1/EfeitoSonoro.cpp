#include "EfeitoSonoro.h"

void EfeitoSonoro::ERRCHECK(FMOD_RESULT result)
{
	if (result != FMOD_OK)
	{
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
		exit(-1);
	}
}

EfeitoSonoro::EfeitoSonoro()
{
	try
	{
		/*
		Create a System object and initialize.
		*/
		result = FMOD::System_Create(&system);
		ERRCHECK(result);

		result = system->getVersion(&version);
		ERRCHECK(result);

		if (version < FMOD_VERSION)
		{
			throw;
		}
		result = system->init(32, FMOD_INIT_NORMAL, 0);
		ERRCHECK(result);
	}
	catch (const std::exception&)
	{
		printf("Error!  You are using an old version of FMOD %08x.  This program requires %08x\n", version, FMOD_VERSION);
	}
}


EfeitoSonoro::~EfeitoSonoro()
{

}

void EfeitoSonoro::playMainTheme(bool loop) {
	result = system->createSound("Sound/MainTheme.mp3", FMOD_HARDWARE, 0, &sound);
	ERRCHECK(result);
	result = system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);
	ERRCHECK(result);

	if (loop) {
		channel->setMode(FMOD_LOOP_NORMAL);
	}
}

void EfeitoSonoro::playOpenSound() {
	result = system->createSound("Sound/Open_Theme.mp3", FMOD_HARDWARE, 0, &sound);
	ERRCHECK(result);
	result = system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);
	ERRCHECK(result);
}
void EfeitoSonoro::stopSound() {
	result = sound->release();
	ERRCHECK(result);
}

FMOD::Sound EfeitoSonoro::getSound() {
	return *sound;
}