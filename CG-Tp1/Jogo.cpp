#include "Jogo.hpp"


Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}


void Jogo::run()
{
	char *myargv[1];
	int myargc = 1;
	myargv[0] = _strdup("CG-Tp1");
	glutInit(&myargc, myargv);
	glutCreateWindow("Jiraya's Fly");
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(EfeitoVisual::getInstance().sizeScreen().first, EfeitoVisual::getInstance().sizeScreen().second);
	glutInitWindowPosition(EfeitoVisual::getInstance().positionScreen("center").first, EfeitoVisual::getInstance().positionScreen("center").second);
	glutReshapeFunc(EfeitoVisual::resize);
	EfeitoVisual::getInstance().ortho2D();


	//fases.push_back(new Menu());
	proxFase = 0;
	proximaFase();

	glutMainLoop();
}


Jogo& Jogo::getInstance()
{
	static Jogo singleton;
	return singleton;
}


void Jogo::mouse(int button, int state, int x, int y)
{
	Jogo::getInstance().fases[Jogo::getInstance().proxFase]->mouse(button, state, x, y);
}
void Jogo::keyDown(unsigned char key, int x, int y)
{
	Jogo::getInstance().fases[Jogo::getInstance().proxFase]->keyDown(key, x, y);
}
void Jogo::keyUp(unsigned char key, int x, int y)
{
	Jogo::getInstance().fases[Jogo::getInstance().proxFase]->keyUp(key, x, y);
}
void Jogo::draw()
{
	Jogo::getInstance().fases[Jogo::getInstance().proxFase]->desenha();
}
void Jogo::timer(int value)
{
	Jogo::getInstance().fases[Jogo::getInstance().proxFase]->atualiza(value);
	glutPostRedisplay();
	glutTimerFunc(TEMPOQUADRO, Jogo::timer, value + 1);
}




void Jogo::inicializa(int fase)
{
	glutMouseFunc(Jogo::mouse);
	glutKeyboardFunc(Jogo::keyDown);
	glutKeyboardUpFunc(Jogo::keyUp);
	glutDisplayFunc(Jogo::draw);
	glutTimerFunc(TEMPOQUADRO, Jogo::timer, 1);
}

void Jogo::proximaFase()
{
	if (proxFase != -1)
		inicializa(proxFase);
	else
		fimJogo();
}

void Jogo::setProxFase(int p)
{
	proxFase = p;
}

void Jogo::fimJogo()
{
	//salvar score
	exit(0);
}
