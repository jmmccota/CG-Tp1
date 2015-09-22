#ifndef POLIGONO_H
#define POLIGONO_H

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <string>
#include <vector>
#include "FuncoesAuxiliares.h"

class Poligono
{
    private:
        float escala;
        GLfloat cor[3];
        int nPontos;
        GLfloat *pontosX;
        GLfloat *pontosY;

    public:
        Poligono(int escala);
        ~Poligono();

        //Carrega o poligono
        void carrega(std::string *linhas, int nLinhas);

        //Desenha o poligono relativo ao ponto (x,y)
        //    (x,y) usado como posicao do solido que contem o poligono
        void desenha(GLfloat x, GLfloat y);

};

#endif