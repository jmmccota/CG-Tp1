#ifndef PROJETIL_ABS
#define PROJETIL_ABS



#include <GL/gl.h>
#include <GL/glut.h>


/*
	Classe abstrata para servir como "interface" para
		os objetos do jogo.
*/


class Solido
{
	protected:
		//Posicao central do solido
		GLfloat posX, posY;

		//Dimensoes X e Y do solido
		GLfloat tamX, tamY;

	public:
		//Limpa memoria alocada dinamicamente
		virtual ~Solido() = 0;

		//Retorna true caso solido tenha sido destruido, false caso contrario
		virtual bool destruido() = 0;

		//Desenha o solido na tela
		virtual void desenha() = 0;

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