#include "Bf109.h"


Bf109::Bf109(GLfloat pX, GLfloat pY, float esc, Personagem *a, Fase *f)
    : Personagem(pX, pY, 0.01*esc, esc, f)
{
    alvo = a;
    carrega("modelos/bf109.txt");
    hp = 30;
    municao[0] = 999;
    municao[1] = 0;
}


Bf109::~Bf109()
{
}

void Bf109::acao()
{
    //Se ainda esta "longe" do alvo
    if (abs(alvo->getX() - posX) > (tamX + tamX + tamX))
    {
        posX += (alvo->getX() - posX > 0 ? velocidade : -velocidade);
    }
    //Se esta perto do alvo
    else
    {
        posX += (alvo->getX() - posX > 0 ? velocidade / 1.5 : -velocidade / 1.5);

        //Atira 3 vezes por segundo caso esteja em posicao
        estadoTiro = ++estadoTiro % (int)(1 / (3 * TEMPOQUADRO));
        if(!estadoTiro) atira(0);
    }
    posY -= velocidade;
}

void Bf109::atira(int tipo)
{
    if (municao[tipo] > 0)
    {
        municao[tipo]--;
        fase->novoProjetil(new TiroSimplesInimigo(posX, posY + tamY, escala));
    }
}