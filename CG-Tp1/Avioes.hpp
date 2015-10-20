#ifndef AVIOES_H
#define AVIOES_H

class Spitfire;
class Bf109;
class Bf109Verde;
class Bf109Amarelo;
class Me163;
class Me264;
class Me262;
class Bismarck;
class V2;

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
		// 0 = Tiro simples; 1 = Tiro duplo
		int powerUp = 0;
		int nBomba = 10;
        Spitfire(GLfloat pX, GLfloat pY, float esc, Fase *f);
        ~Spitfire();

        void acao();
        void atira(int tipo);
		int danoColisao();
        void morreu();
		bool venceu();
		string getNome();
		int getScore();
		GLfloat getX();
		GLfloat getY();

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

    //Quantidade de tiros a serem dados em um segundo
    int tirosSegundo = 1;

    void atira(int tipo);
    void acao();
	int danoColisao();
	string getNome();
	int getScore();
};

class Bf109Verde : public Bf109
{
public:
	Bf109Verde(GLfloat pX, GLfloat pY, float esc, Personagem *a, Fase *f) :
		Bf109(pX, pY, esc, a, f)
	{
		this->carrega("modelos/bf109Verde.dat");
	}
	~Bf109Verde() {}

	string getNome() { return "Bf109Verde"; }
};

class Bf109Amarelo : public Bf109
{
public:
	Bf109Amarelo(GLfloat pX, GLfloat pY, float esc, Personagem *a, Fase *f) :
		Bf109(pX, pY, esc, a, f)
	{
		this->carrega("modelos/bf109Amarelo.dat");
	}
	~Bf109Amarelo() {}

	string getNome() { return "Bf109Amarelo"; }
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
		void atira(int tipo);
		int danoColisao();
		string getNome();
		int getScore();
};

class Me262 : public Personagem
{
private:
    Spitfire *alvo;

    bool movCima = false, movBaixo = false, movEsq = false, movDir = false;
    int alvoX, alvoY;

    int estadoTiro;
    int contadorEst = -1;
    int tirosSegundo = 3;

public:
    Me262(GLfloat pX, GLfloat pY, float esc, Spitfire *a, Fase *f);
    ~Me262();
    void acao();
    void atira(int tipo);
    int danoColisao();
    string getNome();
    int getScore();
};


class Me264 : public Personagem
{
private:
    Personagem *alvo;
    //variaveis usadas para controlar em quais frames deve atirar
    int estadoTiro = 0;
    int estrategia;
    int ladoBomba = -1;
    int tirosSegundo = 3;
    int contadorEst = -1;
    float velocidadeBala;

public:
    Me264(GLfloat pX, GLfloat pY, float esc, Personagem *a, Fase *f);
	~Me264();
	void acao();
	void atira(int tipo);
	int danoColisao();
	string getNome();
    int getScore();
    void finaliza();
};

class V2 : public Personagem
{
private:
	bool movCima = false, movBaixo = false, movEsq = false, movDir = false;

public:
	V2(GLfloat pX, GLfloat pY, float esc, Fase *f);
	~V2();
	void acao();
	void atira(int tipo);
	int danoColisao();
	string getNome();
    int getScore();
    void finaliza();
};

class Bismarck : public Personagem
{
private:
	Personagem *alvo;
	//variaveis usadas para controlar em quais frames deve atirar
	int estadoTiro = 0;
	int estrategia;
	int tirosSegundo = 3;
	int contadorEst = -1;
	float velocidadeBala;
	bool movCima = false, movBaixo = false, movEsq = false, movDir = false;

public:
	Bismarck(GLfloat pX, GLfloat pY, float esc, Spitfire *a, Fase *f);
	~Bismarck();
	void acao();
	void atira(int tipo);
	int danoColisao();
	string getNome();
    int getScore();
    void finaliza();
};

class AviaoCriado : public Personagem
{
private:
	bool movCima = false, movBaixo = false, movEsq = false, movDir = false;

public:
	AviaoCriado(GLfloat pX, GLfloat pY, float esc, Fase *f);
	~AviaoCriado();
	void acao();
	void atira(int tipo);
	int danoColisao();
	string getNome();
	int getScore();
	void finaliza();
};

#endif
#endif


 