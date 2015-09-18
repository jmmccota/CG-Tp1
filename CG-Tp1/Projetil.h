#ifndef PROJETIL_ABS
#define PROJETIL_ABS



#include <GL/gl.h>
#include <GL/glut.h>


/*
	Classe abstrata para servir como "interface" para
		os projeteis do jogo.
*/


class Projetil : protected Solido
{
	protected:
		//Dano causado pelo projetil
		int dano;
};



#endif