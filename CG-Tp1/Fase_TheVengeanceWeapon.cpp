#include "Fase_TheVengeanceWeapon.hpp"

Fase_TheVengeanceWeapon::Fase_TheVengeanceWeapon()
{
}

Fase_TheVengeanceWeapon::~Fase_TheVengeanceWeapon()
{
}

void Fase_TheVengeanceWeapon::definePersonagens()
{
}

void Fase_TheVengeanceWeapon::desenhaBackground()
{
}

void Fase_TheVengeanceWeapon::desenha()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers();
}

void Fase_TheVengeanceWeapon::terminou()
{
}

void Fase_TheVengeanceWeapon::atualiza(int value)
{
}

void Fase_TheVengeanceWeapon::mouse(int button, int state, int x, int y)
{
}

void Fase_TheVengeanceWeapon::keyDown(unsigned char key, int x, int y)
{
}

void Fase_TheVengeanceWeapon::keyUp(unsigned char key, int x, int y)
{
}

void Fase_TheVengeanceWeapon::specialKeyDown(int key, int x, int y)
{
}

void Fase_TheVengeanceWeapon::specialKeyUp(int key, int x, int y)
{
}

void Fase_TheVengeanceWeapon::inicializa()
{
	EfeitoSonoro::getInstance().playThirdFaseTheme();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
