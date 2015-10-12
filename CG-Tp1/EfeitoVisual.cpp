#include "EfeitoVisual.hpp"
#include <cmath>
#define FULLHD_ORTHO_X 1920
#define FULLHD_ORTHO_Y 1080


EfeitoVisual::EfeitoVisual()
{
	fullscreen = false;
	sizeX = 1280;
	sizeY = 720;
}

EfeitoVisual::~EfeitoVisual()
{
}

void EfeitoVisual::ortho2D()
{
	gluOrtho2D(0.0f, FULLHD_ORTHO_X, 0.0f, FULLHD_ORTHO_Y);
}

pair<float, float> EfeitoVisual::getOrtho2D()
{
	return pair<float, float>(FULLHD_ORTHO_X, FULLHD_ORTHO_Y);
}

bool EfeitoVisual::colisao(Solido *a, Solido *b)
{
	if ((abs(a->getX() - b->getX()) <= (a->getTamX() + b->getTamX()) / 2) ||
		(abs(a->getY() - b->getY()) <= (a->getTamY() + b->getTamY()) / 2))
		return true;
	return false;
}

void EfeitoVisual::resize(GLsizei w, GLsizei h)
{
	// Especifica as dimensões da Viewport
	if (w * 9 / 16 < h)
		glViewport(0, 0, w, w * 9 / 16);
	else
		glViewport(0, 0, h * 16 / 9, h);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	EfeitoVisual::getInstance().sizeX = w;
	EfeitoVisual::getInstance().sizeY = h;
}

bool EfeitoVisual::isFullScreen()
{
	return fullscreen;
}

pair<int, int> EfeitoVisual::sizeScreen()
{
	return pair<int, int>(sizeX, sizeY);
}

pair<double, double> EfeitoVisual::positionScreen(char * type)
{
	pair<double, double> val;
	if (type == "center") {
		val.first = ((GetSystemMetrics(SM_CXSCREEN) - sizeScreen().first) / 2);
		val.second = ((GetSystemMetrics(SM_CYSCREEN) - sizeScreen().second) / 2);
	}
	return val;
}

void EfeitoVisual::setFullScreen()
{
	if (!fullscreen) {
		glutFullScreen();
	}
	else {
		//Default values
		sizeX = 1280;
		sizeY = 720;
		glutReshapeWindow(sizeX, sizeY);
		pair<int, int> position = positionScreen("center");
		glutInitWindowPosition(position.first, position.second);
	}
	fullscreen = !fullscreen;
}

void EfeitoVisual::desenhaEstrelas(int quantEstrelas) {

	srand((unsigned)time(NULL));
	float posRand = 0, posRandY = 0;

	glPointSize(5);
	glColor4f(0.5, 0.5,0.5, 0.15);

	
	while (quantEstrelas > 0) {
		posRand = rand() / 10 ;
		posRandY = rand() / 10;
		glBegin(GL_POINTS);
		glVertex2f(posRand, posRandY);
		glEnd();

		quantEstrelas--;
	}

}

EfeitoVisual& EfeitoVisual::getInstance()
{
	static EfeitoVisual singleton;
	return singleton;
}
