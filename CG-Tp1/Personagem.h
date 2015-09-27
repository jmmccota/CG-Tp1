#ifndef PERSONAGEM_ABS
#define PERSONAGEM_ABS



#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include "Solido.h"
#include "Projetil.h"
#include "Fase.h"
#include <string>


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
        Personagem(GLfloat posX, GLfloat posY, GLfloat velocidade, float escala, Fase* f);

		//Limpa memoria alocada dinamicamente
		virtual ~Personagem() = 0;

		//Carrega o personagem do arquivo de modelo
        virtual void carrega(std::string file);

        //Atira projetil tipo 1 ou 2
        virtual void atira(int tipo) = 0;

        void alvejado(int dano);

        //Retorna true caso o personagem tenha sido destruido
        bool destruido();
};



#endif