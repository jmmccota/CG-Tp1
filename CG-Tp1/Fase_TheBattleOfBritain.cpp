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
	srand(time(NULL));
    boss = nullptr;
}

Fase_TheBattleOfBritain::~Fase_TheBattleOfBritain()
{
    delete principal;
}

void Fase_TheBattleOfBritain::definePersonagens()
{
    pair<float, float> size = EfeitoVisual::getInstance().getOrtho2D();
    principal = new Spitfire(size.first / 2, size.second / 10, (float)100 / 10000, this);
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
    for (int i = 0; i < 16; i++)
    {
        drawWaves(PontosAgua[i][0], PontosAgua[i][1], 0.25);
    }
    if (boss == nullptr)
    {
        drawIsland1(transXIlha1, transYIlha1, 1);
        drawIsland2(transXIlha2, transYIlha2, 1);
    }
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

	for (std::list<Caixa*>::iterator i = caixas.begin(); i != caixas.end(); ++i)
		(*i)->desenha();

    principal->desenha();

    desenhaExplosoes();

	desenhaHUD();

    if (boss != nullptr)
        desenhaHPBoss(boss->getHP(), 6000);
    // Executa os comandos OpenGL
    glutSwapBuffers();
}

void Fase_TheBattleOfBritain::terminou()
{
	EfeitoSonoro::getInstance().finishAllAudios();
	if (Jogo::getInstance().numeroVidas == 0)
		Jogo::getInstance().setProxFase(5);
	else
		Jogo::getInstance().setProxFase(4);
	Jogo::getInstance().proximaFase();
}

