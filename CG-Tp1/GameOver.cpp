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
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void GameOver::writeScore(int score)
{
}

void GameOver::desenha()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.05, 0.05, 0.05, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	desenhaBackground();

	EfeitoVisual::getInstance().ortho2D();	
		//se gameOver true escreve grande na tela game over se fudeu etc
	desenhaGameOver();
		//se gameOver false escreve you win voce é fodão	
	
	if (melhorScore) {
		desenhaScore();
		//coloca no meio da tela o quadradim pra digitar
	}
	// App drawing here
	// ...

	// Draw tweak bars
	

	// Present frame buffer
	glutSwapBuffers();
}

void GameOver::terminou()
{	
}

void GameOver::atualiza(int value)
{
	desenha();
}

void GameOver::mouse(int button, int state, int x, int y)
{	
		// send event to AntTweakBar
		
	
}

void GameOver::keyDown(unsigned char key, int x, int y)
{
	
		
}

void GameOver::keyUp(unsigned char key, int x, int y)
{
	string aux;
	switch (key) {
	case 13:
		//enter salvar

	case 8:

		if (nome.length() > 0) {
			for (int i = 0; i < nome.length() - 1; i++) {
				aux += nome[i];
			}
			nome = aux;
		}
		break;
	}
	if (nome.length()<20) {
		switch (key) {
		case 'a': //
		case 'A':
			nome += "A";
			break;
		case 'b': //
		case 'B':
			nome += "B";
			break;
		case 'c': //
		case 'C':
			nome += "C";
			break;
		case 'd': //
		case 'D':
			nome += "D";
			break;
		case 'e': //
		case 'E':
			nome += "E";
			break;
		case 'f': //
		case 'F':
			nome += "F";
			break;
		case 'g': //
		case 'G':
			nome += "G";
			break;
		case 'h': //
		case 'H':
			nome += "H";
			break;
		case 'i': //
		case 'I':
			nome += "I";
			break;
		case 'j': //
		case 'J':
			nome += "J";
			break;
		case 'k': //
		case 'K':
			nome += "K";
			break;
		case 'l': //
		case 'L':
			nome += "L";
			break;
		case 'M': //
		case 'm':
			nome += "M";
			break;
		case 'n': //
		case 'N':
			nome += "N";
			break;
		case 'o': //
		case 'O':
			nome += "O";
			break;
		case 'p': //
		case 'P':
			nome += "P";
			break;
		case 'q': //
		case 'Q':
			nome += "Q";
			break;
		case 'r': //
		case 'R':
			nome += "R";
			break;
		case 's': //
		case 'S':
			nome += "S";
			break;
		case 't': //
		case 'T':
			nome += "T";
			break;
		case 'u': //
		case 'U':
			nome += "U";
			break;
		case 'V': //
		case 'v':
			nome += "V";
			break;
		case 'x': //
		case 'X':
			nome += "X";
			break;
		case 'y': //
		case 'Y':
			nome += "Y";
			break;
		case 'w': //
		case 'W':
			nome += "W";
			break;
		case 'z': //
		case 'Z':
			nome += "Z";
			break;
		}
	}
}

void GameOver::specialKeyDown(int key, int x, int y)
{
	
}

