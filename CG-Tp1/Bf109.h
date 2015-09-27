#ifndef BF109_H
#define BF109_H

class Bf109;

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
        Bf109(GLfloat pX, GLfloat pY, float esc, Personagem *a, Fase *f);
        ~Bf109();

        void atira(int tipo);
        void acao();
};

#endif