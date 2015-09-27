#include "Me163.h"


Me163::Me163(GLfloat posX, GLfloat posY, float escala, Personagem *alvo, Fase *f)
    : Personagem(posX, posY, 0.025*escala, escala, f)
{
    this->alvo = alvo;
    this->carrega("modelo/me163.txt");
    hp = 20;
    municao[0] = 0;
    municao[1] = 0;
}


Me163::~Me163()
{
}


void Me163::acao()
{
    //Se ainda esta "longe" do alvo
    if (abs(alvo->getX() - posX) > (tamX + tamX + tamX))
    {
        posX += (alvo->getX() - posX > 0 ? velocidade : -velocidade);
    }
    //Se esta perto do alvo
    else
    {
        posX += (alvo->getX() - posX > 0 ? velocidade : -velocidade);
    }
    posY -= velocidade;
}