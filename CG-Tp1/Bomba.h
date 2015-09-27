#ifndef BOMBA_H
#define BOMBA_H

class Bomba;

#include "Projetil.h"

class Bomba : public Projetil
{
    public:
        Bomba(GLfloat posX, GLfloat posY, float escala);
        ~Bomba();
};

#endif