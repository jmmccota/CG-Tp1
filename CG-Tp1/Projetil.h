#ifndef PROJETIL_ABS
#define PROJETIL_ABS



#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include "Solido.h"


/*
	Classe abstrata para servir como "interface" para
		os projeteis do jogo.
*/


class Projetil : public Solido
{
	protected:
		//Dano causado pelo projetil
		int dano;
};



#endif