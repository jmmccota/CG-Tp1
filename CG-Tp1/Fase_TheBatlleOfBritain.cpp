#include "Fase_TheBatlleOfBritain.hpp"

Fase_TheBatlleOfBritain::Fase_TheBatlleOfBritain()
{
}

Fase_TheBatlleOfBritain::~Fase_TheBatlleOfBritain()
{
}

void Fase_TheBatlleOfBritain::definePersonagens()
{
}

void Fase_TheBatlleOfBritain::desenhaBackground()
{
}

void Fase_TheBatlleOfBritain::desenha()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers();
}

void Fase_TheBatlleOfBritain::terminou()
{
}

void Fase_TheBatlleOfBritain::atualiza(int value)
{
}

void Fase_TheBatlleOfBritain::mouse(int button, int state, int x, int y)
{
}

void Fase_TheBatlleOfBritain::keyDown(unsigned char key, int x, int y)
{
}

void Fase_TheBatlleOfBritain::keyUp(unsigned char key, int x, int y)
{
}

void Fase_TheBatlleOfBritain::specialKeyDown(int key, int x, int y)
{
}

void Fase_TheBatlleOfBritain::specialKeyUp(int key, int x, int y)
{
}

void Fase_TheBatlleOfBritain::inicializa()
{
	EfeitoSonoro::getInstance().playSecondFaseTheme();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
