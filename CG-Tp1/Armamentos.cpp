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
    this->dano = 50;
    this->carrega("modelos/bombasimples.dat");
}


Bomba::~Bomba()
{
}


////////////////////////////////////////////////////////////////////////////////////////////////


TiroEspecialInimigo::TiroEspecialInimigo(GLfloat posX, GLfloat posY, GLfloat posXAlvo, GLfloat posYAlvo, float escala)
    : Projetil(posX, posY, 30000 * escala, escala)
{
    double tan = (posY - posYAlvo) / (posX - posXAlvo);
    double teta = atan(tan);
    for (int i = 0; i < poligonos.size(); i++)
        poligonos[i].rotaciona(teta);
}

TiroEspecialInimigo::~TiroEspecialInimigo()
{

}

void TiroEspecialInimigo::acao()
{

}