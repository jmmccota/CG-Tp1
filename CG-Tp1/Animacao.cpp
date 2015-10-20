#include "Animacao.hpp"

Animacao::Animacao()
{
	spitifire = new Spitfire(0, -200, 0.002, nullptr);
	bf109_1 = new Bf109(0, -100, 0.002, nullptr, nullptr);
	bf109_2 = new Bf109(45, -120, 0.002, nullptr, nullptr);
	bf109_3 = new Bf109(-45, -120, 0.002, nullptr, nullptr);
}

Animacao::~Animacao()
{
}

void Animacao::definePersonagens()
{
}

void drawLineAnimacao(float pos, char eixo) {

	pair<int, int> size = EfeitoVisual::getInstance().getOrtho2D();

	//glColor3f(0, 1.0, 0.9);
	glColor3f(1, 0.27, 0);
	glLineWidth(3.0f);
	if (eixo == 'x') {
		glBegin(GL_LINE_LOOP);
		glVertex2f(pos, 0.0);
		glVertex2f(pos, size.second);
		glEnd();
	}
	else if (eixo == 'y') {
		glBegin(GL_LINE_LOOP);
		glVertex2f(0.0, pos);
		glVertex2f(size.first, pos);
		glEnd();
	}
}

void Animacao::desenhaBackground()
{
	pair<int, int> sizeScreen = EfeitoVisual::getInstance().getOrtho2D();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Desenha Linha Superior Y
	drawLineAnimacao(sizeScreen.second - 40, 'y');
	//Desenha Linha Inferior Y
	drawLineAnimacao(40, 'y');

	EfeitoVisual::getInstance().desenhaTitulo(600, -200);

}

void Animacao::desenhaHUD()
{
}

void Animacao::desenha()
{
	glClear(GL_COLOR_BUFFER_BIT);
	desenhaBackground();

	gluOrtho2D(-100, 100, -100, 100);
	glTranslatef(translacaoX, 0, 0);
	glRotatef(270.0f, 0, 0, 1);
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	spitifire->desenha();

	bf109_1->desenha();
	bf109_2->desenha();
	bf109_3->desenha();
	glPopMatrix();

	glutSwapBuffers();
}

void Animacao::terminou()
{
	if (pularAnimacao)
	{
		EfeitoSonoro::getInstance().finishAllAudios();
		Jogo::getInstance().setProxFase(1);
		Jogo::getInstance().proximaFase();
	}
}

void Animacao::atualiza(int value)
{
	if (value >= 450)
		pularAnimacao = true;
	//Testa se a fase acabou
	terminou();

	translacaoX += 0.8;
}

void Animacao::mouse(int button, int state, int x, int y)
{
}

void Animacao::keyDown(unsigned char key, int x, int y)
{
}

void Animacao::keyUp(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'f':
		EfeitoVisual::getInstance().setFullScreen();
		break;
	case 13: //Tecla enter para pular animação
		pularAnimacao = true;
		break;
	default:
		break;
	}
}

void Animacao::specialKeyDown(int key, int x, int y)
{
}

void Animacao::specialKeyUp(int key, int x, int y)
{
}
void Animacao::desenhaHUD(int hp) {
}
void Animacao::desenhaNumeroVidas(int numeroVidas) {
}

void Animacao::inicializa()
{
	EfeitoSonoro::getInstance().playStreamAudio("audio/sfx/bf109FlyBy.mp3");
	EfeitoSonoro::getInstance().playStreamAudio("audio/sfx/spitfireFlyBy.mp3");
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}