void Fase_TheBattleOfBritain::atualiza(int value)
{
	pair<GLint, GLint> size = EfeitoVisual::getInstance().getOrtho2D();

	//Passa de Fase
	if (passouFase) {
		if (principal->venceu()) {
			terminou();
		}
	}

	//Inimigos normais
	if (value < 10000) 
	{
		if (value % 255 == 99)
		{
			Bf109 *aux = new Bf109(rand() % size.first, size.second, (float)100 / 10000, principal, this);
			aux->inverteY();
			inimigosAtivos.push_back(aux);
			EfeitoSonoro::getInstance().playBf109Motor();
		}
		if (value % 600 == 99)
		{
			Me163 *aux2 = new Me163(rand() % size.first, size.second, (float)100 / 10000, principal, this);
			aux2->inverteY();
			inimigosAtivos.push_back(aux2);
			EfeitoSonoro::getInstance().playMe163Motor();
		}
		if (value % 5000 == 9)
		{
			Bf109Verde *aux2 = new Bf109Verde(rand() % size.first, size.second, (float)100 / 10000, principal, this);
			aux2->inverteY();
			inimigosAtivos.push_back(aux2);
		}
	}
	

	//Chefao
	else if (value == 10200)
	{
		boss = new Bismarck(size.first / 2, size.second + 299, (float) 900 / 10000, principal, this);
		inimigosAtivos.push_back(boss);

	}
	else if (value == 17000)
	{
		boss->finaliza();
	}

	for (std::list<Projetil*>::iterator i = projeteisAmigos.begin(); i != projeteisAmigos.end();)
	{
		(*i)->acao();
		if ((*i)->getX() < 0 || (*i)->getX() > size.first || (*i)->getY() < 0 || (*i)->getY() > size.second)
			i = projeteisAmigos.erase(i);
		else
			i++;
	}

	for (std::list<Projetil*>::iterator i = projeteisInimigos.begin(); i != projeteisInimigos.end();)
	{
		(*i)->acao();
		if ((*i)->getX() < 0 || (*i)->getX() > size.first || (*i)->getY() < 0 || (*i)->getY() > size.second)
			i = projeteisInimigos.erase(i);
		else
			i++;
	}

	for (std::list<Personagem*>::iterator i = inimigosAtivos.begin(); i != inimigosAtivos.end();)
	{
		(*i)->acao();
		if ((*i)->getX() < -300 || (*i)->getX() > size.first + 300 || (*i)->getY() < -300 || (*i)->getY() > size.second + 300)
			i = inimigosAtivos.erase(i);
		else
			i++;
	}

	principal->acao();

	//Para os sons dos avioes abatidos
	if (inimigosAtivos.size() == 0)
	{
		EfeitoSonoro::getInstance().stopBf109Motor();
		EfeitoSonoro::getInstance().stopMe163Motor();
	}
	else
	{
		bool bf109 = false, me163 = false;
		for (std::list<Personagem*>::iterator i = inimigosAtivos.begin(); i != inimigosAtivos.end(); ++i)
		{
			if ((*i)->getNome() == "Bf109")
				bf109 = true;
			else if ((*i)->getNome() == "Me163")
				me163 = true;
			if (bf109 && me163)
				break;
		}
		if (!me163)
			EfeitoSonoro::getInstance().stopMe163Motor();
		if (!bf109)
			EfeitoSonoro::getInstance().stopBf109Motor();
	}

	//Bala aliada X Avioes inimigos
	string nome;
	for (std::list<Projetil*>::iterator i = projeteisAmigos.begin(); i != projeteisAmigos.end();)
	{
		bool destruiu = false;
		for (std::list<Personagem*>::iterator j = inimigosAtivos.begin(); j != inimigosAtivos.end();)
		{
			//Se foi alvejado
			nome = (*j)->getNome();
			if (EfeitoVisual::getInstance().colisao((*j), (*i)))
			{
				(*j)->alvejado((*i)->getDano());
				i = projeteisAmigos.erase(i);
				destruiu = true;
			}
			//Se foi destruido
			if ((*j)->destruido())
			{
				explosoesAtivas.push_back(new Explosao((*j)->getX(), (*j)->getY(), 1));
				Jogo::getInstance().score->incScoreValue((*j)->getScore());
				if (nome == "Bf109Verde")
				{
                    caixas.push_back(new Caixa((*j)->getX(), (*j)->getY(), 1));
				}
				else if (nome == "Bismarck")
				{
					passouFase = true;
                }
                j = inimigosAtivos.erase(j);
			}
			//Se ta de boa ainda
			else
				j++;

			if (destruiu)
				break;
		}
		if (!destruiu)
			i++;

	}


	//Bala dos inimigos X Aviao
	for (std::list<Projetil*>::iterator i = projeteisInimigos.begin(); i != projeteisInimigos.end();)
	{
		if (EfeitoVisual::getInstance().colisao((*i), principal))
		{
			principal->alvejado((*i)->getDano());
			i = projeteisInimigos.erase(i);
		}
		else
			++i;

		if (principal->destruido())
		{
			explosoesAtivas.push_back(new Explosao(principal->getX(), principal->getY(), 1));
			principal->powerUp = 0;
			Jogo::getInstance().numeroVidas--;
			principal->morreu();
		}
	}

	//Colisao avioes
	for (std::list<Personagem*>::iterator i = inimigosAtivos.begin(); i != inimigosAtivos.end();)
	{
		if (EfeitoVisual::getInstance().colisao((*i), principal))
		{
			nome = (*i)->getNome();
			if (nome == "Bismarck")
			{
				i++;
				continue;
			}
			principal->alvejado((*i)->danoColisao());
			(*i)->alvejado(principal->danoColisao());
			if (nome == "Me163")
				(*i)->alvejado(1000);
		}

		if ((*i)->destruido())
		{
			if (rand() % 20 == 0)
				principal->powerUp = 1;
			Jogo::getInstance().score->incScoreValue((*i)->getScore());
			if (nome == "bismarck")
			{
				explosoesAtivas.push_back(new Explosao(((*i)->getX() + principal->getX()) / 2, ((*i)->getY() + principal->getY()) / 2, 10));
				//EfeitoSonoro::getInstance().stopMe264Motor();
            }
            else
            {
                if (nome == "Bf109Verde")
                    caixas.push_back(new Caixa((*i)->getX(), (*i)->getY(), 1));

                explosoesAtivas.push_back(new Explosao(((*i)->getX() + principal->getX()) / 2, ((*i)->getY() + principal->getY()) / 2, 2));
            }
			EfeitoSonoro::getInstance().playExplosion();
			i = inimigosAtivos.erase(i);
		}
		else
		{
			++i;
		}

		if (principal->destruido())
		{
			if (nome != "Me163")
				explosoesAtivas.push_back(new Explosao(principal->getX(), principal->getY(), 1));
			principal->powerUp = 0;
			Jogo::getInstance().numeroVidas--;
			principal->morreu();
		}
	}

	for (std::list<Caixa*>::iterator i = caixas.begin(); i != caixas.end();)
	{
		if (EfeitoVisual::getInstance().colisao(*i, principal))
		{
			if ((*i)->tipo == 1)
			{
				principal->municao[1]++;
				principal->powerUp = 1;
			}
			else if ((*i)->tipo == 2)
			{
				principal->morreu();
				Jogo::getInstance().numeroVidas++;
			}
			i = caixas.erase(i);
		}
		else
		{
			i++;
		}
	}

	if (Jogo::getInstance().numeroVidas == 0) {
		terminou();
	}

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
}

void Fase_TheBattleOfBritain::mouse(int button, int state, int x, int y)
{
}

void Fase_TheBattleOfBritain::keyDown(unsigned char key, int x, int y)
{
}

void Fase_TheBattleOfBritain::keyUp(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'F':
	case 'f':
		EfeitoVisual::getInstance().setFullScreen();
		break;
	case 'p':
	case 'P':
		Jogo::getInstance().pausado = !Jogo::getInstance().pausado;
		break;
	default:
		principal->detectaTiro(key, x, y);
	}
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
    reseta();
	EfeitoSonoro::getInstance().initAudios_TheBattleOfBritain();
    EfeitoSonoro::getInstance().playMainTheme();
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
