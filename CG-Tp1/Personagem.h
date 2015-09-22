#ifndef PERSONAGEM_ABS
#define PERSONAGEM_ABS



#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include "Solido.h"
#include <string>


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
        virtual void carrega(std::string file);
};



#endif