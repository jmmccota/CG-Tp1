#include "Armamentos.hpp"


////////////////////////////////////////////////////////////////////////////////////////////////


TiroSimples::TiroSimples(GLfloat posX, GLfloat posY, float escala)
    : Projetil(posX, posY, 30000*escala, escala)
{
    this->dano = 10;
    this->carrega("modelos/tirosimples.dat");
}


TiroSimples::~TiroSimples()
{
}


////////////////////////////////////////////////////////////////////////////////////////////////


TiroSimplesInimigo::TiroSimplesInimigo(GLfloat posX, GLfloat posY, float escala)
    : Projetil(posX, posY, -30000 * escala, escala)
{
    this->dano = 10;
    this->carrega("modelos/tirosimples.dat");
}


TiroSimplesInimigo::~TiroSimplesInimigo()
{
}


////////////////////////////////////////////////////////////////////////////////////////////////


Bomba::Bomba(GLfloat posX, GLfloat posY, float escala)
    : Projetil(posX, posY, 300*escala, escala)
{
    this->dano = 200;
    this->carrega("modelos/bombasimples.dat");
}


Bomba::~Bomba()
{
}
 