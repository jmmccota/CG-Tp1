#ifndef EFEITOVISUAL_H
#define EFEITOVISUAL_H

class EfeitoVisual;

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include "Solido.hpp"
#include "Avioes.hpp"
#include "EfeitoSonoro.hpp"

/*
	===============SINGLETON===============
	Somente uma instancia vai ser usada no programa todo.
	Como usar:
		EfeitoVisual v = EfeitoVisual::getInstance();
		v-> ...
		...


	Classe usada para efeitos visuais
		(deteccao de colisao, explosoes, ...)
*/


class EfeitoVisual
{
	private:

		bool fullscreen;
		int sizeX;
		int sizeY;
		EfeitoVisual();
		EfeitoVisual(EfeitoVisual const&);
		void operator=(EfeitoVisual const&);

	public:
		~EfeitoVisual();

		//Funcoes de configuracoes basicas
		void ortho2D();

		//COMO FAZER ANIMACAO EXPLOSAO?
		//void static Explosao(GLfloat x, GLfloat y, GLfloat raio, int estagio);

		//Retorna true caso objetos tenham colidido, false caso contrario
		bool colisao(Solido *a, Solido *b);

		//Reajusta o tamanho da tela
		void resize(GLsizei w, GLsizei h);

		//Retorna se a tela est� em fullScreen ou n�o
		bool isFullScreen();

		//Retorna a resolu��o padr�o da Tela
		pair<int, int> sizeScreen();

		//Posi��o da tela
		pair<double, double> positionScreen(char *type);

		//Metodo de pressionamento de teclas
		void setFullScreen();

		//Anima��o Incial
		void displayAnimacaoInicial();
		void timerAnimacaoInicial(int value, void(*func)(int));

		static EfeitoVisual& getInstance()
		{
			static EfeitoVisual singleton;
			return singleton;
		}
};
#endif
 