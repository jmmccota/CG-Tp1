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
	int contador = 0;
	void definePersonagens();

	void desenhaBackground();

	void writeScore(int score);

	void desenha();

	void terminou();

	void atualiza(int value);
	void desenhaQuadrado(int x, int y, int x1, int y1);
	void mouse(int button, int state, int x, int y);
	void keyDown(unsigned char key, int x, int y);
	void keyUp(unsigned char key, int x, int y);
	void specialKeyDown(int key, int x, int y);
	void specialKeyUp(int key, int x, int y);
	void desenhaGameOver();
	void desenhaScore();
	void inicializa();
};

