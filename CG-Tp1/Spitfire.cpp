#include "Spitfire.h"


Spitfire::Spitfire(GLfloat posX, GLfloat posY, float escala, Fase *f)
    : Personagem(posX, posY, 0.016 * escala, escala, f)
{
    this->carrega("modelos/spitfire.txt");
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