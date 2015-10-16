#include "Avioes.hpp"


////////////////////////////////////////////////////////////////////////////////////////////////


Spitfire::Spitfire(GLfloat pX, GLfloat pY, float esc, Fase *f)
    : Personagem(pX, pY, 150 * esc, esc, f)
{
    this->carrega("modelos/spitfire.dat");

	numeroVidas = 5;
    hp = 1000;
    municao[0] = 9999999;
    municao[1] = 10;
}


Spitfire::~Spitfire()
{
}

void Spitfire::acao()
{
    /*pair<GLfloat, GLfloat> size = EfeitoVisual::getInstance().getOrtho2D();
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
	}*/

	pair<GLfloat, GLfloat> size = EfeitoVisual::getInstance().getOrtho2D();
	if (posY + velY + tamY < size.second && posY + velY - tamY > 0)
	{
		posY += velY;
	}
	else
	{
		velY = 0;
	}
	if (posX + velX + tamX < size.first && posX + velX - tamX > 0)
	{
		posX += velX;
	}
	else
	{
		velX = 0;
	}

}

void Spitfire::atira(int tipo)
{
    if (municao[tipo] > 0)
    {
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
    /*switch (key)
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
    }*/
}
void Spitfire::detectaMovimentoUp(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        //movCima = false;
        velY += velocidade;
        break;
    case GLUT_KEY_DOWN:
        //movBaixo = false;
        velY -= velocidade;
        break;
    case GLUT_KEY_RIGHT:
        //movDir = false;
        velX += velocidade;
        break;
    case GLUT_KEY_LEFT:
        //movEsq = false;
        velX -= velocidade;
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
        estadoTiro = ++estadoTiro % (int)(1000 / (1 * TEMPOQUADRO));
        if (!estadoTiro) atira(0);
    }
    posY -= velocidade;
}

int Bf109::danoColisao()
{
	return 1;
}

void Bf109::atira(int tipo)
{
    if (municao[tipo] > 0)
    {
        municao[tipo]--;
        fase->novoProjetilInimigo(new TiroSimplesInimigo(posX, posY, 0.1 * escala));
    }
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
	return 30;
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


Me264::Me264(GLfloat pX, GLfloat pY, float esc, Fase *f)
	: Personagem(pX, pY, 0.016 * esc, esc, f)
{
	this->carrega("modelos/me264.dat");
	hp = 40;
	municao[1] = 9999;
	municao[2] = 150;
}
Me264::~Me264()
{
}

void Me264::acao()
{
	if (movCima)
		posY += velocidade;
	else if (movBaixo)
		posY -= velocidade;
	if (movDir)
		posX += velocidade;
	else if (movEsq)
		posX -= velocidade;
}

void Me264::atira(int tipo)
{
	if (municao[tipo] > 0)
	{
		municao[tipo]--;
		if (!tipo)
			fase->novoProjetilInimigo(new TiroSimples(posX, posY + tamY, escala));
		else
			fase->novoProjetilInimigo(new Bomba(posX, posY + tamY, escala));
	}
}

int Me264::danoColisao()
{
	return 2;
}

string Me264::getNome()
{
	return "Me264";
}

int Me264::getScore()
{
	return 5000;
}

////////////////////////////////////////////////////////////////////////////////////////////////


Me262::Me262(GLfloat pX, GLfloat pY, float esc, Fase *f)
	: Personagem(pX, pY, 0.016 * esc, esc, f)
{
	this->carrega("modelos/me262.dat");
	hp = 40;
	municao[1] = 9999;
	municao[2] = 150;
}
Me262::~Me262()
{
}

void Me262::acao()
{
	if (movCima)
		posY += velocidade;
	else if (movBaixo)
		posY -= velocidade;
	if (movDir)
		posX += velocidade;
	else if (movEsq)
		posX -= velocidade;
}

void Me262::atira(int tipo)
{
	if (municao[tipo] > 0)
	{
		municao[tipo]--;
		if (!tipo)
			fase->novoProjetilInimigo(new TiroSimples(posX, posY + tamY, escala));
		else
			fase->novoProjetilInimigo(new Bomba(posX, posY + tamY, escala));
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


V2::V2(GLfloat pX, GLfloat pY, float esc, Fase *f)
	: Personagem(pX, pY, 0 * esc, esc, f)
{
	this->carrega("modelos/v2.dat");
	hp = 9999;
}
V2::~V2()
{
}

void V2::acao()
{
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
	return 10000;
}
