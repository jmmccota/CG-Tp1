#include "Personagem.hpp"

Personagem::Personagem(GLfloat pX, GLfloat pY, GLfloat vel, float esc, Fase* f) : Solido(pX, pY, vel, esc)
{
    fase = f;
}

Personagem::~Personagem()
{
}

void Personagem::alvejado(int dano)
{
    hp -= dano;
}
int Personagem::getHP() {
	return hp;
}
void Personagem::setNumeroVidas() {
	numeroVidas++;
}
int Personagem::getNumeroVidas() {
	return numeroVidas;
}
int Personagem::getQtdTiros() {
	return municao[1];
}
bool Personagem::destruido()
{
    return hp <= 0;
}
float Personagem::getX() {
	return posX;
}
float Personagem::getY() {
	return posY;
}