#include "Fase_TheBattleOfBritain.hpp"

// pontos do efeito de agua
GLfloat PontosAgua[16][2];
GLfloat transXIlha1 = 0;
GLfloat transXIlha2 = 50;
GLfloat transYIlha1 = 0;
GLfloat transYIlha2 = 500;
GLfloat escalaMe = 1;
GLfloat meX = 0;
Me163 *me163 = new Me163(0, -5, 0.0005, nullptr, nullptr);
bool ilha1 = false;

Fase_TheBattleOfBritain::Fase_TheBattleOfBritain()
{
}

Fase_TheBattleOfBritain::~Fase_TheBattleOfBritain()
{
    delete principal;
}

void Fase_TheBattleOfBritain::definePersonagens()
{
    pair<float, float> size = EfeitoVisual::getInstance().getOrtho2D();
    principal = new Spitfire(size.first / 2, size.second / 10, (float)100 / 10000, this);

    //Fora da tela so pra nao comecar vazio
    projeteisAmigos.push_back(new TiroSimples(-1000, -1000, 0));
    projeteisInimigos.push_back(new TiroSimples(-1000, -1000, 0));
    inimigosAtivos.push_back(new Bf109(-1000, -1000, 0, principal, this));
}

void drawWaves(float translacaoX, float translacaoY, float escala){
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

void desenhaCirculo1(GLfloat raio, GLfloat Px, GLfloat Py){
	GLfloat x = 0;
	GLfloat y = 0;
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i += 0.2){
		x = Px + raio * cos(i);
		y = Py + raio * sin(i);
		glVertex2f(x, y);
	}
	glEnd();
}
void drawIsland2(float translacaoX, float translacaoY, float escala){
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glScalef(escala, escala, 0);
	glTranslatef(translacaoX, translacaoY, 0);
	glColor3f(0.722, 0.525, 0.043);
	desenhaCirculo1(20, 0, 0);
	desenhaCirculo1(10, -12, -9);
	desenhaCirculo1(10, -12, 9);
	desenhaCirculo1(7, 0, 15);
	desenhaCirculo1(12, 8, 12);
	desenhaCirculo1(8, 10, -13);
	desenhaCirculo1(12, -15, 0);
	glTranslatef(meX, 0, 0);
	glRotatef(90, 0, 0, 1);
	glScalef(escalaMe, escalaMe, 0);
	me163->desenha();
	glPopMatrix();
	glFlush();
}


void drawIsland1(float translacaoX, float translacaoY, float escala){
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glScalef(escala, escala, 0);
	glTranslatef(translacaoX, translacaoY, 0);
	glColor3f(0.722, 0.525, 0.043);
	desenhaCirculo1(10, 0, 0);
	desenhaCirculo1(8, 4, 5);
	desenhaCirculo1(4, -6, 6);
	desenhaCirculo1(5, 6, -6);
	desenhaCirculo1(3, -3, -9);
	glPopMatrix();
	glFlush();
}

void Fase_TheBattleOfBritain::desenhaBackground()
{
    for (int i = 0; i < 16; i++){
        drawWaves(PontosAgua[i][0], PontosAgua[i][1], 0.25);
    }
		drawIsland1(transXIlha1, transYIlha1, 1);
		drawIsland2(transXIlha2, transYIlha2, 1);
    EfeitoVisual::getInstance().ortho2D();
}

void Fase_TheBattleOfBritain::desenha()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.2235f, 0.4823f, 0.8078f, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    desenhaBackground();

    for (std::list<Projetil*>::iterator i = projeteisAmigos.begin(); i != projeteisAmigos.end(); ++i)
        (*i)->desenha();

    for (std::list<Projetil*>::iterator i = projeteisInimigos.begin(); i != projeteisInimigos.end(); ++i)
        (*i)->desenha();

    for (std::list<Personagem*>::iterator i = inimigosAtivos.begin(); i != inimigosAtivos.end(); ++i)
        (*i)->desenha();

    principal->desenha();
	desenhaHUD();
    // Executa os comandos OpenGL
    glutSwapBuffers();
}
//void Fase_TheBattleOfBritain::desenhaHUD(int hp) {
//	glBegin(GL_LINE_LOOP);
//	glColor3f(1, 1, 1);
//	glVertex2i(20, 1000);
//	glVertex2i(254, 1000);
//	glVertex2i(254, 970);
//	glVertex2i(20, 970);
//	glEnd();
//	glBegin(GL_QUADS);
//	glColor3f(1, 0, 0);
//	glVertex2i(21, 999);
//	glVertex2i(253, 999);
//	glVertex2i(253, 971);
//	glVertex2i(21, 971);
//	glEnd();	
//}

