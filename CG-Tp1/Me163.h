#ifndef ME163_H
#define ME163_H

#include "Personagem.h"

class Me163 : public Personagem
{
    private:
        Personagem *alvo;

    public:
        Me163(GLfloat posX, GLfloat posY, float escala, Personagem *alvo, Fase *f);
        ~Me163();

        void acao();
};

#endif