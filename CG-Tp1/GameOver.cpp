#define _CRT_SECURE_NO_WARNINGS
#include "GameOver.hpp"
#include <AntTweakBar.h>
GameOver::GameOver()
{
}

GameOver::~GameOver()
{
}

void GameOver::definePersonagens()
{
}

void GameOver::desenhaBackground()
{
}

void GameOver::writeScore(int score)
{
}

void GameOver::desenha()
{

	glClearColor(0.5f, 0.5f, 0.6f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	// App drawing here
	// ...

	// Draw tweak bars
	TwDraw();

	// Present frame buffer
	glutSwapBuffers();
}

void GameOver::terminou()
{
	TwTerminate();
}

void GameOver::atualiza(int value)
{
}

void GameOver::mouse(int button, int state, int x, int y)
{	
		// send event to AntTweakBar
		if (TwEventMouseMotionGLUT(x, y))
			glutPostRedisplay(); // request redraw if event has been handled
	
}

void GameOver::keyDown(unsigned char key, int x, int y)
{
	if (TwEventKeyboardGLUT(key, x, y))
		glutPostRedisplay(); // request redraw if event has been handled
}

void GameOver::keyUp(unsigned char key, int x, int y)
{
	if (TwEventKeyboardGLUT(key, x, y))
		glutPostRedisplay(); // request redraw if event has been handled
}

void GameOver::specialKeyDown(int key, int x, int y)
{
	if (TwEventSpecialGLUT(key, x, y))
		glutPostRedisplay();
}

void GameOver::specialKeyUp(int key, int x, int y)
{
	if (TwEventSpecialGLUT(key, x, y))
		glutPostRedisplay();
}

void GameOver::inicializa()
{
	
}