void Fase_TheBattleOfBritain::terminou()
{
}

void Fase_TheBattleOfBritain::atualiza(int value)
{
    for (int i = 0; i < 16; i++){
        PontosAgua[i][1] -= 2;
    }
    for (int i = 0; i < 16; i++){
        if (PontosAgua[i][1] < -400){
            PontosAgua[i][1] = 600;
        }
    }
	transYIlha1 -= 0.5;
	transYIlha2 -= 0.5;
	if (transYIlha1 < -600){
		transYIlha1 = 500;
		transXIlha1 = -130 + (rand() % 200);
	}
	if (transYIlha2 < -700){
		transYIlha2 = 400;
		meX = 0;
		escalaMe = 1;
		transXIlha2 = -90 + (rand() % 200);
	}
	if (transYIlha2 < 100){
		meX -= 0.5;
		if (meX < -20){
			escalaMe += 0.002;
		}
	}
	for (std::list<Projetil*>::iterator i = projeteisAmigos.begin(); i != projeteisAmigos.end(); ++i)
	{
		//Calcula os disparos dados
		(*i)->acao();

		//Atualiza situacao dos inimigos
		for (std::list<Personagem*>::iterator j = inimigosAtivos.begin(); j != inimigosAtivos.end();)
		{
			//Se foi alvejado
			if (EfeitoVisual::getInstance().colisao((*j), (*i)))
				(*j)->alvejado((*i)->getDano());
			//Se foi destruido
			if ((*j)->destruido())
			{
				//Explode
				j = inimigosAtivos.erase(j);
			}
			//Se ta de boa ainda
			else
			{
				(*j)->acao();
				j++;
			}
		}
	}



	for (std::list<Projetil*>::iterator i = projeteisInimigos.begin(); i != projeteisInimigos.end(); ++i)
	{
		(*i)->acao();

		if (EfeitoVisual::getInstance().colisao((*i), principal))
			principal->alvejado((*i)->getDano());

		if (principal->destruido())
		{
			//Explosao
			//Perde uma vida
		}
		else
		{
			principal->acao();
		}
	}
}

void Fase_TheBattleOfBritain::mouse(int button, int state, int x, int y)
{
}

void Fase_TheBattleOfBritain::keyDown(unsigned char key, int x, int y)
{
	switch (key) {
	case 'F':
	case 'f':
		EfeitoVisual::getInstance().setFullScreen();
		break;
	}
}

void Fase_TheBattleOfBritain::keyUp(unsigned char key, int x, int y)
{
    principal->detectaTiro(key, x, y);
}

void Fase_TheBattleOfBritain::specialKeyDown(int key, int x, int y)
{
    principal->detectaMovimentoDown(key, x, y);
}

void Fase_TheBattleOfBritain::specialKeyUp(int key, int x, int y)
{
    principal->detectaMovimentoUp(key, x, y);
}

void Fase_TheBattleOfBritain::inicializa()
{
    definePersonagens();
  //  EfeitoSonoro::getInstance().playSecondLevelTheme();
//    EfeitoSonoro::getInstance().spitfireMotor();
    PontosAgua[0][0] = -265;
    PontosAgua[0][1] = 220;
    PontosAgua[1][0] = 0;
    PontosAgua[1][1] = 150;
    PontosAgua[2][0] = 225;
    PontosAgua[2][1] = 0;
    PontosAgua[3][0] = 265;
    PontosAgua[3][1] = 220;
    PontosAgua[4][0] = -225;
    PontosAgua[4][1] = 0;
    PontosAgua[5][0] = -265;
    PontosAgua[5][1] = -220;
    PontosAgua[6][0] = 0;
    PontosAgua[6][1] = -150;
    PontosAgua[7][0] = 265;
    PontosAgua[7][1] = -220;
    for (int i = 8; i < 16; i++){
        PontosAgua[i][0] = PontosAgua[i - 8][0];
        PontosAgua[i][1] = PontosAgua[i - 8][1] + 570;
    }
}
