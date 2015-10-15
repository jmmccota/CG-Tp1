#include "EfeitoSonoro.hpp"

EfeitoSonoro::EfeitoSonoro()
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

EfeitoSonoro::~EfeitoSonoro()
{
}

void EfeitoSonoro::initAudios_Menu()
{
	arrayAudios.push_back(new FMOD_Audio(system, "music/MainTitles.mp3", true));
	arrayAudios.push_back(new FMOD_Audio(system, "Sound/TransitioningMenu_Effect.mp3", false));
	arrayAudios.push_back(new FMOD_Audio(system, "Sound/EnterMenu_Effect.mp3", false));
}

void EfeitoSonoro::initAudios_TheBlitz()
{
	//arrayAudios.push_back(new FMOD_Audio(&*system, "music/MainTitles.mp3", true));
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



EfeitoSonoro& EfeitoSonoro::getInstance()
{
	static EfeitoSonoro singleton;
	return singleton;
}