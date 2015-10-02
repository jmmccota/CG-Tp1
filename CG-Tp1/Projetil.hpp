#ifndef PROJETIL_H
#define PROJETIL_H

class Projetil;

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include "Solido.hpp"


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
        Projetil(GLfloat pX, GLfloat pY, GLfloat vel, float esc);

        void acao();
};



#endif