#ifndef PERSONAGEM_ABS
#define PERSONAGEM_ABS



#include <GL/gl.h>
#include <GL/glut.h>
#include "Solido.h"


/*
	Classe abstrata para servir como "interface" para
		os personagens do jogo.
*/


class Personagem : public Solido
{
	protected:
		//Valores de vida e municoes do personagem
		int hp, municao1, municao2;

	public:
		//Limpa memoria alocada dinamicamente
		virtual ~Personagem() = 0;

		//Carrega o personagem do arquivo de modelo
		virtual void carrega() = 0;
};



#endif