#ifndef EFEITOVISUAL_ABS
#define EFEITOVISUAL_ABS

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include "Solido.h"


/*
	Classe usada para efeitos visuais
		(deteccao de colisao, explosoes, ...)
*/


class EfeitoVisual
{
protected:
	bool fullScreen = false;
public:
	EfeitoVisual();
	~EfeitoVisual();

	//COMO FAZER ANIMACAO EXPLOSAO?
	//void static Explosao(GLfloat x, GLfloat y, GLfloat raio, int estagio);

	//Retorna true caso objetos tenham colidido, false caso contrario
	bool static Colisao(Solido *a, Solido *b);

	//Metodo de pressionamento de teclas
	void Teclas(unsigned char tecla, GLint x, GLint y) {

		switch (tecla) {
			//A tecla 'f' alterna entre a tecla cheia (full screen) e não cheia.
		case 'f':
			if (!fullScreen) {
				glutFullScreen();
			}
			else {
				glutReshapeWindow(800, 600);
			}
			fullScreen = fullScreen;
			break;
		}
	}

	//Retorna se a tela está em fullScreen ou não
	bool isFullScreen() {
		return fullScreen;
	}


};




#endif