#include "EfeitoSonoro.hpp"

void EfeitoSonoro::ERRCHECK(FMOD_RESULT result)
{
	if (result != FMOD_OK)
	{
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
		exit(-1);
	}
}

void EfeitoSonoro::createObjectSystem() {
	try
	{
		/*
		Create a System object and initialize.
		*/
		result = FMOD::System_Create(&system);
		result = system->getVersion(&version);
		
		if (version < FMOD_VERSION)
		{
			throw;
		}
		result = system->init(10, FMOD_INIT_NORMAL, 0);
		ERRCHECK(result);
	}
	catch (const std::exception&)
	{
		printf("Error!  You are using an old version of FMOD %08x.  This program requires %08x\n", version, FMOD_VERSION);
	}
	channel = 0;
}


EfeitoSonoro::EfeitoSonoro()
{
	createObjectSystem();
}


EfeitoSonoro::~EfeitoSonoro()
{

}

void EfeitoSonoro::playSong(char *file, bool loop) {

	result = system->createSound(file, FMOD_HARDWARE, 0, &sound);
	result = system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);

	if (loop) {
		channel->setMode(FMOD_LOOP_NORMAL);
	}

}

// -------------------- Musics ------------------------
void EfeitoSonoro::playMainTheme() {
    playSong("music/MainTitles.mp3", true);
}
void EfeitoSonoro::playFirstLevelTheme()
{
	playSong("music/TheBlitz.mp3", true);
}
void EfeitoSonoro::playSecondLevelTheme()
{
	playSong("music/TheBattleOfBritain.mp3", true);
}
void EfeitoSonoro::playThirdLevelTheme()
{
	playSong("music/TheVengeanceWeapon.mp3", true);
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
void EfeitoSonoro::vickersShot()
{
    playSong("sfx/vickers.mp3", false);
}
void EfeitoSonoro::airRaidSiren()
{
    playSong("sfx/airRaid.mp3", false);
}
void EfeitoSonoro::spitfireFlyBy()
{
    playSong("sfx/spitfireFlyBy.mp3", false);
}
void EfeitoSonoro::spitfireMotor()
{
    playSong("sfx/spitfireMotor.mp3", false);
}
void EfeitoSonoro::spitfireMotorAway()
{
    playSong("sfx/spitfireMotorAway.mp3", false);
}
// ------------------------------------------------------------

void EfeitoSonoro::stopSong() {
	channel->stop();
	sound->release();
	system->release();
	createObjectSystem();	
}

FMOD::Sound EfeitoSonoro::getSound() {
	return *sound;
}

EfeitoSonoro& EfeitoSonoro::getInstance()
{
	static EfeitoSonoro singleton;
	return singleton;
}