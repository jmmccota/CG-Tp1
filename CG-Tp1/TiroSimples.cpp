#include "TiroSimples.h"


TiroSimples::TiroSimples(GLfloat posX, GLfloat posY, float escala)
    : Projetil(posX, posY, 0.1*escala, escala)
{
    this->dano = 10;
    this->carrega("modelos/tirosimples.txt");
}


TiroSimples::~TiroSimples()
{
}
