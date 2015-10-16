#include "Fase_TheVengeanceWeapon.hpp"
#include "FuncoesAuxiliares.hpp"
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
	pair<float, float> size = EfeitoVisual::getInstance().getOrtho2D();
	principal = new Spitfire(0, 0, 0.000015, this);
}

void desenhaCirculo(GLfloat raio, GLfloat Px, GLfloat Py){
	GLfloat x = 0;
	GLfloat y = 0;
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i += 0.2){
		x = Px + raio * cos(i);
		y = Py + raio * sin(i);
		glVertex2f(x, y);
	}
	glEnd();
}

void Pedra(GLfloat X, GLfloat Y, GLfloat escala, float translacaoX, float translacaoY){
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glScalef(escala, escala, 0);
	glTranslatef(translacaoX + variacaoX, translacaoY, 0);
	glColor3f(1, 1, 1);
	desenhaCirculo(5, 8+X, 6+Y);
	desenhaCirculo(5, 4+X, 4+Y);
	desenhaCirculo(4, 9+X, 3+Y);
	desenhaCirculo(3, 5+X, 0+Y);
	desenhaCirculo(5, 5+X, 0+Y);
	glPopMatrix();
	glFlush();
}
void desenhaBackgroundAnterior(){
	for (int i = 0; i < 14; i = i + 2){
		Pedra(0, 0, 2, PontosCeu[i][0], PontosCeu[i][1]);
	}
}

void desenhabackgroudPosterior(){
	for (int i = 0; i < 14; i = i + 2){
		Pedra(0, 0, 2.5, PontosCeu[i + 1][0], PontosCeu[i + 1][1]);
	}
}

void Fase_TheVengeanceWeapon::desenhaBackground()
{
}

void Fase_TheVengeanceWeapon::desenha()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.1137, 0.8627, 0.8902, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	desenhaBackgroundAnterior();
	desenhaHUD();
	principal->desenha();
	desenhabackgroudPosterior();
	// Executa os comandos OpenGL
	glutSwapBuffers();
}
//void Fase_TheVengeanceWeapon::desenhaHUD(int hp) {
//	glBegin(GL_LINE_LOOP);
//	glColor3f(1, 1, 1);
//	glVertex2i(20, 1000);
//	glVertex2i(254, 1000);
//	glVertex2i(254, 970);
//	glVertex2i(20, 970);
//	glEnd();
//	glBegin(GL_QUADS);
//	glColor3f(1, 0, 0);
//	glVertex2i(21, 999);
//	glVertex2i(253, 999);
//	glVertex2i(253, 971);
//	glVertex2i(21, 971);
//	glEnd();	
//}

void Fase_TheVengeanceWeapon::terminou()
{
}

void Fase_TheVengeanceWeapon::atualiza(int value)
{
	for (int i = 0; i < 14; i++){
		PontosCeu[i][1] -= 0.3;
	}
	for (int i = 0; i < 14; i++){
		if (PontosCeu[i][1] < -100){
			PontosCeu[i][1] = 100;
		}
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
	definePersonagens();
	EfeitoSonoro::getInstance().initAudios_TheVengeanceWeapon();
	EfeitoSonoro::getInstance().playMainTheme();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	PontosCeu[0][0] = -35;
	PontosCeu[0][1] = 30;
	PontosCeu[1][0] = -5;
	PontosCeu[1][1] = 15;
	PontosCeu[2][0] = 25;
	PontosCeu[2][1] = 30;
	PontosCeu[4][0] = -5;
	PontosCeu[4][1] = 20;
	PontosCeu[5][0] = -40;
	PontosCeu[5][1] = -25;
	PontosCeu[6][0] = 35;
	PontosCeu[6][1] = -30;
	PontosCeu[7][0] = -5;
	PontosCeu[7][1] = -45;
	for (int i = 8; i < 14; i++){
		PontosCeu[i][0] = PontosCeu[i - 7][0];
		PontosCeu[i][1] = PontosCeu[i - 7][1] + 100;
	}
}
