#include "Fase_TheBlitz.hpp"
float escalaGeral = 0.25;
float tX = -2880;
float tY = -1620;
float rot = 0;
float transladaCena2 = 0;
float translY = 0;
float escalaBomba = 0;

Fase_TheBlitz::Fase_TheBlitz()
{
	srand(time(NULL));
}

Fase_TheBlitz::~Fase_TheBlitz()
{
	delete principal;
}

void Fase_TheBlitz::definePersonagens()
{
	pair<float, float> size = EfeitoVisual::getInstance().getOrtho2D();
	principal = new Spitfire(size.first / 2, size.second / 10, (float)100 / 10000, this);
}

void Fase_TheBlitz::desenhaBackground()
{
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	transladaCena2 -= 3;
	if (transladaCena2 <= -3240)
		transladaCena2 = 0;
	for (int i = 0; i < 32; i++) {

		switch (i)
		{
		case 0:
			tX = -2880;
			tY = -1620;
			break;
		case 1:
			tX = -960;
			tY = -1620;
			break;
		case 2:
			tX = 960;
			tY = -1620;
			break;
		case 3:
			tX = 2880;
			tY = -1620;
			break;
		case 4:
			tX = -2880;
			tY = -540;
			break;
		case 5:
			tX = -960;
			tY = -540;
			break;
		case 6:
			tX = 960;
			tY = -540;
			break;
		case 7:
			tX = 2880;
			tY = -540;
			break;
		case 8:
			tX = -2880;
			tY = 540;
			break;
		case 9:
			tX = -960;
			tY = 540;
			break;
		case 10:
			tX = 960;
			tY = 540;
			break;
		case 11:
			tX = 2880;
			tY = 540;
			break;
		case 12:
			tX = -2880;
			tY = 1620;
			break;
		case 13:
			tX = -960;
			tY = 1620;
			break;
		case 14:
			tX = 960;
			tY = 1620;
			break;
		case 15:
			tX = 2880;
			tY = 1620;
			break;
		case 16:
			tX = -2880;
			tY = -1620 + 3240;
			break;
		case 17:
			tX = -960;
			tY = -1620 + 3240;
			break;
		case 18:
			tX = 960;
			tY = -1620 + 3240;
			break;
		case 19:
			tX = 2880;
			tY = -1620 + 3240;
			break;
		case 20:
			tX = -2880;
			tY = -540 + 3240;
			break;
		case 21:
			tX = -960;
			tY = -540 + 3240;
			break;
		case 22:
			tX = 960;
			tY = -540 + 3240;
			break;
		case 23:
			tX = 2880;
			tY = -540 + 3240;
			break;
		case 24:
			tX = -2880;
			tY = 540 + 3240;
			break;
		case 25:
			tX = -960;
			tY = 540 + 3240;
			break;
		case 26:
			tX = 960;
			tY = 540 + 3240;
			break;
		case 27:
			tX = 2880;
			tY = 540 + 3240;
			break;
		case 28:
			tX = -2880;
			tY = 1620 + 3240;
			break;
		case 29:
			tX = -960;
			tY = 1620 + 3240;
			break;
		case 30:
			tX = 960;
			tY = 1620 + 3240;
			break;
		case 31:
			tX = 2880;
			tY = 1620 + 3240;
		}

		EfeitoVisual::getInstance().desenhaQuarteirao(1, 1 + transladaCena2, 1 * escalaGeral, 1 * escalaGeral, 0.098, 0.098, 0.098, 540, 960, tX, tY);
		//desenha casas
		EfeitoVisual::getInstance().desenhaRetangulo(-100 + (tX / 3), 100 + (tY / 3) + (transladaCena2 / 3), 3 * escalaGeral, 3 * escalaGeral, rot, 0.098, 0.098, 0.098);
		EfeitoVisual::getInstance().desenhaRetangulo(-230 + (tX / 3), 100 + (tY / 2) + (transladaCena2 / 2), 3 * escalaGeral, 2 * escalaGeral, rot, 0.098, 0.098, 0.098);
		EfeitoVisual::getInstance().desenhaRetangulo(-450 + (tX / 1.6), -90 + (tY / 3) + (transladaCena2 / 3), 1.6*escalaGeral, 3 * escalaGeral, rot, 0.098, 0.098, 0.098);
		EfeitoVisual::getInstance().desenhaRetangulo(-120 + (tX / 2.3), -90 + (tY / 3) + (transladaCena2 / 3), 2.3*escalaGeral, 3 * escalaGeral, rot, 0.098, 0.098, 0.098);
		EfeitoVisual::getInstance().desenhaRetangulo(120 + (tX / 3), -400 + (tY)+(transladaCena2), 3 * escalaGeral, 1 * escalaGeral, rot, 0.098, 0.098, 0.098);
		EfeitoVisual::getInstance().desenhaRetangulo(90 + (tX / 5), -100 + (tY / 2) + (transladaCena2 / 2), 5 * escalaGeral, 2 * escalaGeral, rot, 0.098, 0.098, 0.098);
		EfeitoVisual::getInstance().desenhaRetangulo(100 + (tX / 5), 75 + (tY / 4) + (transladaCena2 / 4), 5 * escalaGeral, 4 * escalaGeral, rot, 0.098, 0.098, 0.098);
		//desenha linha asfalto
		EfeitoVisual::getInstance().desenhaLinhaAsfalto(1, 1 + transladaCena2, 1 * escalaGeral, 1 * escalaGeral, 0.1, 0.1, 0.1, 540, 960, tX, tY);
		// desenha carros
		EfeitoVisual::getInstance().desenhaRetangulo(70 + (tX / 0.8), -200 + (tY)+(transladaCena2), 0.8*escalaGeral, 1 * escalaGeral, rot, 0.13, 0.07, 0.14);
		EfeitoVisual::getInstance().desenhaRetangulo(120 + (tX / 0.5), -250 + (tY / 0.8) + (transladaCena2 / 0.8), 0.5*escalaGeral, 0.8*escalaGeral, rot, 0, 0, 0);
		EfeitoVisual::getInstance().desenhaRetangulo(200 + (tX / 0.3), -400 + (tY / 0.5) + (transladaCena2 / 0.5), 0.3*escalaGeral, 0.5*escalaGeral, rot, 0.13, 0.07, 0.14);
		EfeitoVisual::getInstance().desenhaRetangulo(-400 + (tX / 1.45), -60 + (tY / 0.45) + (transladaCena2 / 0.45), 1.45*escalaGeral, 0.45*escalaGeral, rot, 0.13, 0.07, 0.14);
		EfeitoVisual::getInstance().desenhaRetangulo(-585 + (tX), -80 + (tY / 0.3) + (transladaCena2 / 0.3), 1 * escalaGeral, 0.3*escalaGeral, rot, 0, 0, 0);
		EfeitoVisual::getInstance().desenhaRetangulo(-730 + (tX / 0.8), -115 + (tY / 0.2) + (transladaCena2 / 0.2), 0.8*escalaGeral, 0.2*escalaGeral, rot, 0.13, 0.07, 0.14);
	}
	glPopMatrix();
}

