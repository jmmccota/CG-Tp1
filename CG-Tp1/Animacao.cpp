#include "Animacao.hpp"

Animacao::Animacao()
{
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

	Spitfire *s = new Spitfire(-45, 0, (float)20 / 10000, nullptr);
	Bf109 *b = new Bf109(50, 0, (float)20 / 10000, nullptr, nullptr);
	TiroSimples *t1 = new TiroSimples(-38, 8, (float)2 / 10000);
	TiroSimples *t2 = new TiroSimples(-38, -8, (float)2 / 10000);

	//desenha o primeiro bloco atirador
	gluOrtho2D(-100, 100, -100, 100);
	glTranslatef(translacaoX - 45, translacaoY - 45, translacaoZ);
	glRotatef(rotacaoX1, 1, 0, 0);
	glRotatef(rotacaoY1, 0, 1, 0);
	glRotatef(270.0f, 0.0f, 0.0f, 1.0f);
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	s->desenha();
	glPopMatrix();

	if (booldesenha == true) {
		//desenha a muniçãoo
		glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-100, 100, -100, 100);
		glTranslatef(translacaoX2, 0, 0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		t1->desenha();
		t2->desenha();
		//desenha o bloco que recebe o tiro
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-100, 100, -100, 100);
		glTranslatef(translacaoX + 45, 50, 0);
		glRotatef(270.0f, 0.0f, 0.0f, 1.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		b->desenha();
		glPopMatrix();
	}
	else if (explosao) {
		explosao = !EfeitoVisual::getInstance().desenhaExplosao(3, translacaoX2, 0);
	}
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
	if (value >= 180)
		pularAnimacao = true;
	//Testa se a fase acabou
	terminou();

	translacaoX += 2;
	if (booldesenha) {

		if (translacaoX >= -20) {
			translacaoX2 = translacaoX2 + 8;
		}
		else {
			translacaoX2 += 2;
		}
		//momento em q as balas colidem com o bloco
		if ((translacaoX2 - translacaoX) > 78) {
			translacaoX2 = translacaoX2 - 30;
			booldesenha = false;
		}
	}
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