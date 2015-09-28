#include <windows.h>
#include <math.h>
#include <gl/glut.h>
#include<iostream>
#include "EfeitoSonoro.h"
using namespace std;

GLfloat escala = 1;
GLfloat rotacaoX1 = 0;
GLfloat rotacaoY1 = 0;
GLfloat rotacaoX2 = 0;
GLfloat rotacaoY2 = 0;
GLfloat translacaoY = 0;
GLint translacaoX = -180;
GLint translacaoX2 = -180;
GLfloat translacaoZ = 0;
bool fullscreen = false;
bool booldesenha = true;
bool explosao = true;



#include "Spitfire.h"
#include "Bf109.h"
#include "TiroSimples.h"

Spitfire *s = new Spitfire(-50, 0, (float)20 / 10000, nullptr);
Bf109 *b = new Bf109(50, 0, (float)20 / 10000, nullptr, nullptr);
TiroSimples *t1 = new TiroSimples(-39.5, 8, (float)2 / 10000);
TiroSimples *t2 = new TiroSimples(-39.5, -8, (float)2 / 10000);


void desenha(void){
	glClear(GL_COLOR_BUFFER_BIT);
	// desenha o primeiro bloco atiraador
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glTranslatef(translacaoX, translacaoY, translacaoZ);
	glRotatef(rotacaoX1, 1, 0, 0);
    glRotatef(rotacaoY1, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    s->desenha();
	glEnd();
	glPopMatrix();

	if (booldesenha == true){
		// desenha a muniçãoo
		glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-100, 100, -100, 100);
		glTranslatef(translacaoX2, 0, 0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
        t1->desenha();
        t2->desenha();
		glPopMatrix();

		// desenha o bloco q recebe o tiro
		glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-100, 100, -100, 100);
		glTranslatef(translacaoX, 0, 0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
        b->desenha();
		glPopMatrix();
	}
	else if(explosao){
		// desenha a explosao
		glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-100, 100, -100, 100);
		glTranslatef(translacaoX2, 0, 0);
		if (escala < 3){
			escala = escala + 0.3;
		}
		else{
			explosao = false;
		}
		glScalef(escala, escala, escala);
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
	}
	glutSwapBuffers();
}

// de tempo em tempo ele desenha
void Timer(int value){
	translacaoX += 2;
	if (booldesenha){

		if (translacaoX >= -20){
			translacaoX2 = translacaoX2 + 8;
		}
		else{
			translacaoX2 += 2;
		}
		//momento em q as balas colidem com o bloco
		if ((translacaoX2 - translacaoX)>78){
			translacaoX2 = translacaoX2 - 30;
			booldesenha = false;
		}
	}
		if (value > 0){
			glutPostRedisplay();
			glutTimerFunc(33, Timer, 1);
		}
}

int main(int argc, char **argv)
{
	EfeitoSonoro ef;
	ef.playOpenSound();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition((GetSystemMetrics(SM_CXSCREEN) - 1280) / 2, (GetSystemMetrics(SM_CYSCREEN) - 720) / 2);
	glutCreateWindow("Jogo");
	glutTimerFunc(33, Timer, 1);
	glutDisplayFunc(desenha);
	glutMainLoop();

	return 0;
}