void Fase_TheBlitz::desenha()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.05, 0.05, 0.05, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	desenhaBackground();

	EfeitoVisual::getInstance().ortho2D();

	for (std::list<Projetil*>::iterator i = projeteisAmigos.begin(); i != projeteisAmigos.end(); ++i)
		(*i)->desenha();

	for (std::list<Projetil*>::iterator i = projeteisInimigos.begin(); i != projeteisInimigos.end(); ++i)
		(*i)->desenha();

	principal->desenha();

	for (std::list<Personagem*>::iterator i = inimigosAtivos.begin(); i != inimigosAtivos.end(); ++i)
		(*i)->desenha();

	desenhaExplosoes();

	desenhaHUD();
	if (bossOn) {
		desenhaHPBoss();
	}
	/*if (gameOver || fimDeJogo) {
		desenhaGameOver();
	}*/
	// Executa os comandos OpenGLhh
	glutSwapBuffers();
}

void Fase_TheBlitz::terminou()
{
	EfeitoSonoro::getInstance().finishAllAudios();
	if (Jogo::getInstance().numeroVidas == 0)
	{
		Jogo::getInstance().setProxFase(5);
	}
	else {
		Jogo::getInstance().setProxFase(3);
	}
	Jogo::getInstance().proximaFase();
}

