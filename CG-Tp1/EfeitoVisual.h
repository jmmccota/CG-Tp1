#ifndef EFEITOVISUAL_H
#define EFEITOVISUAL_H

class EfeitoVisual;

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include "Solido.h"
#include "Spitfire.h"
#include "Bf109.h"
#include "EfeitoSonoro.h"

/*
	Classe usada para efeitos visuais
		(deteccao de colisao, explosoes, ...)
*/


class EfeitoVisual
{
protected:
	bool fullScreen = false;
	const int sizeX = 1280;
	const int sizeY = 720;
public:
	EfeitoVisual();
	~EfeitoVisual();

	//COMO FAZER ANIMACAO EXPLOSAO?
	//void static Explosao(GLfloat x, GLfloat y, GLfloat raio, int estagio);

	//Retorna true caso objetos tenham colidido, false caso contrario
	bool static Colisao(Solido *a, Solido *b);

	//Retorna se a tela está em fullScreen ou não
	bool IsFullScreen();

	//Retorna a resolução padrão da Tela
	pair<int, int> sizeScreen();

	//Posição da tela
	pair<double, double> positionScreen(char *type);

	//Metodo de pressionamento de teclas
	void Teclas(unsigned char tecla, GLint x, GLint y);

	//Animação Incial
	void DisplayAnimacaoInicial();
	void TimerAnimacaoInicial(int value, void(*func)(int));

};
#endif