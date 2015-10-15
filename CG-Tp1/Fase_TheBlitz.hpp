#ifndef THEBLITZ_FASE
#define THEBLITZ_FASE

#include "Fase.hpp"

#ifdef FASE

using namespace std;

class Fase_TheBlitz : public Fase
{
protected:

public:
	Fase_TheBlitz();
	~Fase_TheBlitz();

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
};

#endif

#endif
