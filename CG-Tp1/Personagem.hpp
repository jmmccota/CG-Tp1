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
		int hp, municao[2];

        //Ponteiro para fase
        //  Utilizado para informar novos projeteis
        Fase *fase;

	public:
        //Inicia o personagem
        Personagem(GLfloat pX, GLfloat pY, GLfloat vel, float esc, Fase* f);

		//Limpa memoria alocada dinamicamente
		virtual ~Personagem() = 0;

        //Atira projetil tipo 1 ou 2
        virtual void atira(int tipo) = 0;

        void alvejado(int dano);

        //Retorna true caso o personagem tenha sido destruido
        bool destruido();

        //Inverte os pontos Y do poligono
        //    Usado para avioes vindo na direcao oposta
        void inverteY();
};

#include "Avioes.hpp"

#endif
 