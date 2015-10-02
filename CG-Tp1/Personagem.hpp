#ifndef PERSONAGEM_H
#define PERSONAGEM_H

class Personagem;

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include "Solido.hpp"
#include "Projetil.hpp"
#include "Fase.hpp"

/*
	Classe abstrata para servir como "interface" para
		os personagens do jogo.
*/

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
};



#endif