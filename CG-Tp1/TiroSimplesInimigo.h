#ifndef TIROSIMPLESINIMIGO_H
#define TIROSIMPLESINIMIGO_H

class TiroSimplesInimigo;

#include "Projetil.h"

class TiroSimplesInimigo : public Projetil
{
    public:
        TiroSimplesInimigo(GLfloat posX, GLfloat posY, float escala);
        ~TiroSimplesInimigo();
};

#endif