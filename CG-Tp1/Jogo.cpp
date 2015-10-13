#include "Jogo.hpp"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::run()
{
	pair<int, int> sizeScreen = EfeitoVisual::getInstance().sizeScreen();
	pair<int, int> posScrenn = EfeitoVisual::getInstance().positionScreen("center");
	char *myargv[1];
	int myargc = 1;
	myargv[0] = _strdup("CG-Tp1");

	glutInit(&myargc, myargv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(sizeScreen.first, sizeScreen.second);
	glutInitWindowPosition(posScrenn.first, posScrenn.second);
	glutCreateWindow("Jiraya's Fly");
	glutReshapeFunc(EfeitoVisual::resize);

	fases.push_back(new Animacao());
	fases.push_back(new Menu());
	fases.push_back(new Fase_TheBlitz());
	fases.push_back(new Fase_TheBattleOfBritain());
	fases.push_back(new Fase_TheVengeanceWeapon());
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
	pair<int, int> size = EfeitoVisual::getInstance().sizeScreen();
	pair<int, int> ortho = EfeitoVisual::getInstance().getOrtho2D();

	x = ((double)x) / size.first * ortho.first;
	y = ((double)y) / size.second * ortho.second;

	Jogo::getInstance().fases[Jogo::getInstance().proxFase]->mouse(button, state, x, y);
}
void Jogo::keyDown(unsigned char key, int x, int y)
{
	Jogo::getInstance().fases[Jogo::getInstance().proxFase]->keyDown(key, x, y);
}
void Jogo::keyUp(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'f':
		EfeitoVisual::getInstance().setFullScreen();
		break;
	case 27: //Tecla ESC -> Sair do Jogo
		exit(0);
		break;
	}

	Jogo::getInstance().fases[Jogo::getInstance().proxFase]->keyUp(key, x, y);
}

void Jogo::specialKeyDown(int key, int x, int y)
{
	Jogo::getInstance().fases[Jogo::getInstance().proxFase]->specialKeyDown(key, x, y);
}
void Jogo::specialKeyUp(int key, int x, int y)
{
	Jogo::getInstance().fases[Jogo::getInstance().proxFase]->specialKeyUp(key, x, y);
}

void Jogo::draw()
{
	EfeitoVisual::getInstance().ortho2D();
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
	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glutMouseFunc(Jogo::mouse);
	glutKeyboardFunc(Jogo::keyDown);
	glutKeyboardUpFunc(Jogo::keyUp);
	glutSpecialFunc(Jogo::specialKeyDown);
	glutSpecialUpFunc(Jogo::specialKeyUp);
	glutDisplayFunc(Jogo::draw);
	glutTimerFunc(TEMPOQUADRO, Jogo::timer, 1);
	Jogo::getInstance().fases[fase]->inicializa();
}

void Jogo::proximaFase()
{
	if (proxFase != -1){
		inicializa(proxFase);}
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
