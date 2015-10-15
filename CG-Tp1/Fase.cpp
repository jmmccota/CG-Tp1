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
//void Fase::desenhaHUD() {
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
//	pair<float, float> size = EfeitoVisual::getInstance().getOrtho2D();
//	int xspit, yspit;
//	xspit = 35;
//	yspit = 1028;
//	vidas = new Spitfire(xspit, yspit, (float)20 / 10000, this);
//	vidas->desenha();
//	vidas2 = new Spitfire(xspit + 50 * 1, yspit, (float)20 / 10000, this);
//	vidas2->desenha();
//	vidas3 = new Spitfire(xspit + 50 * 2, yspit, (float)20 / 10000, this);
//	vidas3->desenha();
//	vidas4 = new Spitfire(xspit + 50 * 3, yspit, (float)20 / 10000, this);
//	vidas4->desenha();
//	vidas5 = new Spitfire(xspit + 50 * 4, yspit, (float)20 / 10000, this);
//	vidas5->desenha();
//}

//void desenha2(){
//	glClearColor(0, 0.5, 1, 1);
//	glPushMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-100, 100, -100, 100);
//	glPopMatrix();
//}

void Fase::desenhaHUD() {
	//HP
	int hp = principal->getHP();
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2i(20, 1000);
	glVertex2i(254, 1000);
	glVertex2i(254, 970);
	glVertex2i(20, 970);
	glEnd();
	double partes = 0.234;
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex2f(21, 999);
	if ((partes*hp + 20) > 21) {
		glVertex2f(partes*hp + 20, 999);
		glVertex2f(partes*hp + 20, 971);
	}
	else {
		glVertex2f(21, 999);
		glVertex2f(21, 971);
	}
	glVertex2f(21, 971);
	glEnd();
	//Vidas
	for (int ii = 0; ii < Jogo::getInstance().numeroVidas; ii++) {
		Jogo::getInstance().vidas[ii]->desenha();
	}
	
	string qtd = "x ";
	qtd += std::to_string(principal->getQtdTiros());
	//Jogo::getInstance().projetil->desenha();
	glRasterPos2f(50, 50);
	FuncoesAuxiliares::writeWord_BITMAP(qtd, GLUT_BITMAP_TIMES_ROMAN_24);
	//Score
	//string sc = "Score: ";
	int sco = Jogo::getInstance().score;
	std::string s = std::to_string(Jogo::getInstance().score);
	//sc += s;
	glRasterPos2f(1630, 1000);
	int contrSc = Jogo::getInstance().getControlaScore();
	
	if (sco>=contrSc) {
		cout << "Sco: "<<sco;
		cout << "Contr: "<<contrSc;	
		if (Jogo::getInstance().numeroVidas<5) {
			Jogo::getInstance().numeroVidas++;
		}
		Jogo::getInstance().setControlaScore();
		//mudar cor do score??
		
		
	}
	FuncoesAuxiliares::writeWord_BITMAP(s, GLUT_BITMAP_TIMES_ROMAN_24);	
	

	
}

void Fase::desenha(){
	//desenhaBackground();
}

void Fase::novoProjetilInimigo(Projetil *p)
{
    projeteisInimigos.push_back(p);
}

void Fase::novoProjetilAmigo(Projetil *p)
{
    projeteisAmigos.push_back(p);
}
 