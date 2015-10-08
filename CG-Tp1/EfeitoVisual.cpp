#include "EfeitoVisual.hpp"
#include <cmath>

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
	gluOrtho2D(0, 2000, 0, 2000);
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
	// Evita a divisao por zero
	if (h == 0) h = 1;

	// Especifica as dimensões da Viewport
	if (w < h)
		glViewport(0, 0, w, w);
	else
		glViewport(0, 0, h, h);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	sizeX = w;
	sizeY = h;
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
		glutReshapeWindow(700, 700);
		glutInitWindowPosition((GetSystemMetrics(SM_CXSCREEN) - 700) / 2, (GetSystemMetrics(SM_CYSCREEN) - 700) / 2);
	}
	fullscreen = !fullscreen;
}

//#pragma region "Animação Inicial"
//GLfloat escala = 1;
//GLfloat rotacaoX1 = 0;
//GLfloat rotacaoY1 = 0;
//GLfloat rotacaoX2 = 0;
//GLfloat rotacaoY2 = 0;
//GLfloat translacaoY = 0;
//GLint translacaoX = -180;
//GLint translacaoX2 = -180;
//GLfloat translacaoZ = 0;
//bool fullscreen = false;
//bool booldesenha = true;
//bool explosao = true;
//
//void EfeitoVisual::displayAnimacaoInicial()
//{
//	Spitfire *s = new Spitfire(-45, 0, (float)20 / 10000, nullptr);
//	Bf109 *b = new Bf109(50, 0, (float)20 / 10000, nullptr, nullptr);
//	TiroSimples *t1 = new TiroSimples(-39.5, 8, (float)2 / 10000);
//	TiroSimples *t2 = new TiroSimples(-39.5, -8, (float)2 / 10000);
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	// desenha o primeiro bloco atiraador
//	glPushMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-100, 100, -100, 100);
//	glTranslatef(translacaoX - 45, translacaoY - 45, translacaoZ);
//	glRotatef(rotacaoX1, 1, 0, 0);
//	glRotatef(rotacaoY1, 0, 1, 0);
//	glRotatef(270.0f, 0.0f, 0.0f, 1.0f);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	s->desenha();
//	glPopMatrix();
//
//	if (booldesenha == true) {
//		// desenha a muniçãoo
//		glPushMatrix();
//		glMatrixMode(GL_PROJECTION);
//		glLoadIdentity();
//		gluOrtho2D(-100, 100, -100, 100);
//		glTranslatef(translacaoX2, 0, 0);
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		t1->desenha();
//		t2->desenha();
//		glPopMatrix();
//
//		// desenha o bloco q recebe o tiro
//		glPushMatrix();
//		glMatrixMode(GL_PROJECTION);
//		glLoadIdentity();
//		gluOrtho2D(-100, 100, -100, 100);
//		glTranslatef(translacaoX + 45, 50, 0);
//		glRotatef(270.0f, 0.0f, 0.0f, 1.0f);
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		b->desenha();
//		glPopMatrix();
//	}
//	else if (explosao) {
//		// desenha a explosao
//		
//		glPushMatrix();
//		glMatrixMode(GL_PROJECTION);
//		glLoadIdentity();
//		gluOrtho2D(-100, 100, -100, 100);
//		glTranslatef(translacaoX2, 0, 0);
//		if (escala < 3) {
//			escala = escala + 0.3;
//		}
//		else {
//			explosao = false;
//		}
//		glScalef(escala, escala, escala);
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		glBegin(GL_POLYGON);
//		glColor3f(1, 0, 0);
//		glVertex2f(-10, 10);
//		glVertex2f(10, 10);
//		glVertex2f(10, -10);
//		glVertex2f(-10, -10);
//		glEnd();
//		glBegin(GL_POLYGON);
//		glColor3f(1, 0, 0);
//		glVertex2f(15, 0);
//		glVertex2f(0, 15);
//		glVertex2f(-15, 0);
//		glVertex2f(0, -15);
//		glEnd();
//		glBegin(GL_POLYGON);
//		glColor3f(1, 1, 0);
//		glVertex2f(-5, 5);
//		glVertex2f(5, 5);
//		glVertex2f(5, -5);
//		glVertex2f(-5, -5);
//		glEnd();
//		glBegin(GL_POLYGON);
//		glColor3f(1, 1, 0);
//		glVertex2f(7.5, 0);
//		glVertex2f(0, 7.5);
//		glVertex2f(-7.5, 0);
//		glVertex2f(0, -7.5);
//		glEnd();
//		glPopMatrix();
//	}
//	glutSwapBuffers();
//}
//
//void EfeitoVisual::timerAnimacaoInicial(int value, void(*func)(int))
//{
//	translacaoX += 2;
//	if (booldesenha) {
//
//		if (translacaoX >= -20) {
//			translacaoX2 = translacaoX2 + 8;
//		}
//		else {
//			translacaoX2 += 2;
//		}
//		//momento em q as balas colidem com o bloco
//		if ((translacaoX2 - translacaoX) > 78) {
//			translacaoX2 = translacaoX2 - 30;
//			booldesenha = false;
//		}
//	}
//	if (value > 0) {
//		glutPostRedisplay();
//		glutTimerFunc(3, func, 1);
//	}
//}
//#pragma endregion 
