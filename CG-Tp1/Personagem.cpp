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

bool Personagem::destruido()
{
    return hp <= 0;
}