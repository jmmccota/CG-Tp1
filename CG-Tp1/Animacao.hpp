#ifndef ANIMACAO_FASE
#define ANIMACAO_FASE

#include "Fase.hpp"

#ifdef FASE

using namespace std;

class Animacao : public Fase
{
protected:
	Spitfire *spitifire;
	Bf109 *bf109_1;
	Bf109 *bf109_2;
	Bf109 *bf109_3;

	GLfloat translacaoX = 0;
	bool pularAnimacao = false;
public:
	Animacao();
	~Animacao();

	void definePersonagens();

	void desenhaBackground();
	void desenhaHUD();
	void desenhaNumeroVidas(int numeroVidas);

	void desenhaHUD(int hp);

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
