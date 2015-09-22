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

        void Carrega(std::string *linhas, int nLinhas);
        void Desenha(GLfloat x, GLfloat y);

};

#endif