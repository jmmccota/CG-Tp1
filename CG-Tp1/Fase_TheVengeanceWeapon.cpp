#include "Fase_TheVengeanceWeapon.hpp"
GLfloat Pontos[16][2];
float variacaoX = 0;
bool variacao = false;
Fase_TheVengeanceWeapon::Fase_TheVengeanceWeapon()
{
}

Fase_TheVengeanceWeapon::~Fase_TheVengeanceWeapon()
{
}

void Fase_TheVengeanceWeapon::definePersonagens()
{
}

void desenha3(float translacaoX, float translacaoY, float escala){
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glScalef(escala, escala, 0);
	glTranslatef(translacaoX + variacaoX, translacaoY, 0);
	glColor3f(1.0, 1.0, 1.0);
	// poligono 1
	glBegin(GL_POLYGON);
	glVertex2i(-40, 15);
	glVertex2i(-30, 25);
	glVertex2i(-20, 15);
	glVertex2i(-20, -15);
	glVertex2i(-30, -25);
	glVertex2i(-40, -15);
	glVertex2i(-40, 15);
	glEnd();
	// poligono 2
	glBegin(GL_POLYGON);
	glVertex2i(-20, 15);
	glVertex2i(-10, 30);
	glVertex2i(0, 15);
	glVertex2i(0, -15);
	glVertex2i(-10, -30);
	glVertex2i(-20, -15);
	glVertex2i(-20, 15);
	glEnd();
	// poligono 3
	glBegin(GL_POLYGON);
	glVertex2i(0, 15);
	glVertex2i(10, 25);
	glVertex2i(20, 15);
	glVertex2i(20, -15);
	glVertex2i(10, -25);
	glVertex2i(0, -15);
	glVertex2i(0, 15);
	glEnd();
	glPopMatrix();
	glFlush();
}

void desenha4(float translacaoX, float translacaoY, float escala){
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glScalef(escala, escala, 0);
	glTranslatef(translacaoX - variacaoX, translacaoY, 0);
	glColor3f(1.0, 1.0, 1.0);
	// poligono 1
	glBegin(GL_POLYGON);
	glVertex2i(-40, 15);
	glVertex2i(-30, 25);
	glVertex2i(-20, 15);
	glVertex2i(-30, -15);
	glVertex2i(-35, -25);
	glVertex2i(-40, -15);
	glVertex2i(-40, 15);
	glEnd();
	// poligono 2
	glBegin(GL_POLYGON);
	glVertex2i(-20, 15);
	glVertex2i(-15, -15);
	glVertex2i(-20, -20);
	glVertex2i(-30, -15);
	glVertex2i(-20, 15);
	glEnd();
	// poligono 3
	glBegin(GL_POLYGON);
	glVertex2i(-20, 15);
	glVertex2i(-10, 35);
	glVertex2i(0, 15);
	glVertex2i(0, -15);
	glVertex2i(-5, -30);
	glVertex2i(-15, -15);
	glVertex2i(-20, 15);
	glEnd();
	// poligono 3
	glBegin(GL_POLYGON);
	glVertex2i(0, 15);
	glVertex2i(10, 20);
	glVertex2i(20, 15);
	glVertex2i(20, -15);
	glVertex2i(10, -20);
	glVertex2i(0, -15);
	glVertex2i(0, 15);
	glEnd();
	glPopMatrix();
	glFlush();
}

void Fase_TheVengeanceWeapon::desenhaBackground()
{
	for (int i = 0; i < 15; i = i + 2){
		desenha3(Pontos[i][0], Pontos[i][1], 0.8);
		desenha4(Pontos[i + 1][0], Pontos[i + 1][1], 0.8);
	}
}

void Fase_TheVengeanceWeapon::desenha()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.1137, 0.8627, 0.8902, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	desenhaBackground();
	// Executa os comandos OpenGL
	glutSwapBuffers();
}

void Fase_TheVengeanceWeapon::terminou()
{
}

void Fase_TheVengeanceWeapon::atualiza(int value)
{
	for (int i = 0; i < 16; i++){
		Pontos[i][1] -= 10;
	}
	for (int i = 0; i < 16; i++){
		if (Pontos[i][1] < -400){
			Pontos[i][1] = 600;
		}
	}
	if (variacao){
		variacaoX++;
	}
	else{
		variacaoX--;
	}
	if (variacaoX < -100){
		variacao = true;
	}
	else if (variacaoX > 100){
		variacao = false;
	}
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
	EfeitoSonoro::getInstance().playThirdLevelTheme();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	Pontos[0][0] = -265;
	Pontos[0][1] = 220;
	Pontos[1][0] = 0;
	Pontos[1][1] = 150;
	Pontos[2][0] = 225;
	Pontos[2][1] = 0;
	Pontos[3][0] = 265;
	Pontos[3][1] = 220;
	Pontos[4][0] = -225;
	Pontos[4][1] = 0;
	Pontos[5][0] = -265;
	Pontos[5][1] = -220;
	Pontos[6][0] = 0;
	Pontos[6][1] = -150;
	Pontos[7][0] = 265;
	Pontos[7][1] = -220;
	for (int i = 8; i < 16; i++){
		Pontos[i][0] = Pontos[i - 8][0];
		Pontos[i][1] = Pontos[i - 8][1] + 570;
	}
}
