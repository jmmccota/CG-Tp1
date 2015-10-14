#ifndef EFEITOSONORO_H
#define EFEITOSONORO_H

class EfeitoSonoro;


#include <fmod.hpp>
#include <fmod_errors.h>
#include <iostream>
#include <vector>

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

protected:
	FMOD::System *system;
	FMOD::Sound *sound;
	FMOD::Channel *channel;
	FMOD_RESULT result;
	unsigned int version;

private:
	EfeitoSonoro();
	EfeitoSonoro(EfeitoSonoro const&);

	//Verificação de erros
	void ERRCHECK(FMOD_RESULT result);

	//Executa o som
	void playSong(char *file, bool loop);

	void operator=(EfeitoSonoro const&);
	void createObjectSystem();

public:
	~EfeitoSonoro();
	
	//Altera o volume do canal virtual do som
	void setVolumeSound(FMOD::Channel *selectedChannel, float volume);
	//Altera o estato do canal virtual do som para pausado ou tocando
	void setStateSound(FMOD::Channel *selectedChannel, bool state);
	//Finalisa todos os som e cria um novo objeto sonoro
	void finishAllSounds();

	//Execução de Músicas
	void playMainTheme();
	void playFirstLevelTheme();
	void playSecondLevelTheme();
	void playThirdLevelTheme();

	//Execução de Sounds
	void playBoomEffect();
	void playTransitioningMenuEffect();
	void playEnterMenuEffect();
	void airRaidSiren();
	//Spitfire
	void spitfireFlyBy();
	void spitfireMotor();
	void spitfireMotorAway();
	//Bf109
	void bf109FlyBy();
	//Armamentos
	void vickersShot();
	void bombDrop();

	static EfeitoSonoro& getInstance();
};



#endif
