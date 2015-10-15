#include "Fase_TheVengeanceWeapon.hpp"
GLfloat PontosCeu[16][2];
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
		desenha3(PontosCeu[i][0], PontosCeu[i][1], 0.8);
		desenha4(PontosCeu[i + 1][0], PontosCeu[i + 1][1], 0.8);
	}
}

void Fase_TheVengeanceWeapon::desenha()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.1137, 0.8627, 0.8902, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	desenhaBackground();
	desenhaHUD(principal->getHP());
	// Executa os comandos OpenGL
	glutSwapBuffers();
}
void Fase_TheVengeanceWeapon::desenhaHUD(int hp) {
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2i(20, 1000);
	glVertex2i(254, 1000);
	glVertex2i(254, 970);
	glVertex2i(20, 970);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex2i(21, 999);
	glVertex2i(253, 999);
	glVertex2i(253, 971);
	glVertex2i(21, 971);
	glEnd();	
}
void Fase_TheVengeanceWeapon::desenhaNumeroVidas(int numeroVidas) {

}
void Fase_TheVengeanceWeapon::terminou()
{
}

void Fase_TheVengeanceWeapon::atualiza(int value)
{
	for (int i = 0; i < 16; i++){
		PontosCeu[i][1] --;
	}
	for (int i = 0; i < 16; i++){
		if (PontosCeu[i][1] < -400){
			PontosCeu[i][1] = 600;
		}
	}
	if (variacao){
		variacaoX+=0.5;
	}
	else{
		variacaoX-=0.5;
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
	PontosCeu[0][0] = -265;
	PontosCeu[0][1] = 220;
	PontosCeu[1][0] = 0;
	PontosCeu[1][1] = 150;
	PontosCeu[2][0] = 225;
	PontosCeu[2][1] = 0;
	PontosCeu[3][0] = 265;
	PontosCeu[3][1] = 220;
	PontosCeu[4][0] = -225;
	PontosCeu[4][1] = 0;
	PontosCeu[5][0] = -265;
	PontosCeu[5][1] = -220;
	PontosCeu[6][0] = 0;
	PontosCeu[6][1] = -150;
	PontosCeu[7][0] = 265;
	PontosCeu[7][1] = -220;
	for (int i = 8; i < 16; i++){
		PontosCeu[i][0] = PontosCeu[i - 8][0];
		PontosCeu[i][1] = PontosCeu[i - 8][1] + 570;
	}
}
