#ifndef JOGO_H
#define JOGO_H

#include "Fase.h"
#include <vector>

//60fps
#define TEMPOQUADRO 0.01666

class Jogo
{
    private:
        int proxFase;
        std::vector<Fase*> fases;

    public:
        Jogo();
        ~Jogo();

        void setProxFase(int p);
        void proximaFase();
        void fimJogo();
};

#endif