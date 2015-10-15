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

public:
	EfeitoSonoro();
	~EfeitoSonoro();

	void initAudios_Menu();
	void initAudios_TheBlitz();


	//Tocar a Musica principal
	void playMainTheme();

	//Sons do Menu
	void playTransitioningMenu();
	void playEnterMenu();

	static EfeitoSonoro& getInstance();
};



#endif
