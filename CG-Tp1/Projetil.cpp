#include "Projetil.h"

Projetil::Projetil(GLfloat posX, GLfloat posY, GLfloat velocidade, float escala)
    : Solido(posX, posY, velocidade, escala)
{
}

void Projetil::acao()
{
    posY += velocidade;
}