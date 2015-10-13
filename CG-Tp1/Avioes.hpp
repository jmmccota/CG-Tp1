#ifndef AVIOES_H
#define AVIOES_H

class Spitfire;
class Bf109;
class Me163;
class Me264;

#include "Personagem.hpp"
#include "Armamentos.hpp"
#include <cmath>


#ifdef PERSONAGEM

class Spitfire : public Personagem
{
    private:
        bool movCima = false, movBaixo = false, movEsq = false, movDir = false;
        GLfloat velX = 0, velY = 0;

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


class Bf109 : public Personagem
{
private:
    //Ponteiro para o personagem que esse inimigo visa destruir
    Personagem* alvo;

    //variavel usada para controlar em quais frames deve atirar
    int estadoTiro;

public:
    Bf109(GLfloat pX, GLfloat pY, float esc, Personagem *a, Fase *f);
    ~Bf109();

    void atira(int tipo);
    void acao();
};


class Me163 : public Personagem
{
    private:
        Personagem *alvo;
        GLfloat velocidadeX, velocidadeY;

    public:
        Me163(GLfloat pX, GLfloat pY, float esc, Personagem *a, Fase *f);
        ~Me163();

        void acao();
};


class Me264 : public Personagem
{
private:
	bool movCima = false, movBaixo = false, movEsq = false, movDir = false;

public:
	Me264(GLfloat pX, GLfloat pY, float esc, Fase *f);
	~Me264();
	void acao();
	void atira(int tipo);
};

#endif


#endif
 