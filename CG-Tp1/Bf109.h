#ifndef BF109_H
#define BF109_H

#include "Personagem.h"
#include "TiroSimplesInimigo.h"
#include <cmath>

class Bf109 : public Personagem
{
    private:
        //Ponteiro para o personagem que esse inimigo visa destruir
        Personagem* alvo;

        //variavel usada para controlar em quais frames deve atirar
        int estadoTiro;

    public:
        Bf109(GLfloat posX, GLfloat posY, float escala, Personagem *alvo, Fase *f);
        ~Bf109();

        void atira(int tipo);
        void acao();
};

#endif