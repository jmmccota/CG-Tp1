#ifndef JOGO_H
#define JOGO_H

//60fps
#define TEMPOQUADRO 16.66
class Jogo;

#include "Fase.hpp"
#include "EfeitoVisual.hpp"
#include "Menu.hpp"
#include <vector>


#define JOGO


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


#include "Fase.hpp"

#endif
 