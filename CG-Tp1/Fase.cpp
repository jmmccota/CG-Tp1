#include "Fase.hpp"

Fase::Fase()
{

}

Fase::~Fase()
{
    
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

void Fase::desenha(){
	//desenhaBackground();
}

void Fase::desenhaHUD()
{

}

void Fase::novoProjetilInimigo(Projetil *p)
{
    projeteisInimigos.push_back(p);
}

void Fase::novoProjetilAmigo(Projetil *p)
{
    projeteisAmigos.push_back(p);
}
 