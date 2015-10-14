#include "Avioes.hpp"


////////////////////////////////////////////////////////////////////////////////////////////////


Spitfire::Spitfire(GLfloat pX, GLfloat pY, float esc, Fase *f)
    : Personagem(pX, pY, 250 * esc, esc, f)
{
    this->carrega("modelos/spitfire.dat");
    hp = 99999;
	numeroVidas = 5;
    municao[0] = 9999999;
    municao[1] = 10;
}


Spitfire::~Spitfire()
{
}

void Spitfire::acao()
{
    pair<GLfloat, GLfloat> size = EfeitoVisual::getInstance().getOrtho2D();
    if (movCima && posY + velocidade + tamY < size.second)
        posY += velocidade;
    else if (movBaixo && posY - velocidade - tamY > 0)
        posY -= velocidade;
    if (movDir && posX + velocidade + tamX < size.first)
        posX += velocidade;
    else if (movEsq && posX - velocidade - tamX > 0)
        posX -= velocidade;
    //posY += velY;
    //posX += velX;
}

void Spitfire::atira(int tipo)
{
    if (municao[tipo] > 0)
    {
        municao[tipo]--;
        if (!tipo)
        {
            EfeitoSonoro::getInstance().vickersShot();
            fase->novoProjetilAmigo(new TiroSimples(posX, posY + tamY * escala, 0.1 * escala));
        }
        else
        {
            EfeitoSonoro::getInstance().bombDrop();
            fase->novoProjetilAmigo(new Bomba(posX, posY + tamY * escala, 0.2 * escala));
        }
    }
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
        //velY += 1;
        break;
    case GLUT_KEY_DOWN:
        movBaixo = false;
        //velY -= 1;
        break;
    case GLUT_KEY_RIGHT:
        movDir = false;
        //velX += 1;
        break;
    case GLUT_KEY_LEFT:
        movEsq = false;
        //velX -= 1;
        break;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////


Bf109::Bf109(GLfloat pX, GLfloat pY, float esc, Personagem *a, Fase *f)
    : Personagem(pX, pY, 100*esc, esc, f)
{
    alvo = a;
    carrega("modelos/bf109.dat");
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

        //Atira 3 vezes por segundo caso esteja em posicao
        estadoTiro = ++estadoTiro % (int)(1000 / (3 * TEMPOQUADRO));
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


////////////////////////////////////////////////////////////////////////////////////////////////


Me163::Me163(GLfloat pX, GLfloat pY, float esc, Personagem *a, Fase *f) : Personagem(pX, pY, 400*esc, esc, f)
{
    alvo = a;
    carrega("modelo/me163.dat");
    hp = 20;
    municao[0] = 0;
    municao[1] = 0;
    velocidadeX = 400 * esc;
    velocidadeY = 100 * esc;
}


Me163::~Me163()
{
}


void Me163::acao()
{
    posX += (alvo->getX() - posX > 0 ? velocidadeX : -velocidadeX);
    posY -= velocidadeY;
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
