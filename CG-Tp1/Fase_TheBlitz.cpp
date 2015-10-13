#include "Fase_TheBlitz.hpp"

// pontos do efeito de agua
GLfloat Pontos[16][2];

Fase_TheBlitz::Fase_TheBlitz()
{
    principal = new Spitfire(500, 500, (float) 100 / 10000, this);
}

Fase_TheBlitz::~Fase_TheBlitz()
{
    delete principal;
}

void Fase_TheBlitz::definePersonagens()
{
}


void desenha2(float translacaoX, float translacaoY, float escala){
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glScalef(escala, escala, 0);
    glTranslatef(translacaoX, translacaoY, 0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2i(-10, 0);
    glVertex2i(0, 10);
    glVertex2i(0, 10);
    glVertex2i(10, 0);
    glVertex2i(10, 0);
    glVertex2i(20, 10);
    glEnd();
    glPopMatrix();
    glFlush();
}

void Fase_TheBlitz::desenhaBackground()
{
    for (int i = 0; i < 16; i++){
        desenha2(Pontos[i][0], Pontos[i][1], 0.25);
    }
    EfeitoVisual::getInstance().ortho2D();
}

void Fase_TheBlitz::desenha()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.1137, 0.8627, 0.8902, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    desenhaBackground();

    for (int i = 0; i < inimigosAtivos.size(); i++)
        inimigosAtivos[i]->desenha();

    principal->desenha();

    for (int i = 0; i < projeteis.size(); i++)
        projeteis[i]->desenha();

    // Executa os comandos OpenGL
    glutSwapBuffers();
}

void Fase_TheBlitz::terminou()
{
}

void Fase_TheBlitz::atualiza(int value)
{
	for (int i = 0; i < 16; i++){
		Pontos[i][1] -= 2;
	}
	for (int i = 0; i < 16; i++){
		if (Pontos[i][1] < -400){
			Pontos[i][1] = 600;
		}
	}

    principal->acao();

    for (int i = 0; i < inimigosAtivos.size(); i++)
        inimigosAtivos[i]->acao();

    for (int i = 0; i < projeteis.size(); i++)
        projeteis[i]->acao();
    
}

void Fase_TheBlitz::mouse(int button, int state, int x, int y)
{
}

void Fase_TheBlitz::keyDown(unsigned char key, int x, int y)
{
}

void Fase_TheBlitz::keyUp(unsigned char key, int x, int y)
{
    principal->detectaTiro(key, x, y);
}

void Fase_TheBlitz::specialKeyDown(int key, int x, int y)
{
    principal->detectaMovimentoDown(key, x, y);
}

void Fase_TheBlitz::specialKeyUp(int key, int x, int y)
{
    principal->detectaMovimentoUp(key, x, y);
}

void Fase_TheBlitz::inicializa()
{
	EfeitoSonoro::getInstance().playFirstLevelTheme();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    Pontos[0][0] = -265;
    Pontos[0][1] = 220;
    Pontos[1][0] = 0;
    Pontos[1][1] = 150;
    Pontos[2][0] = 225;
    Pontos[2][1] = 0;
    Pontos[3][0] = 265;
    Pontos[3][1] = 220;
    Pontos[4][0] = -225;
    Pontos[4][1] = 0;
    Pontos[5][0] = -265;
    Pontos[5][1] = -220;
    Pontos[6][0] = 0;
    Pontos[6][1] = -150;
    Pontos[7][0] = 265;
    Pontos[7][1] = -220;
    for (int i = 8; i < 16; i++){
        Pontos[i][0] = Pontos[i - 8][0];
        Pontos[i][1] = Pontos[i - 8][1] + 570;
    }
}
