#ifndef TIROSIMPLES_H
#define TIROSIMPLES_H

class TiroSimples;

#include "Projetil.h"

class TiroSimples : public Projetil
{
    public:
        TiroSimples(GLfloat posX, GLfloat posY, float escala);
        ~TiroSimples();
};

#endif