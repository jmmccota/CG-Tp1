#include "Me163.h"


Me163::Me163(GLfloat pX, GLfloat pY, float esc, Personagem *a, Fase *f)
    : Personagem(pX, pY, 0.025*esc, esc, f)
{
    alvo = a;
    carrega("modelo/me163.txt");
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