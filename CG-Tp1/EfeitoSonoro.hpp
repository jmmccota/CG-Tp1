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
	void initAudios_TheBlitz();
	void initAudios_TheBattleOfBritain();
	void initAudios_TheVengeanceWeapon();

	//Finalisar todos os sons
	void finishAllAudios();

	//Tocar a Musica principal
	void playMainTheme();

	//Sons do Menu
	void playTransitioningMenu();
	void playEnterMenu();

	//Tocar os sons uma vez sem carregar na memoria
	void playStreamAudio(char *file);


	static EfeitoSonoro& getInstance();
};



#endif
