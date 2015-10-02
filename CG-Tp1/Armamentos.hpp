#ifndef ARMAMENTOS_H
#define ARMAMENTOS_H

class TiroSimples;
class TiroSimplesInimigo;
class Bomba;

#include "Projetil.hpp"

class TiroSimples : public Projetil
{
    public:
        TiroSimples(GLfloat posX, GLfloat posY, float escala);
        ~TiroSimples();
};


class TiroSimplesInimigo : public Projetil
{
public:
    TiroSimplesInimigo(GLfloat posX, GLfloat posY, float escala);
    ~TiroSimplesInimigo();
};


class Bomba : public Projetil
{
public:
    Bomba(GLfloat posX, GLfloat posY, float escala);
    ~Bomba();
};


#endif