#ifndef ARMAMENTOS_H
#define ARMAMENTOS_H

class TiroSimples;
class TiroSimplesInimigo;
class Bomba;

#include "Projetil.hpp"
#include <cmath>

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


class TiroEspecialInimigo : public Projetil
{
private:
    GLfloat velX, velY;
public:
    TiroEspecialInimigo(GLfloat posX, GLfloat posY, GLfloat posXAlvo, GLfloat posYAlvo, float escala, float velocidade);
    ~TiroEspecialInimigo();
    void acao();
};


#endif
 