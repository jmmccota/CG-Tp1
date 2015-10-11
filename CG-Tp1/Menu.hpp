#ifndef MENU_FASE
#define MENU_FASE

#include "Fase.hpp"
#include "Score.hpp"
#include "EfeitoSonoro.hpp"
#include "EfeitoVisual.hpp"
#include <gl/glut.h>
#include <cstring>
#include <string>
#include <iostream>
#include "Avioes.hpp"

#ifdef FASE

using namespace std;

class Menu : public Fase
{
protected:
	// Tamanho e posição inicial do quadrado 
	GLfloat posX1 = 100.0f;
	GLfloat PosY1 = 150.0f;
	GLsizei POSrsize = 50;

	// Tamanho do incremento nas direções x e y 
	// (número de pixels para se mover a cada
	// intervalo de tempo)
	GLfloat xstep = 1.0f;
	GLfloat ystep = 1.0f;

	// Largura e altura da janela
	GLfloat windowWidth;
	GLfloat windowHeight;

	bool optIniciar = false;
	bool optMelhores = false;
	bool optOpcoes = false;
	bool optSair = false;


public:
	Menu();
	~Menu();

	void definePersonagens();

	void desenhaBackground();

	// Função callback chamada para fazer o desenho
	void desenha();

	void terminou();

	// Função callback chamada pela GLUT a cada intervalo de tempo
	// (a window não está sendo redimensionada ou movida)
	void atualiza(int value);

	//Clique do mouse
	void mouse(int button, int state, int x, int y);
	void keyDown(unsigned char key, int x, int y);
	void keyUp(unsigned char key, int x, int y);

	// Inicializa parâmetros de rendering
	void inicializa();
};

#endif

#endif
