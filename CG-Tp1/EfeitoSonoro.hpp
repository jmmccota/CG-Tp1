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
	static FMOD::System *system;
	static FMOD::Sound *sound;
	static FMOD::Channel *channel;
	static FMOD_RESULT result;
	static unsigned int version;

private:
	//Verificação de erros
	void static ERRCHECK(FMOD_RESULT result);

	//Execura o som
	void static playSong(char *file, bool loop);

public:
	EfeitoSonoro();
	~EfeitoSonoro();

	//Execução de Sons
	static void playMainTheme(bool loop);
	static void playOpenTheme();
	static void playBoomEffect();

	static void stopSong();

	static FMOD::Sound getSound();

	static void inicializa();
};



#endif
 