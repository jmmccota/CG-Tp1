#ifndef EFEITOVISUAL_H
#define EFEITOVISUAL_H

class Explosao;
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

class Explosao
{
    public:
        GLfloat x;
        GLfloat y;
        int value;
        GLfloat escala;
        Explosao(GLfloat x, GLfloat y, GLfloat escala)
        {
            this->x = x;
            this->y = y;
            this->value = 1;
            this->escala = escala;
        }
} ;

class EfeitoVisual
{
	private:

		bool fullscreen;
		int sizeX ;
		int sizeY;
		EfeitoVisual();
		EfeitoVisual(EfeitoVisual const&);
		void operator=(EfeitoVisual const&);
		bool isFinish = false;

        //coisas de explosao
        std::vector<float> posX;
        std::vector<float> posY;
        std::vector<int> esc;
        std::vector<bool> expl;
        std::vector<bool> cresce;
        float escalaAnimacao = 0;
        bool explode = true;

	public:
		~EfeitoVisual();

		//Funcoes de configuracoes basicas
		void ortho2D();

		//Pegar os valores do ortho2D: First = Eixo X; Second = Eixo Y;
		pair<float, float> getOrtho2D();

        //Coisas de explosao
        void desenhaExplosao(Explosao e);

        //Desenhos de cenario TheBlitz
        void desenhaRetangulo(float translacaoX, float translY, float escalaX, float escalaY, float rot, float red, float green, float blue);
        void desenhaQuarteirao(float translacaoX, float translY, float escalaX, float escalaY, float red, float green, float blue, int altura, int largura, int tX, int tY);
        void desenhaLinhaAsfalto(float translacaoX, float translY, float escalaX, float escalaY, float red, float green, float blue, int altura, int largura, int tX, int tY);

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

        //Reajusta o tamanho da tela
        void static resize(GLsizei w, GLsizei h);

		void desenhaTitulo(int posX,int posY);
};
#endif
 