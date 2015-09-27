#include "Jogo.h"


Jogo::Jogo()
{
    //fases.push_back(new Fase1);
    proxFase = 0;
}


Jogo::~Jogo()
{
}

void Jogo::proximaFase()
{
    if (proxFase != -1)
        fases[proxFase]->inicializa();
    else
        fimJogo();
}

void Jogo::setProxFase(int p)
{
    proxFase = p;
}

void Jogo::fimJogo()
{

}