void Fase_TheBlitz::atualiza(int value)
{
	pair<GLint, GLint> size = EfeitoVisual::getInstance().getOrtho2D();

	//Passa de Fase
	if (passouFase) {
		if (principal->venceu()) {
			terminou();
		}
	}

	//Inimigos normais
	if (value % 300 == 99 && value < 10000)
	{
		Bf109 *aux = new Bf109(rand() % size.first, size.second, (float)100 / 10000, principal, this);
		aux->inverteY();
		inimigosAtivos.push_back(aux);
		EfeitoSonoro::getInstance().playBf109Motor();
		if (value % 700 == 99)
		{
			Me163 *aux2 = new Me163(rand() % size.first, size.second, (float)100 / 10000, principal, this);
			aux2->inverteY();
			inimigosAtivos.push_back(aux2);
			EfeitoSonoro::getInstance().playMe163Motor();
		}
	}

	//Chefao
	else if (value == 10300)
	{
		boss = new Me264(size.first / 2, size.second + 299, (float)600 / 10000, principal, this);
		inimigosAtivos.push_back(boss);
		EfeitoSonoro::getInstance().playMe264Motor();
		bossOn = true;

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
	for (std::list<Projetil*>::iterator i = projeteisAmigos.begin(); i != projeteisAmigos.end();)
	{
		bool destruiu = false;
		for (std::list<Personagem*>::iterator j = inimigosAtivos.begin(); j != inimigosAtivos.end();)
		{
			//Se foi alvejado
			if (EfeitoVisual::getInstance().colisao((*j), (*i)))
			{
				(*j)->alvejado((*i)->getDano());
				i = projeteisAmigos.erase(i);
				destruiu = true;
			}
			//Se foi destruido
			if ((*j)->destruido())
			{
				if ((*j)->getNome() == "Me264") {
					passouFase = true;
				}

				explosoesAtivas.push_back(new Explosao((*j)->getX(), (*j)->getY(), 1));
				Jogo::getInstance().score->incScoreValue((*j)->getScore());
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
			if (Jogo::getInstance().numeroVidas == 0) {
				EfeitoSonoro::getInstance().stopSpitfireMotor();
				EfeitoSonoro::getInstance().stopBf109Motor();
				EfeitoSonoro::getInstance().stopMe163Motor();
				Jogo::getInstance().setProxFase(5);
				Jogo::getInstance().proximaFase();
			}
			principal->morreu();
		}
	}

	string nome;
	//Colisao avioes
	for (std::list<Personagem*>::iterator i = inimigosAtivos.begin(); i != inimigosAtivos.end();)
	{
		if (EfeitoVisual::getInstance().colisao((*i), principal))
		{
			nome = (*i)->getNome();
			if (nome == "Me264")
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
			if (nome == "Me264")
			{
				explosoesAtivas.push_back(new Explosao(((*i)->getX() + principal->getX()) / 2, ((*i)->getY() + principal->getY()) / 2, 5));
				//EfeitoSonoro::getInstance().stopMe264Motor();
			}
			else
				explosoesAtivas.push_back(new Explosao(((*i)->getX() + principal->getX()) / 2, ((*i)->getY() + principal->getY()) / 2, 2));
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
			terminou();
			principal->morreu();
		}
	}
}
void Fase_TheBlitz::desenhaHPBoss() {
	if (bossOn && boss->getHP() > 0) {
		//glRasterPos2f(1600, 970);
		int hp = 1000 * boss->getHP() / 3000;
		glBegin(GL_LINE_LOOP);
		glColor3f(1, 1, 1);
		glVertex2i(1450, 1050);
		glVertex2i(1850, 1050);
		glVertex2i(1850, 1020);
		glVertex2i(1450, 1020);
		glEnd();
		double partes = 0.4;
		glBegin(GL_QUADS);
		glColor3f(1, 0, 0);
		glVertex2f(1451, 1049);
		if ((partes*hp + 1450) > 1451) {
			glVertex2f(partes*hp + 1450, 1049);
			glVertex2f(partes*hp + 1450, 1021);
		}
		else {
			glVertex2f(1451, 1049);
			glVertex2f(1451, 1021);
		}
		glVertex2f(1451, 1021);
		glEnd();
	}
}
void Fase_TheBlitz::mouse(int button, int state, int x, int y)
{
}

void Fase_TheBlitz::keyDown(unsigned char key, int x, int y)
{

}

void Fase_TheBlitz::keyUp(unsigned char key, int x, int y)
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
	reseta();
	EfeitoSonoro::getInstance().initAudios_TheBlitz();
	EfeitoSonoro::getInstance().playMainTheme();
	definePersonagens();
	EfeitoSonoro::getInstance().playAirRaid();
	EfeitoSonoro::getInstance().playSpitfireMotor();
}

