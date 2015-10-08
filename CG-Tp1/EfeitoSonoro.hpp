#ifndef EFEITOSONORO_H
#define EFEITOSONORO_H

class EfeitoSonoro;


#include <fmod.hpp>
#include <fmod_errors.h>
#include <iostream>

using namespace std;
/*
	===============SINGLETON===============
	Somente uma instancia vai ser usada no programa todo.
	Como usar:
		EfeitoSonoro::getInstance().FUNCAOQUEEUQUEROCHAMAR(PARAMETROS);
		...

	Classe usada para efeitos sonoros
		(efeito sonoro, musica, ...)
*/


class EfeitoSonoro
{

private:
	FMOD::System *system;
	FMOD::Sound *sound;
	FMOD::Channel *channel;
	FMOD_RESULT result;
	unsigned int version;
	EfeitoSonoro();
	EfeitoSonoro(EfeitoSonoro const&);
	void operator=(EfeitoSonoro const&);

private:
	//Verifica��o de erros
	void ERRCHECK(FMOD_RESULT result);

	//Execura o som
	void playSong(char *file, bool loop);

public:
	~EfeitoSonoro();

	//Execu��o de Sons
	void playMainTheme(bool loop);
	void playOpenTheme();
	void playBoomEffect();

	void stopSong();

	FMOD::Sound getSound();

	EfeitoSonoro& getInstance()
	{
		static EfeitoSonoro singleton;
		return singleton;
	}
};



#endif
 