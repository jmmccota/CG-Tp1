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

void EfeitoSonoro::initAudios_TheBlitz() {
    arrayAudios.push_back(new FMOD_Audio(system, "audio/music/TheBlitz.mp3", true));
	arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/vickers.mp3", false));
	arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/mg42.mp3", false));
	arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/bombDrop.mp3", false));
	arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/spitfireMotor.mp3", false));
    arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/bf109Motor.mp3", false));
    arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/bf163Motor.mp3", false));
    arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/me264Motor.mp3", false));
    arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/airRaid.mp3", false));
	//arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/me163Motor.mp3", false));
	//arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/me264Motor.mp3", false));
}

void EfeitoSonoro::initAudios_TheBattleOfBritain() {
	arrayAudios.push_back(new FMOD_Audio(system, "audio/music/TheBlitz.mp3", true));
	arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/vickers.mp3", false));
	//arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/mg42.mp3", false));
	arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/bombDrop.mp3", false));
	arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/spitfireMotor.mp3", false));
	//arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/bf109Motor.mp3", false));
	//arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/me163Motor.mp3", false));
	//arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/bismarkMotor.mp3", false));
}

void EfeitoSonoro::initAudios_TheVengeanceWeapon() {
	arrayAudios.push_back(new FMOD_Audio(system, "audio/music/TheBlitz.mp3", true));
	arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/vickers.mp3", false));
	//arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/mg42.mp3", false));
	arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/bombDrop.mp3", false));
	arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/spitfireMotor.mp3", false));
	//arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/bf109Motor.mp3", false));
	//arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/me163Motor.mp3", false));
	//arrayAudios.push_back(new FMOD_Audio(system, "audio/sfx/v2Motor.mp3", false));
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

void EfeitoSonoro::playTransitioningMenu()
{
	arrayAudios[1]->playMemoryAudio(system);
}

void EfeitoSonoro::playEnterMenu()
{
	arrayAudios[2]->playMemoryAudio(system);
}

void EfeitoSonoro::playSpitfireMotor()
{
    arrayAudios[4]->playMemoryAudio(system);
}

void EfeitoSonoro::playSpitfireFlyBy()
{
}

void EfeitoSonoro::playSpitfireAway()
{
}

void EfeitoSonoro::playBf109Motor()
{
    arrayAudios[5]->playMemoryAudio(system);
}

void EfeitoSonoro::playBf109FlyBy()
{
    arrayAudios[5]->playMemoryAudio(system);
}

void EfeitoSonoro::playMe163Motor()
{
    arrayAudios[6]->playMemoryAudio(system);
}

void EfeitoSonoro::playMe264Motor()
{
    arrayAudios[7]->playMemoryAudio(system);
}

void EfeitoSonoro::playMe262Motor()
{
}

void EfeitoSonoro::playV2Motor()
{
}

void EfeitoSonoro::playVickersShot()
{
    arrayAudios[1]->playMemoryAudio(system);
}

void EfeitoSonoro::playMg42Shot()
{
    arrayAudios[2]->playMemoryAudio(system);
}

void EfeitoSonoro::playBombDrop()
{
    arrayAudios[3]->playMemoryAudio(system);
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

void EfeitoSonoro::stopMe264Motor()
{
}

void EfeitoSonoro::stopMe262Motor()
{
}

void EfeitoSonoro::stopV2Motor()
{
}

void EfeitoSonoro::stopVickers()
{
}

void EfeitoSonoro::stopMg42()
{
}

void EfeitoSonoro::stopBombDrop()
{
}


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