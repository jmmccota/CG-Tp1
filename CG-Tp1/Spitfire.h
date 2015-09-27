#ifndef SPITFIRE_H
#define SPITFIRE_H

class Spitfire;

#include "Personagem.h"
#include "TiroSimples.h"
#include "Bomba.h"

class Spitfire : public Personagem
{
    private:
        bool movCima = false, movBaixo = false, movEsq = false, movDir = false;

    public:
        Spitfire(GLfloat pX, GLfloat pY, float esc, Fase *f);
        ~Spitfire();

        void acao();
        void atira(int tipo);

        //Funcao a ser passada para o opengl para detectar botoes de disparo
        void detectaTiro(unsigned char key, int x, int y);
        //Funcao a ser passada para o opengl para detectar botoes de movimento
        void detectaMovimentoDown(int key, int x, int y);
        void detectaMovimentoUp(int key, int x, int y);
};

#endif