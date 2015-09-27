#ifndef EFEITOSONORO_H
#define EFEITOSONORO_H

class EfeitoSonoro;


#include <fmod.hpp>
#include <fmod_errors.h>
#include <iostream>

using namespace std;
/*
	Classe usada para efeitos sonoros
		(efeito sonoro, musica, ...)
*/


class EfeitoSonoro
{

protected:
	FMOD::System *system;
	FMOD::Sound *sound;
	FMOD::Channel *channel = 0;
	FMOD_RESULT result;
	unsigned int version;

private:
	//Verifica��o de erros
	void ERRCHECK(FMOD_RESULT result);

public:
	EfeitoSonoro();
	~EfeitoSonoro();
	
	void playMainTheme(bool loop);
	void stopSound();
	
	FMOD::Sound getSound();


};



#endif