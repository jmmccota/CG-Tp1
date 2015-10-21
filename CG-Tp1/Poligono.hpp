#ifndef POLIGONO_H
#define POLIGONO_H

class Poligono;

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
#include <string>
#include <vector>
#include "FuncoesAuxiliares.hpp"

class Poligono
{
    protected:
        float escala;
        GLfloat cor[3];
        vector<GLfloat> pontosX;
        vector<GLfloat> pontosY;

    public:
        Poligono(float escala);
        ~Poligono();

        //Carrega o poligono
        void carrega(std::vector<std::string> linhas);

        //Desenha o poligono relativo ao ponto (x,y)
        //    (x,y) usado como posicao do solido que contem o poligono
        void desenha(GLfloat x, GLfloat y);

        //Inverte os pontos Y do poligono
        //    Usado para avioes vindo na direcao oposta
        void inverteY();
        void inverteX();
        void gira();

        //Rotaciona o poligono em teta graus
        void rotaciona(double teta);

        //Getters
        GLfloat getPontoX(int indice);
        GLfloat getPontoY(int indice);
        int getNPontos();
};

#endif
 