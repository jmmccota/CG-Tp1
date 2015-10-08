#include "Avioes.hpp"


////////////////////////////////////////////////////////////////////////////////////////////////


Spitfire::Spitfire(GLfloat pX, GLfloat pY, float esc, Fase *f)
    : Personagem(pX, pY, 0.016 * esc, esc, f)
{
    this->carrega("modelos/spitfire.dat");
    hp = 40;
    municao[1] = 300;
    municao[2] = 2;
}


Spitfire::~Spitfire()
{
}

void Spitfire::acao()
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

void Spitfire::atira(int tipo)
{
    if (municao[tipo] > 0)
    {
        municao[tipo]--;
        if (!tipo)
            fase->novoProjetil(new TiroSimples(posX, posY + tamY, escala));
        else
            fase->novoProjetil(new Bomba(posX, posY + tamY, escala));
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
    case GLUT_KEY_LEFT:
        movEsq = true;
        break;
    case GLUT_KEY_RIGHT:
        movDir = true;
        break;
    }
}
void Spitfire::detectaMovimentoUp(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        movCima = false;
        break;
    case GLUT_KEY_DOWN:
        movBaixo = false;
        break;
    case GLUT_KEY_LEFT:
        movEsq = false;
        break;
    case GLUT_KEY_RIGHT:
        movDir = false;
        break;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////


Bf109::Bf109(GLfloat pX, GLfloat pY, float esc, Personagem *a, Fase *f)
    : Personagem(pX, pY, 0.01*esc, esc, f)
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
        fase->novoProjetil(new TiroSimplesInimigo(posX, posY + tamY, escala));
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////


Me163::Me163(GLfloat pX, GLfloat pY, float esc, Personagem *a, Fase *f) : Personagem(pX, pY, 0.025*esc, esc, f)
{
    alvo = a;
    carrega("modelo/me163.dat");
    hp = 20;
    municao[0] = 0;
    municao[1] = 0;
}


Me163::~Me163()
{
}


void Me163::acao()
{
    //Se ainda esta "longe" do alvo
    if (abs(alvo->getX() - posX) > (tamX + tamX + tamX))
    {
        posX += (alvo->getX() - posX > 0 ? velocidade / 5 : -velocidade / 5);
    }
    //Se esta perto do alvo
    else
    {
        posX += (alvo->getX() - posX > 0 ? velocidade / 5 : -velocidade / 5);
    }
    posY -= velocidade;
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
			fase->novoProjetil(new TiroSimples(posX, posY + tamY, escala));
		else
			fase->novoProjetil(new Bomba(posX, posY + tamY, escala));
	}
}
