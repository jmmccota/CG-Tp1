#ifndef FASE_ABS
#define FASE_ABS



#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <queue>
#include "Personagem.h"


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
		std::queue<Personagem> inimigos;

		//Ponteiro para a classe principal
		//	Usado para devolver o fluxo de controle
		//Jogo *jogo

	public:
		//Limpa memoria alocada dinamicamente
		virtual ~Fase() = 0;
		
		//Define funcoes e parametros OpenGL
		virtual void glSetup() = 0;

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
};



#endif