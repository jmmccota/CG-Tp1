#ifndef PERSONAGEM_H
#define PERSONAGEM_H

class Personagem;

#include "Solido.hpp"
#include "Projetil.hpp"
#include "Fase.hpp"
#ifdef _WIN32
#include <windows.h>
#include <GL/gl.h>
#endif
#include <GL/glut.h>

/*
	Classe abstrata para servir como "interface" para
		os personagens do jogo.
*/

#define PERSONAGEM

class Personagem : public Solido
{
	protected:
		//Valores de vida e municoes do personagem
		int hp, numeroVidas;

        //Ponteiro para fase
        //  Utilizado para informar novos projeteis
        Fase *fase;

	public:

		int municao[2];

        //Inicia o personagem
        Personagem(GLfloat pX, GLfloat pY, GLfloat vel, float esc, Fase* f);

		//Limpa memoria alocada dinamicamente
		virtual ~Personagem() = 0;

        //Atira projetil tipo 1 ou 2
        virtual void atira(int tipo) = 0;

        void alvejado(int dano);
		int getHP();
		float getX();
		float getY();
		int getNumeroVidas();
		int getQtdTiros();
		void setNumeroVidas();
        //Retorna true caso o personagem tenha sido destruido
        bool destruido();

		//Retorna o dano ao outro aviao que colidiu com esse
		virtual int danoColisao() = 0;

		//Retorna o nome do aviao
		virtual string getNome() = 0;

		//Retorna o nome do aviao
		virtual int getScore() = 0;
};

#include "Avioes.hpp"

#endif
 