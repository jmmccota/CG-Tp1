#ifndef PROJETIL_ABS
#define PROJETIL_ABS



#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include "Poligono.h"


/*
	Classe abstrata para servir como "interface" para
		os objetos do jogo.
*/


class Solido
{
    protected:
        //Poligonos que compoe o modelo do solido
        Poligono *poligonos;
        int nPoligonos;

		//Posicao central do solido
		GLfloat posX, posY;

		//Dimensoes X e Y do solido
		GLfloat tamX, tamY;

	public:
        //Evita erros de segmentacao
        Solido();

		//Limpa memoria alocada dinamicamente
		~Solido();

		//Retorna true caso solido tenha sido destruido, false caso contrario
		virtual bool destruido() = 0;

		//Desenha o solido na tela
        void desenha();

		//Define as acoes do solido
		//	(movimento, destruicao, ...)
		virtual void acao() = 0;

		//Getters
		GLfloat getX() { return posX; }
		GLfloat getY() { return posY; }
		GLfloat getTamX() { return tamX; }
		GLfloat getTamY() { return tamY; }

};




#endif