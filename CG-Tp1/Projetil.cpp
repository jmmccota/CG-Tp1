#include "Projetil.h"

Projetil::Projetil(GLfloat pX, GLfloat pY, GLfloat vel, float esc)
    : Solido(pX, pY, vel, esc)
{
}

void Projetil::acao()
{
    posY += velocidade;
}