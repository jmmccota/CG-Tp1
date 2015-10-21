#include "Avioes.hpp"


////////////////////////////////////////////////////////////////////////////////////////////////


Spitfire::Spitfire(GLfloat pX, GLfloat pY, float esc, Fase *f)
    : Personagem(pX, pY, 250 * esc, esc, f)
{
    this->carrega("modelos/spitfire.dat");

	numeroVidas = 5;
    hp = VIDA_SPITFIRE;
    municao[0] = 9999999;
    municao[1] = nBomba;
}


Spitfire::~Spitfire()
{
}

void Spitfire::acao()
{
    pair<GLfloat, GLfloat> size = EfeitoVisual::getInstance().getOrtho2D();
    if (movCima && posY + velY + tamY < size.second)
	{
        posY += velocidade;
	}
    else if (movBaixo && posY + velY - tamY > 0)
	{
        posY -= velocidade;
	}
	if (movDir && posX + velX + tamX < size.first)
	{
		posX += velocidade;
	}
	else if (movEsq && posX + velX - tamX > 0)
	{
		posX -= velocidade;
	}

	//pair<GLfloat, GLfloat> size = EfeitoVisual::getInstance().getOrtho2D();
	//if (posY + velY + tamY < size.second && posY + velY - tamY > 0)
	//{
	//	posY += velY;
	//}
	//else
	//{
	//	velY = 0;
	//}
	//if (posX + velX + tamX < size.first && posX + velX - tamX > 0)
	//{
	//	posX += velX;
	//}
	//else
	//{
	//	velX = 0;
	//}

}

void Spitfire::atira(int tipo)
{
    if (municao[tipo] > 0)
    {
		//if bomba=true && tipo==1 nao diminui
        municao[tipo]--;
        if (!tipo)
        {
            EfeitoSonoro::getInstance().playVickersShot();
			if (powerUp == 0)
			{
				fase->novoProjetilAmigo(new TiroSimples(posX, posY + tamY * escala, 0.1 * escala));
			}
			else if (powerUp == 1)
			{
				fase->novoProjetilAmigo(new TiroSimples(posX - (int)(tamX / 2), posY + tamY * escala, 0.1 * escala));
				fase->novoProjetilAmigo(new TiroSimples(posX + (int)(tamX / 2), posY + tamY * escala, 0.1 * escala));
			}
        }
        else
        {
            EfeitoSonoro::getInstance().playBombDrop();
            fase->novoProjetilAmigo(new Bomba(posX, posY + tamY * escala, 0.25 * escala));
        }
    }
}

int Spitfire::danoColisao()
{
	return 1;
}

void Spitfire::morreu()
{
    hp = VIDA_SPITFIRE;
}

bool Spitfire::venceu()
{
	bool termina = false;
	posY += velocidade;
	if (posY >= 1080) {
		termina = true;
	}
	return termina;
}

string Spitfire::getNome()
{
	return "Spitfire";
}

