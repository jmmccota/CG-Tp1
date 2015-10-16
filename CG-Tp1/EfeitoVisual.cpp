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

pair<GLfloat, GLfloat> EfeitoVisual::getOrtho2D()
{
	return pair<GLfloat, GLfloat>(FULLHD_ORTHO_X, FULLHD_ORTHO_Y);
}

bool EfeitoVisual::colisao(Solido *a, Solido *b)
{
	if ((abs(a->getX() - b->getX()) <= (a->getTamX() + b->getTamX()) / 2) &&
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

pair<GLint, GLint> EfeitoVisual::sizeScreen()
{
	return pair<GLint, GLint>(sizeX, sizeY);
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

void EfeitoVisual::desenhaTitulo(int posX, int posY)
{

	glColor3f(0, 1.0, 1.0);
	int x1 = 100 + posX, y1 = 100 + posY;

	//J
	FuncoesAuxiliares::bresenham(x1, 750 + y1 + 80, x1, 660 + y1); //  |
	FuncoesAuxiliares::bresenham(x1 - 100, 660 + y1, x1, 660 + y1); // _
	FuncoesAuxiliares::bresenham(x1 - 100, 660 + y1, x1, 660 + y1); // _
	FuncoesAuxiliares::bresenham(x1 - 100, 660 + y1, x1 - 100, 698 + y1); //i 
	FuncoesAuxiliares::bresenham(x1 - 100, 698 + y1, x1 - 70, 698 + y1);//-
	FuncoesAuxiliares::bresenham(x1 - 70, 698 + y1, x1 - 70, 680 + y1);//'
	FuncoesAuxiliares::bresenham(x1 - 70, 680 + y1, x1 - 28, 680 + y1);//---
	FuncoesAuxiliares::bresenham(x1 - 28, 680 + y1, x1 - 28, 750 + y1 + 80);// I
	FuncoesAuxiliares::bresenham(x1 - 28, 750 + y1 + 80, x1, 750 + y1 + 80); //-

	//I
	FuncoesAuxiliares::bresenham(x1 + 15, 750 + y1 + 80, x1 + 15, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 45, 660 + y1, x1 + 15, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 45, 660 + y1, x1 + 45, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(x1 + 45, 750 + y1 + 80, x1 + 15, 750 + y1 + 80);

	//R
	x1 += 15;
	FuncoesAuxiliares::bresenham(x1 + 45, 750 + y1 + 80, x1 + 45, 660 + y1); //|
	FuncoesAuxiliares::bresenham(x1 + 45, 750 + y1 + 80, x1 + 145, 750 + y1 + 80);//- em cima
	FuncoesAuxiliares::bresenham(x1 + 145, 750 + y1 + 80, x1 + 145, 700 + y1 + 30);// ' ate o meio
	FuncoesAuxiliares::bresenham(x1 + 145, 700 + y1 + 30, x1 + 70, 700 + y1 + 30);// - ate o meio do R
	FuncoesAuxiliares::bresenham(x1 + 70, 700 + y1 + 30, x1 + 145, 660 + y1);// \ate o fim do r
	FuncoesAuxiliares::bresenham(x1 + 145, 660 + y1, x1 + 115, 660 + y1);//
	FuncoesAuxiliares::bresenham(x1 + 70, 695 + y1 + 10, x1 + 115, 660 + y1);//
	FuncoesAuxiliares::bresenham(x1 + 70, 695 + y1 + 10, x1 + 70, 660 + y1);//
	FuncoesAuxiliares::bresenham(x1 + 70, 660 + y1, x1 + 45, 660 + y1);//
	FuncoesAuxiliares::bresenham(x1 + 75 + 5, 715 + y1 + 40, x1 + 112, 715 + y1 + 40);//quadradinho
	FuncoesAuxiliares::bresenham(x1 + 112, 715 + y1 + 40, x1 + 112, 740 + y1 + 50);//
	FuncoesAuxiliares::bresenham(x1 + 112, 740 + y1 + 50, x1 + 75 + 5, 740 + y1 + 50);//
	FuncoesAuxiliares::bresenham(x1 + 75 + 5, 740 + y1 + 50, x1 + 75 + 5, 715 + y1 + 40);//
																							 //A
	//A
	x1 += 50;
	FuncoesAuxiliares::bresenham(x1 + 110, 750 + y1 + 80, x1 + 110, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 110, 750 + y1 + 80, x1 + 220, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(x1 + 220, 750 + y1 + 80, x1 + 220, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 220, 660 + y1, x1 + 193, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 193, 660 + y1, x1 + 193, 700 + y1 + 30);
	FuncoesAuxiliares::bresenham(x1 + 110, 660 + y1, x1 + 142, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 142, 700 + y1 + 30, x1 + 142, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 142, 700 + y1 + 30, x1 + 193, 700 + y1 + 30);
	FuncoesAuxiliares::bresenham(x1 + 142, 715 + y1 + 45, x1 + 193, 715 + y1 + 45);//quadradinho
	FuncoesAuxiliares::bresenham(x1 + 142, 715 + y1 + 45, x1 + 142, 735 + y1 + 60);
	FuncoesAuxiliares::bresenham(x1 + 142, 735 + y1 + 60, x1 + 193, 735 + y1 + 60);
	FuncoesAuxiliares::bresenham(x1 + 193, 715 + y1 + 45, x1 + 193, 735 + y1 + 60);

	//Y
	x1 += 65;
	FuncoesAuxiliares::bresenham(x1 + 175, 660 + y1, x1 + 190 + 20, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 190 + 20, 660 + y1, x1 + 280, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(x1 + 280, 750 + y1 + 80, x1 + 245, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(x1 + 175, 660 + y1, x1 + 193, 705 + y1);
	FuncoesAuxiliares::bresenham(x1 + 193, 705 + y1, x1 + 170, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(x1 + 170, 750 + y1 + 80, x1 + 195, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(x1 + 195, 750 + y1 + 80, x1 + 213, 718 + y1 + 35);
	FuncoesAuxiliares::bresenham(x1 + 213, 718 + y1 + 35, x1 + 245, 750 + y1 + 80);

	//A
	x1 += 185;
	FuncoesAuxiliares::bresenham(x1 + 110, 750 + y1 + 80, x1 + 110, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 110, 750 + y1 + 80, x1 + 220, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(x1 + 220, 750 + y1 + 80, x1 + 220, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 220, 660 + y1, x1 + 193, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 193, 660 + y1, x1 + 193, 700 + y1 + 30);
	FuncoesAuxiliares::bresenham(x1 + 110, 660 + y1, x1 + 142, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 142, 700 + y1 + 30, x1 + 142, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 142, 700 + y1 + 30, x1 + 193, 700 + y1 + 30);
	FuncoesAuxiliares::bresenham(x1 + 142, 715 + y1 + 45, x1 + 193, 715 + y1 + 45);//quadradinho
	FuncoesAuxiliares::bresenham(x1 + 142, 715 + y1 + 45, x1 + 142, 735 + y1 + 60);
	FuncoesAuxiliares::bresenham(x1 + 142, 735 + y1 + 60, x1 + 193, 735 + y1 + 60);
	FuncoesAuxiliares::bresenham(x1 + 193, 715 + y1 + 45, x1 + 193, 735 + y1 + 60);

	//'
	x1 += 15;
	FuncoesAuxiliares::bresenham(x1 + 220, 750 + y1 + 80, x1 + 220, 720 + y1 + 70);
	FuncoesAuxiliares::bresenham(x1 + 220, 750 + y1 + 80, x1 + 245, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(x1 + 220, 720 + y1 + 70, x1 + 245, 750 + y1 + 80);

	//s
	x1 -= 75;
	FuncoesAuxiliares::bresenham(x1 + 300, 718 + y1 + 30, x1 + 355, 718 + y1 + 30);
	FuncoesAuxiliares::bresenham(x1 + 355, 718 + y1 + 30, x1 + 355, 703 + y1 + 25);
	FuncoesAuxiliares::bresenham(x1 + 315, 703 + y1 + 25, x1 + 355, 703 + y1 + 25);
	FuncoesAuxiliares::bresenham(x1 + 300, 718 + y1 + 30, x1 + 300, 683 + y1 + 15);
	FuncoesAuxiliares::bresenham(x1 + 315, 703 + y1 + 25, x1 + 315, 695 + y1 + 15);
	FuncoesAuxiliares::bresenham(x1 + 355, 695 + y1 + 15, x1 + 315, 695 + y1 + 15);
	FuncoesAuxiliares::bresenham(x1 + 355, 695 + y1 + 15, x1 + 355, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 355, 660 + y1, x1 + 300, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 300, 671 + y1, x1 + 300, 660 + y1);
	FuncoesAuxiliares::bresenham(x1 + 300, 671 + y1, x1 + 340, 671 + y1);
	FuncoesAuxiliares::bresenham(x1 + 340, 683 + y1 + 15, x1 + 340, 671 + y1);
	FuncoesAuxiliares::bresenham(x1 + 300, 683 + y1 + 15, x1 + 340, 683 + y1 + 15);

	//fly	
	//f
	int y2 = -40 + posY;
	x1 = 103 + posX;
	FuncoesAuxiliares::bresenham(x1 + 160, 635 + y2, x1 + 160, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 160, 730 + y2, x1 + 220, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 220, 730 + y2, x1 + 220, 705 + y2);
	FuncoesAuxiliares::bresenham(x1 + 220, 705 + y2, x1 + 180, 705 + y2);
	FuncoesAuxiliares::bresenham(x1 + 180, 705 + y2, x1 + 180, 685 + y2);
	FuncoesAuxiliares::bresenham(x1 + 180, 685 + y2, x1 + 200, 685 + y2);
	FuncoesAuxiliares::bresenham(x1 + 200, 685 + y2, x1 + 200, 665 + y2);
	FuncoesAuxiliares::bresenham(x1 + 200, 665 + y2, x1 + 180, 665 + y2);
	FuncoesAuxiliares::bresenham(x1 + 180, 665 + y2, x1 + 180, 635 + y2);
	FuncoesAuxiliares::bresenham(x1 + 160, 635 + y2, x1 + 180, 635 + y2);

	//l
	FuncoesAuxiliares::bresenham(x1 + 230, 635 + y2, x1 + 230, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 230, 635 + y2, x1 + 275, 635 + y2);
	FuncoesAuxiliares::bresenham(x1 + 275, 635 + y2, x1 + 275, 655 + y2);
	FuncoesAuxiliares::bresenham(x1 + 275, 655 + y2, x1 + 250, 655 + y2);
	FuncoesAuxiliares::bresenham(x1 + 250, 655 + y2, x1 + 250, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 230, 730 + y2, x1 + 250, 730 + y2);

	//y
	x1 += 115;
	FuncoesAuxiliares::bresenham(x1 + 175, 635 + y2, x1 + 195, 635 + y2);
	FuncoesAuxiliares::bresenham(x1 + 195, 635 + y2, x1 + 230, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 230, 730 + y2, x1 + 210, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 175, 635 + y2, x1 + 193, 680 + y2);
	FuncoesAuxiliares::bresenham(x1 + 193, 680 + y2, x1 + 165, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 165, 730 + y2, x1 + 180, 730 + y2);
	FuncoesAuxiliares::bresenham(x1 + 180, 730 + y2, x1 + 198, 698 + y2);
	FuncoesAuxiliares::bresenham(x1 + 198, 698 + y2, x1 + 210, 730 + y2);

	//Circulos com Bresenham
	glColor3f(1.0, 1.0, 0.0); //amarelo
	FuncoesAuxiliares::bresenhamCircle(620 + posX, 650 + posY, 90, 90);
	glColor3f(0, 0.0, 0.8);
	FuncoesAuxiliares::bresenhamCircle(620 + posX, 650 + posY, 80, 80);
	glColor3f(1.0, 1.0, 1.0);
	FuncoesAuxiliares::bresenhamCircle(620 + posX, 650 + posY, 40, 40);
	glColor3f(1.0, 0.0, 0.0);
	FuncoesAuxiliares::bresenhamCircle(620 + posX, 650 + posY, 30, 30);

	//katana
	int xk = 540 + posX;
	int yk = 50 + posY;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(-20 + xk, yk + 518);
	glVertex2i(-10 + xk, yk + 498);
	glVertex2i(20 + xk, yk + 528);
	glVertex2i(10 + xk, yk + 548);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(-19 + xk, yk + 518);
	glVertex2i(-11 + xk, yk + 498);
	glVertex2i(19 + xk, yk + 528);
	glVertex2i(11 + xk, yk + 548);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	FuncoesAuxiliares::bresenhamCircle(-8 + xk, yk + 515, 2, 2);
	FuncoesAuxiliares::bresenhamCircle(7 + xk, yk + 530, 2, 2);
	glBegin(GL_LINE_LOOP);
	glVertex2i(27 + xk, yk + 521);
	glVertex2i(7 + xk, yk + 558);
	glVertex2i(14 + xk, yk + 565);
	glVertex2i(35 + xk, yk + 525);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(16 + xk, yk + 521);
	glVertex2i(8 + xk, yk + 558);
	glVertex2i(15 + xk, yk + 565);
	glVertex2i(34 + xk, yk + 525);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(28 + xk, yk + 537);
	glVertex2i(170 + xk, yk + 669);
	glVertex2i(170 + xk, yk + 695);
	glVertex2i(18 + xk, yk + 552);
	glEnd();


	//Circulos com Bresenham
	glColor3f(1.0, 1.0, 0.0); //amarelo
	FuncoesAuxiliares::bresenhamCircle(90 + posX, 650 + posY, 90, 90);
	glColor3f(0, 0.0, 0.8);
	FuncoesAuxiliares::bresenhamCircle(90 + posX, 650 + posY, 80, 80);
	glColor3f(1.0, 1.0, 1.0);
	FuncoesAuxiliares::bresenhamCircle(90 + posX, 650 + posY, 40, 40);
	glColor3f(1.0, 0.0, 0.0);
	FuncoesAuxiliares::bresenhamCircle(90 + posX, 650 + posY, 30, 30);

	//katana
	xk = 170 + posX;
	yk = 50 + posY;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(20 + xk, yk + 518);
	glVertex2i(10 + xk, yk + 498);
	glVertex2i(-20 + xk, yk + 528);
	glVertex2i(-10 + xk, yk + 548);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(19 + xk, yk + 518);
	glVertex2i(11 + xk, yk + 498);
	glVertex2i(-19 + xk, yk + 528);
	glVertex2i(-11 + xk, yk + 548);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	FuncoesAuxiliares::bresenhamCircle(8 + xk, yk + 515, 2, 2);
	FuncoesAuxiliares::bresenhamCircle(-7 + xk, yk + 530, 2, 2);
	glBegin(GL_LINE_LOOP);
	glVertex2i(-27 + xk, yk + 521);
	glVertex2i(-7 + xk, yk + 558);
	glVertex2i(-14 + xk, yk + 565);
	glVertex2i(-35 + xk, yk + 525);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(-16 + xk, yk + 521);
	glVertex2i(-8 + xk, yk + 558);
	glVertex2i(-15 + xk, yk + 565);
	glVertex2i(-34 + xk, yk + 525);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(-28 + xk, yk + 537);
	glVertex2i(-170 + xk, yk + 669);
	glVertex2i(-170 + xk, yk + 695);
	glVertex2i(-18 + xk, yk + 552);
	glEnd();
}

bool EfeitoVisual::desenhaExplosao(float escalaFinal, float posX, float posY)
{
	cout << "Ta entrando";
	bool isFinish = false;
	if (this->escalaAnimacao == 0) {
		EfeitoSonoro::getInstance().playStreamAudio("audio/sfx/boom.mp3");
	}
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glTranslatef(posX, 0, 0);
	if (this->escalaAnimacao < escalaFinal) {
		this->escalaAnimacao += 0.3;
	}
	else {
		this->escalaAnimacao = 0;
		isFinish = true;
	}
	glScalef(this->escalaAnimacao, this->escalaAnimacao, this->escalaAnimacao);
	/*glScalef(escalaFinal, escalaFinal, escalaFinal);*/
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(-10, 10);
	glVertex2f(10, 10);
	glVertex2f(10, -10);
	glVertex2f(-10, -10);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(15, 0);
	glVertex2f(0, 15);
	glVertex2f(-15, 0);
	glVertex2f(0, -15);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(-5, 5);
	glVertex2f(5, 5);
	glVertex2f(5, -5);
	glVertex2f(-5, -5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(7.5, 0);
	glVertex2f(0, 7.5);
	glVertex2f(-7.5, 0);
	glVertex2f(0, -7.5);
	glEnd();
	glPopMatrix();

	return isFinish;
}


EfeitoVisual& EfeitoVisual::getInstance()
{
	static EfeitoVisual singleton;
	return singleton;
}
