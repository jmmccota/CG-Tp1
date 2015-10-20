#pragma once
#include "Fase.hpp"
//#include <AntTweakBar.h>

class GameOver :
	public Fase
{
public:
	GameOver();
	~GameOver();
	bool gameOver = true;
	bool melhorScore = true;
	int bestScore = 0;
	int contador = 0;

	string nome="";
protected:

	void definePersonagens();
	void desenhaBackground();
	// Fun��o callback chamada para fazer o desenho
	void desenha();
	void terminou();

	// Fun��o callback chamada pela GLUT a cada intervalo de tempo
	// (a window n�o est� sendo redimensionada ou movida)
	void atualiza(int value);

	//Clique do mouse
	void mouse(int button, int state, int x, int y);
	void keyDown(unsigned char key, int x, int y);
	void keyUp(unsigned char key, int x, int y);
	void specialKeyDown(int key, int x, int y);
	void specialKeyUp(int key, int x, int y);

	// Inicializa par�metros de rendering
	void inicializa();

	void desenhaGameOver();
	void desenhaScore();
};

