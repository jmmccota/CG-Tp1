#include "EfeitoSonoro.hpp"

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
	channel = 0;
}


EfeitoSonoro::~EfeitoSonoro()
{

}


void EfeitoSonoro::playSong(char *file, bool loop) {

	result = system->createSound(file, FMOD_HARDWARE, 0, &sound);
	ERRCHECK(result);
	result = system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);
	ERRCHECK(result);

	if (loop) {
		channel->setMode(FMOD_LOOP_NORMAL);
	}

}

// -------------------- Musics Themes ------------------------
void EfeitoSonoro::playOpenTheme() {
	playSong("Sound/Open_Theme.mp3", false);
}

void EfeitoSonoro::playMainTheme() {
	playSong("Sound/Main_Theme.mp3", true);
}

void EfeitoSonoro::playFirstFaseTheme()
{
	playSong("Sound/FirstFase_Theme.mp3", true);
}

void EfeitoSonoro::playSecondFaseTheme()
{
	playSong("Sound/SecondtFase_Theme.mp3", true);
}

void EfeitoSonoro::playThirdFaseTheme()
{
	playSong("Sound/ThirdFase_Theme.mp3", true);
}
// ------------------------------------------------------------

// -------------------- Effects Sounds ------------------------
void EfeitoSonoro::playBoomEffect()
{
	playSong("Sound/Boom_Effect.mp3", false);
}
void EfeitoSonoro::playTransitioningMenuEffect()
{
	playSong("Sound/TransitioningMenu_Effect.mp3", false);
}
void EfeitoSonoro::playEnterMenuEffect()
{
	playSong("Sound/EnterMenu_Effect.mp3", false);
}
// ------------------------------------------------------------

void EfeitoSonoro::stopSong() {
	result = sound->release();
	ERRCHECK(result);
}

FMOD::Sound EfeitoSonoro::getSound() {
	return *sound;
}

EfeitoSonoro& EfeitoSonoro::getInstance()
{
	static EfeitoSonoro singleton;
	return singleton;
}