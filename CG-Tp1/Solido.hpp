#ifndef SOLIDO_H
#define SOLIDO_H

class Solido;

#ifdef _WIN32
#include <windows.h>
#endif
#include "FuncoesAuxiliares.hpp"
#include "Poligono.hpp"
#include <GL/gl.h>
#include <GL/glut.h>
#include <string>
#include <fstream>
#include <vector>


/*
	Classe abstrata para servir como "interface" para
		os objetos do jogo.
*/


class Solido
{
	protected:
		//Vetor de poligonos
		std::vector<Poligono> poligonos;

		//Posicao central do solido
		GLfloat posX, posY;

		//Dimensoes X e Y do solido
		GLfloat tamX, tamY;

        //Velocidade de movimentação do solido
        GLfloat velocidade;

        //Escala do solido
        float escala;

	public:
        Solido(GLfloat pX, GLfloat pY, GLfloat vel, float esc);

		//Limpa memoria alocada dinamicamente
		virtual ~Solido();

		//Retorna true caso solido tenha sido destruido, false caso contrario
        // virtual bool destruido() = 0;

		//Desenha o solido na tela
		void carrega(std::string arquivo);

		//Desenha o solido na tela
		void desenha();

		//Define as acoes do solido
		//	(movimento, destruicao, ...)
        virtual void acao() = 0;

		//Getters
		GLfloat getX() { return posX; }
		GLfloat getY() { return posY; }
		GLfloat getTamX() { return tamX; }
		GLfloat getTamY() { return tamY; }

};




#endif
 