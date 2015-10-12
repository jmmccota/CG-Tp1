#include "Animacao.hpp"

void Animacao::inicializa()
{
	EfeitoSonoro::getInstance().playOpenTheme();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

Animacao::Animacao()
{
}


Animacao::~Animacao()
{
}

void Animacao::definePersonagens()
{
}

void Animacao::desenhaBackground()
{
}

void Animacao::desenha()
{
	glClear(GL_COLOR_BUFFER_BIT);

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
	Spitfire *s = new Spitfire(-45, 0, (float)20 / 10000, nullptr);
	Bf109 *b = new Bf109(50, 0, (float)20 / 10000, nullptr, nullptr);
	TiroSimples *t1 = new TiroSimples(-39.5, 8, (float)2 / 10000);
	TiroSimples *t2 = new TiroSimples(-39.5, -8, (float)2 / 10000);

	// desenha o primeiro bloco atiraador
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glTranslatef(translacaoX - 45, translacaoY - 45, translacaoZ);
	glRotatef(rotacaoX1, 1, 0, 0);
	glRotatef(rotacaoY1, 0, 1, 0);
	glRotatef(270.0f, 0.0f, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	s->desenha();
	glPopMatrix();

	if (booldesenha == true) {
		// desenha a muniçãoo
		glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-100, 100, -100, 100);
		glTranslatef(translacaoX2, 0, 0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		t1->desenha();
		t2->desenha();
		glPopMatrix();

		// desenha o bloco q recebe o tiro
		glPushMatrix();
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
		// desenha a explosao
		EfeitoSonoro::getInstance().playBoomEffect();
		glPushMatrix();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-100, 100, -100, 100);
		glTranslatef(translacaoX2, 0, 0);
		if (escala < 3) {
			escala = escala + 0.3;
		}
		else {
			explosao = false;
		}
		glScalef(escala, escala, escala);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex2f(-10, 10);
		glVertex2f(10, 10);
		glVertex2f(10, -10);
		glVertex2f(-10, -10);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(1, 0, 0);
		glVertex2f(15, 0);
		glVertex2f(0, 15);
		glVertex2f(-15, 0);
		glVertex2f(0, -15);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 0);
		glVertex2f(-5, 5);
		glVertex2f(5, 5);
		glVertex2f(5, -5);
		glVertex2f(-5, -5);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 0);
		glVertex2f(7.5, 0);
		glVertex2f(0, 7.5);
		glVertex2f(-7.5, 0);
		glVertex2f(0, -7.5);
		glEnd();
		glPopMatrix();
	}
	glutSwapBuffers();
}

void Animacao::terminou()
{
	if (pularAnimacao)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		EfeitoSonoro::getInstance().stopSong();
		cout << "Menu Iniciado\n";
		Jogo::getInstance().setProxFase(1);
		Jogo::getInstance().proximaFase();
	}
}

void Animacao::atualiza(int value)
{
    if (value >= 300)
        pularAnimacao = true;
	//Testa se a fase acabou
    terminou();
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
