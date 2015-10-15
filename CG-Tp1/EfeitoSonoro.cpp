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

}

void EfeitoSonoro::initAudios_TheBattleOfBritain() {

}

void EfeitoSonoro::initAudios_TheVengeanceWeapon() {

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