#ifndef PROJETIL_H
#define PROJETIL_H



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

    public:
        Projetil(GLfloat posX, GLfloat posY, GLfloat velocidade, float escala);

        void acao();
};



#endif