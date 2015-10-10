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
	Porque:
		Somente uma instancia pode existir para que as informacoes
		de estado do som sejam consistentes durante o jogo todo.

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
	//Verificação de erros
	void ERRCHECK(FMOD_RESULT result);

	//Execura o som
	void playSong(char *file, bool loop);

public:
	~EfeitoSonoro();

	//Execução de Músicas
	void playOpenTheme();
	void playMainTheme();
	void playFirstFaseTheme();
	void playSecondFaseTheme();
	void playThirdFaseTheme();

	//Execução de Sounds
	void playBoomEffect();

	void stopSong();

	FMOD::Sound getSound();

	static EfeitoSonoro& getInstance();
};



#endif
