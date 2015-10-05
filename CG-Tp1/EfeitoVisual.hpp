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
	Classe usada para efeitos visuais
		(deteccao de colisao, explosoes, ...)
*/


class EfeitoVisual
{
protected:
	static bool fullscreen;
	static int sizeX;
	static int sizeY;
public:
	EfeitoVisual();
	~EfeitoVisual();

	//Funcoes de configuracoes basicas
	void static inicializa();
	void static ortho2D();

	//COMO FAZER ANIMACAO EXPLOSAO?
	//void static Explosao(GLfloat x, GLfloat y, GLfloat raio, int estagio);

	//Retorna true caso objetos tenham colidido, false caso contrario
	bool static colisao(Solido *a, Solido *b);

	//Reajusta o tamanho da tela
	void static resize(GLsizei w, GLsizei h);

	//Retorna se a tela está em fullScreen ou não
	bool static isFullScreen();

	//Retorna a resolução padrão da Tela
	pair<int, int> static sizeScreen();

	//Posição da tela
	pair<double, double> static positionScreen(char *type);

	//Metodo de pressionamento de teclas
	void static fullScreen();

	//Animação Incial
	void displayAnimacaoInicial();
	void timerAnimacaoInicial(int value, void(*func)(int));
};
#endif
 