#include "Jogo.hpp"

Jogo::Jogo()
{
	score = new Score();
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
	fases.push_back(new GameOver());
	proxFase = 0;
	proximaFase();


	double xspit = 30;
	for (int ii = 0; ii < 5; ii++) {
		vidas[ii] = new Spitfire(xspit + 50 * ii, 1030, (float) 20 / 10000, nullptr);
	}
	glutMainLoop();
}

Jogo& Jogo::getInstance()
{
	static Jogo singleton;
	return singleton;
}
void Jogo::setControlaScore() {
	controlaScore += 10000;
}
void Jogo::zeraControlaScore() {
	controlaScore = 0;
}
int Jogo::getControlaScore() {
	return controlaScore;
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
	    case 'p':
	    case 'P':
		    Jogo::getInstance().pausado = !Jogo::getInstance().pausado;
		    break;
	    case 27: //Tecla ESC -> Sair do Jogo
		    exit(0);
		    break;
	    default:
		    Jogo::getInstance().fases[Jogo::getInstance().proxFase]->keyUp(key, x, y);
		    break;
	}

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
	if (!Jogo::getInstance().pausado || Jogo::getInstance().proxFase < 2) {
		Jogo::getInstance().estado++;
		Jogo::getInstance().fases[Jogo::getInstance().proxFase]->atualiza(value);
		glutPostRedisplay();
	}
    glutTimerFunc(TEMPOQUADRO, Jogo::timer, Jogo::getInstance().estado);
}

void Jogo::inicializa(int fase)
{
	if(numeroVidas > 0)
	{
		estado = 0;
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
		if (fase == 5) {
			Jogo::getInstance().gameOver = false;
			if (Jogo::getInstance().score->getScoreValue() > 0) {
				Jogo::getInstance().bestScore = true;
			}
		}
		Jogo::getInstance().fases[fase]->inicializa();		
	}
	else
	{
		//Game over
		estado = 0;
		// Inicializa o sistema de coordenadas
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glutMouseFunc(Jogo::mouse);
		glutKeyboardFunc(Jogo::keyDown);
		glutKeyboardUpFunc(Jogo::keyUp);
		glutSpecialFunc(Jogo::specialKeyDown);
		glutSpecialUpFunc(Jogo::specialKeyUp);
		glutDisplayFunc(Jogo::draw);		
		Jogo::getInstance().gameOver = true;		
		if (Jogo::getInstance().score->getScoreValue() > 0) {
			Jogo::getInstance().bestScore = true;
		}
		Jogo::getInstance().fases[fase]->inicializa();
	}
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
	//passar isso pro destrutor??
	exit(0);
}
