#include "Projetil.hpp"

Projetil::Projetil(GLfloat pX, GLfloat pY, GLfloat vel, float esc)
    : Solido(pX, pY, vel, esc)
{
}

void Projetil::acao()
{
    posY += velocidade;
}
 
int Projetil::getDano()
{
    return dano;
}