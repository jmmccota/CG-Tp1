#include "Fase.hpp"

Fase::Fase()
{

}

Fase::~Fase()
{
    
}


void desenha2(){
	glClearColor(0, 0.5, 1, 1);
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glPopMatrix();
}
void Fase::desenhaHUD(int hp) {
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
	/*pair<float, float> size = EfeitoVisual::getInstance().getOrtho2D();
	int xspit, yspit;
	xspit = 35;
	yspit = 1028;*/
	/*vidas = new Spitfire(xspit, yspit, (float)20 / 10000, this);
	vidas->desenha();
	vidas2 = new Spitfire(xspit + 50 * 1, yspit, (float)20 / 10000, this);
	vidas2->desenha();
	vidas3 = new Spitfire(xspit + 50 * 2, yspit, (float)20 / 10000, this);
	vidas3->desenha();
	vidas4 = new Spitfire(xspit + 50 * 3, yspit, (float)20 / 10000, this);
	vidas4->desenha();
	vidas5 = new Spitfire(xspit + 50 * 4, yspit, (float)20 / 10000, this);
	vidas5->desenha();*/
}

//void desenha2(){
//	glClearColor(0, 0.5, 1, 1);
//	glPushMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-100, 100, -100, 100);
//	glPopMatrix();
//}


void Fase::desenhaBackground(){
	//desenha2();
}
void Fase::desenhaNumeroVidas(int numeroVidas) {

}
void Fase::desenha(){
	//desenhaBackground();
}

//void Fase::desenhaHUD(int hp)
//{
//
//}

void Fase::novoProjetilInimigo(Projetil *p)
{
    projeteisInimigos.push_back(p);
}

void Fase::novoProjetilAmigo(Projetil *p)
{
    projeteisAmigos.push_back(p);
}
 