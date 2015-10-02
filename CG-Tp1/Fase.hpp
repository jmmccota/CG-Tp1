#ifndef FASE_H
#define FASE_H

class Fase;

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include "Personagem.hpp"
#include "Projetil.hpp"
#include "Jogo.hpp"
#include <queue>
#include <vector>


/*
	Classe abstrata para servir como "interface" para
		as telas do jogo.
*/


class Fase
{
	protected:
		//Personagem jogavel
        Personagem *principal;

		//Fila de inimigos que apareceram na tela
		std::queue<Personagem*> inimigosInativos;

        //Lista de inimigos que apareceram na tela
        std::vector<Personagem*> inimigosAtivos;

        //Lista de projeteis que apareceram na tela
        std::vector<Projetil*> projeteis;

		//Ponteiro para a classe principal
		//	Usado para devolver o fluxo de controle
        Jogo *jogo;

	public:
		//Limpa memoria alocada dinamicamente
		virtual ~Fase() = 0;

		//Inicializa o personagem principal e a fila de inimigos
		virtual void definePersonagens() = 0;

		//Desenha o fundo da fase na tela
		virtual void desenhaBackground() = 0;

		//Desenha todos os elementos da fase na tela
		virtual void desenha() = 0;

		//Define se a fase foi encerrada
		//	Caso tenha sido desvia o fluxo para a funcao que define as fases
		virtual void terminou() = 0;

		//Define quais alteracoes devem ser feitas do frame anterior
		//para o frame atual e chama a funcao de desenho
        virtual void atualiza() = 0;

        //Define funcoes e parametros OpenGL
        virtual void glSetup() = 0;

        //Realiza chamada para definePersonagens e glSetup
        virtual void inicializa();

        //Insere um novo projetil na fase
        void novoProjetil(Projetil *p);
};



#endif