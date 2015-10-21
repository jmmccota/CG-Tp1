#ifndef EFEITOSONORO_H
#define EFEITOSONORO_H

class EfeitoSonoro;


#include <fmod.hpp>
#include <fmod_errors.h>
#include <iostream>
#include <vector>
#include "FMOD_Audio.hpp"

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
	vector<FMOD_Audio *> arrayAudios;

private:
	//Verificação de erros
	void ERRCHECK(FMOD_RESULT result);

public:
	EfeitoSonoro();
	~EfeitoSonoro();

	//Criar um objeto de sistema
	void createObjectSystem();

	//Iniciar os sons da Fase
    void initAudios_Menu();
    void initAudios_GameOver();
	void initAudios_SFXGerais();
	void initAudios_TheBlitz();
	void initAudios_TheBattleOfBritain();
	void initAudios_TheVengeanceWeapon();
	//void initAudios_GameOver();

	//Finalisar todos os sons
	void finishAllAudios();

	//Tocar a Musica principal
	void playMainTheme();

	//Sons do Menu
	void playTransitioningMenu();
	void playEnterMenu();

	//Sons personagens
	void playSpitfireMotor();
	void playSpitfireFlyBy();
	void playSpitfireAway();
	void playBf109Motor();
	void playBf109FlyBy();
	void playMe163Motor();
	void playMe264Motor();
	void playMe262Motor();
	void playV2Motor();
	void stopSpitfireMotor();
	void stopSpitfireFlyBy();
	void stopSpitfireAway();
	void stopBf109Motor();
	void stopBf109FlyBy();
	void stopMe163Motor();
	void stopMe264Motor();
	void stopMe262Motor();
	void stopV2Motor();

	//Sons gerais
	void playAirRaid();
	void playVickersShot();
	void playMg42Shot();
	void playBombDrop();
    void playExplosion();
	void stopVickers();
	void stopMg42();
	void stopBombDrop();
	void playGanhaVida();

	//Tocar os sons uma vez sem carregar na memoria
	void playStreamAudio(char *file);


	static EfeitoSonoro& getInstance();
};



#endif
