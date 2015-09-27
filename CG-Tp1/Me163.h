#ifndef ME163_H
#define ME163_H

class Me163;

#include "Personagem.h"

class Me163 : public Personagem
{
    private:
        Personagem *alvo;

    public:
        Me163(GLfloat pX, GLfloat pY, float esc, Personagem *a, Fase *f);
        ~Me163();

        void acao();
};

#endif