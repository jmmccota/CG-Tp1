#ifndef JOGO_H
#define JOGO_H

class Jogo;

#include "Fase.hpp"
#include "EfeitoVisual.hpp"
#include <vector>

//60fps
#define TEMPOQUADRO 0.01666

class Jogo
{
    private:
        int proxFase;
        std::vector<Fase*> fases;

    public:
        Jogo(int* argc, char** argv);
        ~Jogo();

        void setProxFase(int p);
        void proximaFase();
        void fimJogo();
};

#endif
 