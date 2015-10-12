#ifndef EFEITOVISUAL_H
#define EFEITOVISUAL_H

class EfeitoVisual;

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include "Solido.hpp"
#include "Avioes.hpp"
#include "EfeitoSonoro.hpp"
#include <time.h>

/*
	===============SINGLETON===============
	Somente uma instancia vai ser usada no programa todo.
	Como usar:
		EfeitoVisal::getInstance().FUNCAOQUEEUQUEROCHAMAR(PARAMETROS);
		...
    Porque:
        Somente uma instancia pode existir para que as informacoes
        de estado da tela sejam consistentes durante o jogo todo.

	Classe usada para efeitos visuais
		(deteccao de colisao, explosoes, ...)
*/


class EfeitoVisual
{
	private:

		bool fullscreen;
		int sizeX ;
		int sizeY;
		EfeitoVisual();
		EfeitoVisual(EfeitoVisual const&);
		void operator=(EfeitoVisual const&);

	public:
		~EfeitoVisual();

		//Funcoes de configuracoes basicas
		void ortho2D();

		//Pegar os valores do ortho2D: First = Eixo X; Second = Eixo Y;
		pair<float, float> getOrtho2D();

		//COMO FAZER ANIMACAO EXPLOSAO?
		//void static Explosao(GLfloat x, GLfloat y, GLfloat raio, int estagio);

		//Retorna true caso objetos tenham colidido, false caso contrario
		bool colisao(Solido *a, Solido *b);

		//Retorna se a tela está em fullScreen ou não
		bool isFullScreen();

		//Retorna a resolução padrão da Tela: First = Eixo X; Second = Eixo Y;
		pair<int, int> sizeScreen();

		//Posição da tela: First = Eixo X; Second = Eixo Y;
		pair<double, double> positionScreen(char *type);

		//Metodo de pressionamento de teclas
		void setFullScreen();

        static EfeitoVisual& getInstance();

        //Callbacks do OpenGL devem ser estaticos

        //Reajusta o tamanho da tela
        void static resize(GLsizei w, GLsizei h);

		//Criar uma nuvem qualquer
		void desenhaNuvem();

		//Cria Estrelas
		void desenhaEstrelas(int quantEstrelas);
};
#endif
 