#include "Fase_TheBattleOfBritain.hpp"

Fase_TheBattleOfBritain::Fase_TheBattleOfBritain()
{
}

Fase_TheBattleOfBritain::~Fase_TheBattleOfBritain()
{
}

void Fase_TheBattleOfBritain::definePersonagens()
{
}

void Fase_TheBattleOfBritain::desenhaBackground()
{
}

void Fase_TheBattleOfBritain::desenha()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers();
}

void Fase_TheBattleOfBritain::terminou()
{
}

void Fase_TheBattleOfBritain::atualiza(int value)
{
}

void Fase_TheBattleOfBritain::mouse(int button, int state, int x, int y)
{
}

void Fase_TheBattleOfBritain::keyDown(unsigned char key, int x, int y)
{
}

void Fase_TheBattleOfBritain::keyUp(unsigned char key, int x, int y)
{
}

void Fase_TheBattleOfBritain::specialKeyDown(int key, int x, int y)
{
}

void Fase_TheBattleOfBritain::specialKeyUp(int key, int x, int y)
{
}

void Fase_TheBattleOfBritain::inicializa()
{
	EfeitoSonoro::getInstance().playSecondLevelTheme();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
