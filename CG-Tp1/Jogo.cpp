#include "Jogo.hpp"


Jogo::Jogo(int* argc, char** argv)
{
	glutInit(argc, argv);
	glutCreateWindow("Jiraya's Fly");
    //fases.push_back(new Menu());
    proxFase = 0;
	glutMainLoop();
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
	//salvar score
	exit(0);
}
 