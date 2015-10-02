#include <windows.h>
#include <math.h>
#include <gl/glut.h>
#include <iostream>
#include "EfeitoSonoro.hpp"
#include "EfeitoVisual.hpp"

using namespace std;

EfeitoVisual *ev = new EfeitoVisual();

void displayA(void) {
	ev->DisplayAnimacaoInicial();
	glFlush();
}

void Timer(int value) {
	ev->TimerAnimacaoInicial(value, Timer);
}

void Keyboard(unsigned char tecla, GLint x, GLint y) {
	ev->Teclas(tecla, x, y);
}


int main(int argc, char **argv)
{

	EfeitoSonoro ef;
	ef.playOpenTheme();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(ev->sizeScreen().first, ev->sizeScreen().second);
	glutInitWindowPosition(ev->positionScreen("center").first, ev->positionScreen("center").second);
	glutCreateWindow("TelaGames:");
	glutTimerFunc(33, Timer, 1);
	glutDisplayFunc(displayA);;
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
	
	return 0;
}