void GameOver::specialKeyUp(int key, int x, int y)
{
	

}
void GameOver::desenhaGameOver() {
		
	int x=500, y;	
	if (melhorScore) {
		y = 1000;
	}
	else {
		y = 600;
	}
	if (gameOver) {		
		//G
		desenhaQuadrado(x-10,y+10,x+60,y-20); 
		desenhaQuadrado(x-10, y, x+20, y - 120);
		desenhaQuadrado(x+10, y -100, x + 70, y - 120);
		desenhaQuadrado(x+50, y - 100, x + 70, y - 60);
		desenhaQuadrado(x + 40, y - 60, x + 70, y - 50);		
		//A
		desenhaQuadrado(x +85, y-10, x + 115, y - 120);
		desenhaQuadrado(x + 85, y - 20, x + 180, y +10);
		desenhaQuadrado(x + 150, y +10, x + 180, y - 120);
		desenhaQuadrado(x + 85, y-60, x + 180, y - 50);
		//M
		desenhaQuadrado(x + 195, y+10, x + 225, y - 120);
		desenhaQuadrado(x + 265, y + 10, x + 295, y - 120);
		desenhaQuadrado(x + 225, y -30, x + 235, y - 40);
		desenhaQuadrado(x + 255, y - 30, x + 265, y - 40);
		desenhaQuadrado(x + 235, y - 40, x + 255, y - 60);
		//E
		desenhaQuadrado(x + 315, y + 10, x + 345, y - 120);
		desenhaQuadrado(x + 315, y + 10, x + 405, y - 10);
		desenhaQuadrado(x + 315, y -50, x + 395, y - 60);
		desenhaQuadrado(x + 315, y - 100, x + 405, y - 120);
		//O
		desenhaQuadrado(x + 455, y + 10, x + 485, y - 120);
		desenhaQuadrado(x + 525, y + 10, x + 555, y - 120);
		desenhaQuadrado(x + 455, y + 10, x + 555, y - 10);
		desenhaQuadrado(x + 455, y - 100, x + 555, y - 120);
		//V
		desenhaQuadrado(x + 575, y + 10, x + 605, y - 80);
		desenhaQuadrado(x + 645, y + 10, x + 675, y - 80);
		desenhaQuadrado(x + 585, y - 80, x + 665, y - 95);
		desenhaQuadrado(x + 595, y - 95, x + 655, y - 105);
		desenhaQuadrado(x + 605, y - 95, x + 645, y - 120);
		//E
		desenhaQuadrado(x + 695, y + 10, x + 725, y - 120);
		desenhaQuadrado(x + 695, y + 10, x + 785, y - 10);
		desenhaQuadrado(x + 695, y - 50, x + 775, y - 60);
		desenhaQuadrado(x + 695, y - 100, x + 785, y - 120);
		//R
		desenhaQuadrado(x + 805, y + 10, x + 835, y - 120);
		desenhaQuadrado(x + 805, y + 10, x + 895, y - 10);
		desenhaQuadrado(x + 875, y + 10, x + 895, y - 70);
		desenhaQuadrado(x + 805, y - 50, x + 895, y - 70);
		glBegin(GL_QUADS);
		glVertex2i(x + 835, y - 70);
		glVertex2i(x + 865, y - 70);
		glVertex2i(x + 895, y - 120);
		glVertex2i(x + 865, y - 120);
		glEnd();

		
	}	
	
}
void GameOver::desenhaQuadrado(int x,int y,int x1,int y1) {
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex2i(x, y);
	glVertex2i(x1, y);
	glVertex2i(x1, y1);
	glVertex2i(x, y1);
	glEnd();
}
void GameOver::desenhaScore() {
	glBegin(GL_LINE_LOOP);
	glColor3f(1,1,1);
	glVertex2i(650,700);
	glVertex2i(1240, 700);
	glVertex2i(1240, 450);
	glVertex2i(650, 450);
	glEnd();	
	int score = 1990;
	string recorde = "NOVO RECORDE! SCORE: ";
	recorde += score;
	glRasterPos2f(660, 650);
	FuncoesAuxiliares::writeWord_BITMAP(recorde,GLUT_BITMAP_TIMES_ROMAN_24);
	glRasterPos2f(660, 565);
	FuncoesAuxiliares::writeWord_BITMAP("Nome: ", GLUT_BITMAP_TIMES_ROMAN_24);	
	glBegin(GL_LINE_LOOP);
	glVertex2i(770, 600);
	glVertex2i(1200, 600);
	glVertex2i(1200, 550);
	glVertex2i(770, 550);
	glEnd();
	glRasterPos2f(780, 565);	
	cout << nome.length();
	FuncoesAuxiliares::writeWord_BITMAP(nome, GLUT_BITMAP_HELVETICA_18);
	glBegin(GL_LINE_LOOP);
	glVertex2i(1080, 530);
	glVertex2i(1200, 530);
	glVertex2i(1200, 480);
	glVertex2i(1080, 480);
	glEnd();
	glRasterPos2f(1095, 490);
	FuncoesAuxiliares::writeWord_BITMAP("Salvar", GLUT_BITMAP_TIMES_ROMAN_24);
}
void GameOver::inicializa()
{
	desenha();
}
