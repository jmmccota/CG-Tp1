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
	//Verificação de erros
	void ERRCHECK(FMOD_RESULT result);

	//Execura o som
	void playSong(char *file, bool loop);

public:
	EfeitoSonoro();
	~EfeitoSonoro();
	
	//Execução de Sons
	void playMainTheme(bool loop);
	void playOpenTheme();

	void stopSong();
	
	FMOD::Sound getSound();


};



#endif