int Spitfire::getScore()
{
	return 0;
}
GLfloat Spitfire::getX() {
	return posX;
}
GLfloat Spitfire::getY() {
	return posY;
}
void Spitfire::detectaTiro(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'z':
    case 'Z':
        atira(0);
        break;
    case 'x':
    case 'X':
        atira(1);
        break;
    }
}
void Spitfire::detectaMovimentoDown(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        movCima = true;
        break;
    case GLUT_KEY_DOWN:
        movBaixo = true;
        break;
    case GLUT_KEY_RIGHT:
        movDir = true;
        break;
    case GLUT_KEY_LEFT:
        movEsq = true;
        break;
    }
}
void Spitfire::detectaMovimentoUp(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        movCima = false;
        //velY += velocidade;
        break;
    case GLUT_KEY_DOWN:
        movBaixo = false;
        //velY -= velocidade;
        break;
    case GLUT_KEY_RIGHT:
        movDir = false;
        //velX += velocidade;
        break;
    case GLUT_KEY_LEFT:
        movEsq = false;
        //velX -= velocidade;
        break;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////


Bf109::Bf109(GLfloat pX, GLfloat pY, float esc, Personagem *a, Fase *f)
    : Personagem(pX, pY, 100*esc, esc, f)
{
    alvo = a;
    this->carrega("modelos/bf109.dat");
    hp = 30;
    municao[0] = 999;
    municao[1] = 0;
}


Bf109::~Bf109()
{
}

void Bf109::acao()
{
    //Se ainda esta "longe" do alvo
    if (abs(alvo->getX() - posX) > (tamX + tamX + tamX))
    {
        posX += (alvo->getX() - posX > 0 ? velocidade : -velocidade);
    }
    //Se esta perto do alvo
    else
    {
        posX += (alvo->getX() - posX > 0 ? velocidade / 1.5 : -velocidade / 1.5);

        //Atira 2 vezes por segundo caso esteja em posicao
        estadoTiro = ++estadoTiro % (int)(1000 / (tirosSegundo * TEMPOQUADRO));
        if (!estadoTiro) atira(0);
    }
    posY -= velocidade;
}

void Bf109::atira(int tipo)
{
    if (municao[tipo] > 0)
    {
        municao[tipo]--;
        fase->novoProjetilInimigo(new TiroSimplesInimigo(posX, posY, 0.1 * escala));
    }
}

int Bf109::danoColisao()
{
	return 1;
}

string Bf109::getNome()
{
	return "Bf109";
}

int Bf109::getScore()
{
	return 100;
}


////////////////////////////////////////////////////////////////////////////////////////////////


Me163::Me163(GLfloat pX, GLfloat pY, float esc, Personagem *a, Fase *f) : Personagem(pX, pY, 400*esc, esc, f)
{
    alvo = a;
    this->carrega("modelos/me163.dat");
    hp = 20;
    municao[0] = 0;
    municao[1] = 0;
    velocidadeX = 100 * esc;
    velocidadeY = 400 * esc;
}


Me163::~Me163()
{
}


void Me163::acao()
{
    posX += (alvo->getX() - posX > 0 ? velocidadeX : -velocidadeX);
    posY -= velocidadeY;
}

void Me163::atira(int tipo)
{
}

int Me163::danoColisao()
{
	return 1000;
}

string Me163::getNome()
{
	return "Me163";
}

int Me163::getScore()
{
	return 150;
}

////////////////////////////////////////////////////////////////////////////////////////////////


Me262::Me262(GLfloat pX, GLfloat pY, float esc, Spitfire *a, Fase *f)
    : Personagem(pX, pY, 350 * esc, esc, f)
{
    this->carrega("modelos/me262.dat");
    hp = 40;
    municao[1] = 9999;
    municao[2] = 150;
    alvo = a;
    alvoX = alvo->getX();
    alvoY = alvo->getY();
    int teta = atan((alvoY - posY) / (alvoX - posX));
    if (alvoX < posX)
        teta = teta + 3.14159;
    velX = cos(teta) * velocidade;
    velY = sin(teta) * velocidade;
}
Me262::~Me262()
{
}

void Me262::acao()
{
    posX += velX;
    posY += velY;

    if (!estadoTiro)
        contadorEst = ++contadorEst % 10;
    if (!contadorEst)
        estrategia = rand() % 10;
    if (estrategia)
        estrategia = 1;

    atira(estrategia);
}

void Me262::atira(int tipo)
{
    //Solta bomba
    if (tipo == 0)
    {
        estadoTiro = ++estadoTiro % (int)(1000 / (tirosSegundo * TEMPOQUADRO));
        if (!estadoTiro)
        {
            EfeitoSonoro::getInstance().playBombDrop();
            Bomba *b = new Bomba(posX, posY, 0.25
                * escala);
            if (girou)
                b->gira();
            if (inverteuY)
                b->inverteY();
            if (inverteuX)
                b->inverteX();
            fase->novoProjetilInimigo(b);
        }
    }
    //Atira
    else if (tipo == 1)
    {
        float x = alvo->getX();
        float y = alvo->getY();
        estadoTiro = ++estadoTiro % (int)(1000 / (tirosSegundo * TEMPOQUADRO));
        if (!estadoTiro &&
            (  (!girou && inverteuY && y < posY)  ||
               (!girou && !inverteuY && y > posY) ||
               (girou && inverteuX && x < posX)   ||
               (girou && !inverteuX && x > posX)))
        {
            EfeitoSonoro::getInstance().playMg42Shot();
            fase->novoProjetilInimigo(new TiroEspecialInimigo(posX, posY, alvo->getX(), alvo->getY(), 0.25 * escala, 1000 * escala));
        }
    }
}

int Me262::danoColisao()
{
    return 1;
}

string Me262::getNome()
{
    return "Me262";
}

int Me262::getScore()
{
    return 3000;
}


////////////////////////////////////////////////////////////////////////////////////////////////


Me264::Me264(GLfloat pX, GLfloat pY, float esc, Personagem *a, Fase *f)
	: Personagem(pX, pY, 5 * esc, esc, f)
{
	this->carrega("modelos/me264.dat");
    alvo = a;
	hp = 3000;
	municao[0] = 9999;
	municao[1] = 9999;
    velocidadeBala = 60 * escala;
}
Me264::~Me264()
{
}

void Me264::acao()
{
    if (posY + tamY - 100 > EfeitoVisual::getInstance().getOrtho2D().second)
    {
        posY -= velocidade;
        return;
    }

    if (!estadoTiro)
        contadorEst = ++contadorEst % 10;
    if (!contadorEst)
        estrategia = rand() % 5;
    if (estrategia > 3)
        estrategia = 2;

    atira(estrategia);
}

void Me264::atira(int tipo)
{
    //Solta bomba
    if (tipo == 1)
    {
        estadoTiro = ++estadoTiro % (int)(1000 / (tirosSegundo * TEMPOQUADRO));
        if (!estadoTiro)
        {
            EfeitoSonoro::getInstance().playBombDrop();
            fase->novoProjetilInimigo(new Bomba(posX + ladoBomba * escala * 300, posY, - 0.05 * escala));
            ladoBomba = -ladoBomba;
        }
    }
    //Atira
    else if (tipo == 2)
    {
        estadoTiro = ++estadoTiro % (int)(1000 / (tirosSegundo * TEMPOQUADRO));
        if (!estadoTiro)
        {
            EfeitoSonoro::getInstance().playMg42Shot();
            fase->novoProjetilInimigo(new TiroEspecialInimigo(posX, posY, alvo->getX(), alvo->getY(), 0.02 * escala, velocidadeBala));
        }
    }
    else if (tipo == 3)
    {
        estadoTiro = ++estadoTiro % (int)(1000 / (2 * tirosSegundo * TEMPOQUADRO));
        if (!estadoTiro)
        {
            EfeitoSonoro::getInstance().playMg42Shot();
            fase->novoProjetilInimigo(new TiroEspecialInimigo(posX, posY, alvo->getX(), alvo->getY(), 0.03 * escala, 0.6 * velocidadeBala));
        }
    }
}

int Me264::danoColisao()
{
	return 0;
}

string Me264::getNome()
{
	return "Me264";
}

int Me264::getScore()
{
	return 5000;
}

void Me264::finaliza()
{
    tirosSegundo *= 4;
    velocidadeBala *= 2;
}

////////////////////////////////////////////////////////////////////////////////////////////////


Bismarck::Bismarck(GLfloat pX, GLfloat pY, float esc, Spitfire *a, Fase *f)
    : Personagem(pX, pY, 3 * esc, esc, f)
{
    this->carrega("modelos/bismarck.dat");
	alvo = a;
    hp = 6000;
    municao[0] = 9999;
    municao[1] = 9999;
    velocidadeBala = 60 * escala;
}
Bismarck::~Bismarck()
{
}

void Bismarck::acao()
{
    if (posY + tamY - 100 > EfeitoVisual::getInstance().getOrtho2D().second)
    {
        posY -= velocidade;
        return;
    }

    if (!estadoTiro)
        contadorEst = ++contadorEst % 10;
    if (!contadorEst)
        estrategia = rand() % 5 + 1;

    atira(estrategia);
}

void Bismarck::atira(int tipo)
{
    float escalaReal = escala * 10000;
    //Solta bomba
    if (tipo == 1)
    {
        estadoTiro = ++estadoTiro % (int)(1000 / (tirosSegundo * TEMPOQUADRO));
        if (!estadoTiro)
        {
            EfeitoSonoro::getInstance().playBombDrop();
            fase->novoProjetilInimigo(new Bomba(-0.36 * escalaReal + posX, -0.05 * escalaReal + posY, -0.03 * escala));
            fase->novoProjetilInimigo(new Bomba(-0.39 * escalaReal + posX, -0.05 * escalaReal + posY, -0.03 * escala));
            fase->novoProjetilInimigo(new Bomba(-0.49 * escalaReal + posX, -0.05 * escalaReal + posY, -0.03 * escala));
            fase->novoProjetilInimigo(new Bomba(-0.52 * escalaReal + posX, -0.05 * escalaReal + posY, -0.03 * escala));
            fase->novoProjetilInimigo(new Bomba(0.53 * escalaReal + posX, -0.05 * escalaReal + posY, -0.03 * escala));
            fase->novoProjetilInimigo(new Bomba(0.49 * escalaReal + posX, -0.05 * escalaReal + posY, -0.03 * escala));
            fase->novoProjetilInimigo(new Bomba(0.66 * escalaReal + posX, -0.05 * escalaReal + posY, -0.03 * escala));
            fase->novoProjetilInimigo(new Bomba(0.63 * escalaReal + posX, -0.05 * escalaReal + posY, -0.03 * escala));
        }
    }
    //Atira
    else if (tipo == 2)
    {
        estadoTiro = ++estadoTiro % (int)(1000 / (tirosSegundo * TEMPOQUADRO));
        if (!estadoTiro)
        {
            EfeitoSonoro::getInstance().playMg42Shot();
            fase->novoProjetilInimigo(new TiroEspecialInimigo(-0.36 * escalaReal + posX, -0.05 * escalaReal + posY, alvo->getX(), alvo->getY(), 0.02 * escala, 0.7 * velocidadeBala));
            fase->novoProjetilInimigo(new TiroEspecialInimigo(-0.39 * escalaReal + posX, -0.05 * escalaReal + posY, alvo->getX(), alvo->getY(), 0.02 * escala, 0.7 * velocidadeBala));
            fase->novoProjetilInimigo(new TiroEspecialInimigo(-0.49 * escalaReal + posX, -0.05 * escalaReal + posY, alvo->getX(), alvo->getY(), 0.02 * escala, 0.7 * velocidadeBala));
            fase->novoProjetilInimigo(new TiroEspecialInimigo(-0.52 * escalaReal + posX, -0.05 * escalaReal + posY, alvo->getX(), alvo->getY(), 0.02 * escala, 0.7 * velocidadeBala));
        }
    }
    else if (tipo == 3)
    {
        estadoTiro = ++estadoTiro % (int)(1000 / (tirosSegundo * TEMPOQUADRO));
        if (!estadoTiro)
        {
            EfeitoSonoro::getInstance().playMg42Shot();
            fase->novoProjetilInimigo(new TiroEspecialInimigo(0.53 * escalaReal + posX, -0.05 * escalaReal + posY, alvo->getX(), alvo->getY(), 0.02 * escala, 0.7 * velocidadeBala));
            fase->novoProjetilInimigo(new TiroEspecialInimigo(0.49 * escalaReal + posX, -0.05 * escalaReal + posY, alvo->getX(), alvo->getY(), 0.02 * escala, 0.7 * velocidadeBala));
            fase->novoProjetilInimigo(new TiroEspecialInimigo(0.66 * escalaReal + posX, -0.05 * escalaReal + posY, alvo->getX(), alvo->getY(), 0.02 * escala, 0.7 * velocidadeBala));
            fase->novoProjetilInimigo(new TiroEspecialInimigo(0.63 * escalaReal + posX, -0.05 * escalaReal + posY, alvo->getX(), alvo->getY(), 0.02 * escala, 0.7 * velocidadeBala));
        }
    }
    else if (tipo == 4)
    {
        estadoTiro = ++estadoTiro % (int)(1000 / (tirosSegundo * TEMPOQUADRO));
        if (!estadoTiro)
        {
            EfeitoSonoro::getInstance().playMg42Shot();
            fase->novoProjetilInimigo(new TiroSimplesInimigo(-0.36 * escalaReal + posX, -0.05 * escalaReal + posY, -0.05 * escala));
            fase->novoProjetilInimigo(new TiroSimplesInimigo(-0.39 * escalaReal + posX, -0.05 * escalaReal + posY, -0.05 * escala));
            fase->novoProjetilInimigo(new TiroSimplesInimigo(-0.49 * escalaReal + posX, -0.05 * escalaReal + posY, -0.05 * escala));
            fase->novoProjetilInimigo(new TiroSimplesInimigo(-0.52 * escalaReal + posX, -0.05 * escalaReal + posY, -0.05 * escala));
            fase->novoProjetilInimigo(new TiroSimplesInimigo(0.53 * escalaReal + posX, -0.05 * escalaReal + posY, -0.05 * escala));
            fase->novoProjetilInimigo(new TiroSimplesInimigo(0.49 * escalaReal + posX, -0.05 * escalaReal + posY, -0.05 * escala));
            fase->novoProjetilInimigo(new TiroSimplesInimigo(0.66 * escalaReal + posX, -0.05 * escalaReal + posY, -0.05 * escala));
            fase->novoProjetilInimigo(new TiroSimplesInimigo(0.63 * escalaReal + posX, -0.05 * escalaReal + posY, -0.05 * escala));
        }
    }
    else if (tipo == 5)
    {
        estadoTiro = ++estadoTiro % (int)(1000 / (tirosSegundo * TEMPOQUADRO));
        if (!estadoTiro)
        {
            EfeitoSonoro::getInstance().playMg42Shot();
            fase->novoProjetilInimigo(new TiroEspecialInimigo(0.53 * escalaReal + posX, -0.05 * escalaReal + posY, alvo->getX(), alvo->getY(), 0.02 * escala, 0.7 * velocidadeBala));
            fase->novoProjetilInimigo(new TiroEspecialInimigo(0.49 * escalaReal + posX, -0.05 * escalaReal + posY, alvo->getX(), alvo->getY(), 0.02 * escala, 0.7 * velocidadeBala));
            fase->novoProjetilInimigo(new TiroEspecialInimigo(0.66 * escalaReal + posX, -0.05 * escalaReal + posY, alvo->getX(), alvo->getY(), 0.02 * escala, 0.7 * velocidadeBala));
            fase->novoProjetilInimigo(new TiroEspecialInimigo(0.63 * escalaReal + posX, -0.05 * escalaReal + posY, alvo->getX(), alvo->getY(), 0.02 * escala, 0.7 * velocidadeBala));
            fase->novoProjetilInimigo(new TiroEspecialInimigo(-0.36 * escalaReal + posX, -0.05 * escalaReal + posY, alvo->getX(), alvo->getY(), 0.02 * escala, 0.7 * velocidadeBala));
            fase->novoProjetilInimigo(new TiroEspecialInimigo(-0.39 * escalaReal + posX, -0.05 * escalaReal + posY, alvo->getX(), alvo->getY(), 0.02 * escala, 0.7 * velocidadeBala));
            fase->novoProjetilInimigo(new TiroEspecialInimigo(-0.49 * escalaReal + posX, -0.05 * escalaReal + posY, alvo->getX(), alvo->getY(), 0.02 * escala, 0.7 * velocidadeBala));
            fase->novoProjetilInimigo(new TiroEspecialInimigo(-0.52 * escalaReal + posX, -0.05 * escalaReal + posY, alvo->getX(), alvo->getY(), 0.02 * escala, 0.7 * velocidadeBala));
        }
    }
}

int Bismarck::danoColisao()
{
    return 0;
}

string Bismarck::getNome()
{
    return "Bismarck";
}

int Bismarck::getScore()
{
    return 10000;
}

void Bismarck::finaliza()
{
    tirosSegundo *= 4;
    velocidadeBala *= 2;
}

////////////////////////////////////////////////////////////////////////////////////////////////


V2::V2(GLfloat pX, GLfloat pY, float esc, Fase *f)
	: Personagem(pX, pY, 5 * esc, esc, f)
{
	this->carrega("modelos/v2.dat");
	hp = 1800;
}
V2::~V2()
{
}

void V2::acao()
{
    if (posY + tamY - 100 > EfeitoVisual::getInstance().getOrtho2D().second)
    {
        posY -= velocidade;
        return;
    }
}

void V2::atira(int tipo)
{
}

int V2::danoColisao()
{
	return 3;
}

string V2::getNome()
{
	return "V2";
}

int V2::getScore()
{
	return 15000;
}

void V2::finaliza()
{

}