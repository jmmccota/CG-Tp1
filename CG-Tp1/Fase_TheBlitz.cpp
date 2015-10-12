#include "Fase_TheBlitz.hpp"

Fase_TheBlitz::Fase_TheBlitz()
{
}

Fase_TheBlitz::~Fase_TheBlitz()
{
}

void Fase_TheBlitz::definePersonagens()
{
}

void Fase_TheBlitz::desenhaBackground()
{
}

void Fase_TheBlitz::desenha()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers();
}

void Fase_TheBlitz::terminou()
{
}

void Fase_TheBlitz::atualiza(int value)
{
}

void Fase_TheBlitz::mouse(int button, int state, int x, int y)
{
}

void Fase_TheBlitz::keyDown(unsigned char key, int x, int y)
{
}

void Fase_TheBlitz::keyUp(unsigned char key, int x, int y)
{
}

void Fase_TheBlitz::specialKeyDown(int key, int x, int y)
{
}

void Fase_TheBlitz::specialKeyUp(int key, int x, int y)
{
}

void Fase_TheBlitz::inicializa()
{
	EfeitoSonoro::getInstance().playFirstLevelTheme();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
