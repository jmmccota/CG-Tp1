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
	createObjectSystem();
}

EfeitoSonoro::~EfeitoSonoro()
{
	system->release();
}


void EfeitoSonoro::createObjectSystem()
{
	try
	{
		/*
		Create a System object and initialize.
		*/
		FMOD::System_Create(&system);

		system->init(20, FMOD_INIT_NORMAL, 0);

	}
	catch (const std::exception&)
	{
		printf("Error!  You are using an old version of FMOD %08x.  This program requires %08x\n", FMOD_VERSION);
	}
}

void EfeitoSonoro::initAudios_Menu()
{
	arrayAudios.push_back(new FMOD_Audio(system, "audio/music/MainTitles.mp3", true));
	arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/transitioningMenu.mp3", false));
	arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/enterOptionMenu.mp3", false));
}

void EfeitoSonoro::initAudios_GameOver()
{
    finishAllAudios();
    arrayAudios.push_back(new FMOD_Audio(system, "audio/music/GameOver.mp3", true));
}

void EfeitoSonoro::initAudios_Ending()
{
    arrayAudios.push_back(new FMOD_Audio(system, "audio/music/Ending.mp3", true));
}

void EfeitoSonoro::initAudios_SFXGerais()
{
	arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/spitfireMotor.mp3", false));
    arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/vickersShot.mp3", false));
    arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/mg42Shot.mp3", false));
    arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/bombDrop.mp3", false));
    arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/explosion.mp3", false));
    arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/bf109Motor.mp3", false));
    arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/bf163Motor.mp3", false));
}

void EfeitoSonoro::initAudios_TheBlitz() {
	arrayAudios.push_back(new FMOD_Audio(system, "audio/music/TheBlitz.mp3", true));
	initAudios_SFXGerais();
	arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/airRaid.mp3", false));
	arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/me264Motor.mp3", false));
}

void EfeitoSonoro::initAudios_TheBattleOfBritain() {
	arrayAudios.push_back(new FMOD_Audio(system, "audio/music/TheBattleOfBritain.mp3", true));
	initAudios_SFXGerais();
    arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/bismarckMotor.mp3", false));
}

void EfeitoSonoro::initAudios_TheVengeanceWeapon() {
	arrayAudios.push_back(new FMOD_Audio(system, "audio/music/TheVengeanceWeapon.mp3", true));
    initAudios_SFXGerais();
    arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/me262Motor.mp3", false));
	arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/v2Motor.mp3", false));
}

void EfeitoSonoro::finishAllAudios()
{
	for (int i = 0; i < arrayAudios.size(); i++) {
		arrayAudios[i]->getSound()->release();
		arrayAudios[i]->getChannel()->stop();
	}
	system->release();
	arrayAudios.clear();
	createObjectSystem();
}

void EfeitoSonoro::playMainTheme()
{
	arrayAudios[0]->playMemoryAudio(system);
}

#pragma region "Menu"
void EfeitoSonoro::playTransitioningMenu()
{
	arrayAudios[1]->playMemoryAudio(system);
}

void EfeitoSonoro::playEnterMenu()
{
	arrayAudios[2]->playMemoryAudio(system);
}
#pragma endregion

#pragma region "Personagens"
void EfeitoSonoro::playSpitfireMotor()
{
	arrayAudios[1]->playMemoryAudio(system);
	//arrayAudios[2]->setVolume(40);
}

void EfeitoSonoro::playSpitfireFlyBy()
{
}

void EfeitoSonoro::playSpitfireAway()
{
}

void EfeitoSonoro::playBf109Motor()
{
    arrayAudios[6]->playMemoryAudio(system);
}

void EfeitoSonoro::playBf109FlyBy()
{
    //arrayAudios[5]->playMemoryAudio(system);
}

void EfeitoSonoro::playMe163Motor()
{
    //arrayAudios[7]->playMemoryAudio(system);
}

void EfeitoSonoro::playMe264Motor()
{
    //arrayAudios[9]->playMemoryAudio(system);
}

void EfeitoSonoro::playMe262Motor()
{
}

void EfeitoSonoro::playV2Motor()
{
}

void EfeitoSonoro::playVickersShot()
{
    arrayAudios[2]->playMemoryAudio(system);
}

void EfeitoSonoro::playMg42Shot()
{
    arrayAudios[3]->playMemoryAudio(system);
}

void EfeitoSonoro::playBombDrop()
{
    arrayAudios[4]->playMemoryAudio(system);
}

void EfeitoSonoro::stopSpitfireMotor()
{
}

void EfeitoSonoro::stopSpitfireFlyBy()
{
}

void EfeitoSonoro::stopSpitfireAway()
{
}

void EfeitoSonoro::stopBf109Motor()
{
}

void EfeitoSonoro::stopBf109FlyBy()
{
}

void EfeitoSonoro::stopMe163Motor()
{
}

void EfeitoSonoro::stopV2Motor()
{

}
#pragma endregion

#pragma region "SFX Gerais"
//void EfeitoSonoro::playVickersShot()
//{
//    arrayAudios[2]->playMemoryAudio(system);
//}
//
//void EfeitoSonoro::playMg42Shot()
//{
//    arrayAudios[3]->playMemoryAudio(system);
//}
//
//void EfeitoSonoro::playBombDrop()
//{
//    arrayAudios[4]->playMemoryAudio(system);
//}

void EfeitoSonoro::playExplosion()
{
    arrayAudios[5]->playMemoryAudio(system);
}

void EfeitoSonoro::playAirRaid()
{
	arrayAudios[8]->playMemoryAudio(system);
}

void EfeitoSonoro::stopVickers()
{
	arrayAudios[2]->stopAudio();
}

void EfeitoSonoro::stopMg42()
{
	arrayAudios[3]->stopAudio();
}

void EfeitoSonoro::stopBombDrop()
{
	arrayAudios[4]->stopAudio();
}

#pragma endregion

void EfeitoSonoro::playStreamAudio(char *file)
{
	FMOD_Audio *audio = new FMOD_Audio();
	audio->playStreamAudio(system, file, false);
}

EfeitoSonoro& EfeitoSonoro::getInstance()
{
	static EfeitoSonoro singleton;
	return singleton;
}