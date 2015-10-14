#ifndef ANIMACAO_FASE
#define ANIMACAO_FASE

#include "Fase.hpp"

#ifdef FASE

using namespace std;

class Animacao : public Fase
{
protected:
	GLfloat escala = 1;
	GLfloat rotacaoX1 = 0;
	GLfloat rotacaoY1 = 0;
	GLfloat rotacaoX2 = 0;
	GLfloat rotacaoY2 = 0;
	GLfloat translacaoY = 0;
	GLint translacaoX = -180;
	GLint translacaoX2 = -180;
	GLfloat translacaoZ = 0;
	bool booldesenha = true;
	bool explosao = true;
    bool comecouExplosao = false;
	bool pularAnimacao = false;
public:
	Animacao();
	~Animacao();

	void definePersonagens();

	void desenhaBackground();
	void desenhaHUD();

	// Função callback chamada para fazer o desenho
	void desenha();

	void terminou();

	// Função callback chamada pela GLUT a cada intervalo de tempo
	// (a window não está sendo redimensionada ou movida)
	void atualiza(int value);

	//Clique do mouse
	void mouse(int button, int state, int x, int y);
	void keyDown(unsigned char key, int x, int y);
	void keyUp(unsigned char key, int x, int y);
	void specialKeyDown(int key, int x, int y);
	void specialKeyUp(int key, int x, int y);

	// Inicializa parâmetros de rendering
	void inicializa();

};

#endif

#endif
