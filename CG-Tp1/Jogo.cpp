#include "Jogo.hpp"


Jogo::Jogo(int* argc, char** argv)
{
	glutInit(argc, argv);
	glutCreateWindow("Jiraya's Fly");
	EfeitoVisual::inicializa();
	EfeitoSonoro::inicializa();
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
 