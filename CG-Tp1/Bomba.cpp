#include "Bomba.h"


Bomba::Bomba(GLfloat posX, GLfloat posY, float escala)
    : Projetil(posX, posY, 0.1*escala, escala)
{
    this->dano = 10;
    //this->carrega("modelos/bomba.txt");
}


Bomba::~Bomba()
{
}
