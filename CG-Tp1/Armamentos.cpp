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
    this->carrega("modelos/tirosimplesInimigo.dat");
}


TiroSimplesInimigo::~TiroSimplesInimigo()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////


TiroEspecial::TiroEspecial(GLfloat posX, GLfloat posY, float escala)
	: Projetil(posX, posY, -30000 * escala, escala)
{
	this->dano = 10;
	this->carrega("modelos/tiroEspecial.dat");
}


TiroEspecial::~TiroEspecial()
{
}


////////////////////////////////////////////////////////////////////////////////////////////////


Bomba::Bomba(GLfloat posX, GLfloat posY, float escala)
    : Projetil(posX, posY, 900*escala, escala)
{
    this->dano = 50;
    this->carrega("modelos/bombasimples.dat");	
}


Bomba::~Bomba()
{
}


void Bomba::acao()
{
    if (girou)
        posX += (inverteuX ? -velocidade : velocidade);
    else
        posY += (inverteuY ? -velocidade : velocidade);
}


////////////////////////////////////////////////////////////////////////////////////////////////

TiroEspecialInimigo::TiroEspecialInimigo(GLfloat posX, GLfloat posY, GLfloat posXAlvo, GLfloat posYAlvo, float escala, float velocidade)
	: Projetil(posX, posY, velocidade, escala)
{
	this->carrega("modelos/tirosimplesInimigo.dat");
	double tan = (posYAlvo - posY) / (posXAlvo - posX);
	double teta = atan(tan);
	if (posXAlvo < posX)
		teta = teta + 3.14159;
	velX = velocidade * cos(teta);
	velY = velocidade * sin(teta);
	if (posXAlvo < posX)
	{
		if (posYAlvo < posY)
		{
			teta = 1.57079 - teta;
		}
		else
		{
			teta = - 1.57079 + teta;
		}
	}
	else
	{
		if (posYAlvo < posY)
		{
			teta = 1.57079 - teta;
		}
		else
		{
			teta = - 1.57079 + teta;
		}
	}
    for (int i = 0; i < poligonos.size(); i++)
        poligonos[i].rotaciona(-teta);
    dano = 10;
}

TiroEspecialInimigo::~TiroEspecialInimigo()
{

}

void TiroEspecialInimigo::acao()
{
    posX += velX;
    posY += velY;
}