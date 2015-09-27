#include "Personagem.h"

Personagem::Personagem(GLfloat posX, GLfloat posY, GLfloat velocidade, float escala, Fase* f) : Solido(posX, posY, velocidade, escala)
{
    fase = f;
}

void Personagem::alvejado(int dano)
{
    hp -= dano;
}

bool Personagem::destruido()
{
    return hp <= 0;
}