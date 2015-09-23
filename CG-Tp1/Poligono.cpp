#include "Poligono.h"

Poligono::Poligono(float escala)
{
    this->escala = escala;
    pontosX = nullptr;
    pontosY = nullptr;
}
Poligono::~Poligono()
{
    delete[] this->pontosX;
    delete[] this->pontosY;
}

void Poligono::Carrega(std::string *linhas, int nLinhas)
{
    //Lendo primeira linha
    std::vector<std::string> linha = FuncoesAuxiliares::split(linhas[0], ' ');

    //Lendo a cor do poligono
    for (int i = 1; i < linha.size(); i++)
    {
        cor[i - 1] = std::stof(linha[i]);
    }

    //Caso seja um circulo
    if (linha[0] == "C")
    {
        pontosX = new GLfloat[24];
        pontosY = new GLfloat[24];
		nPontos = 24;
        linha = FuncoesAuxiliares::split(linha[1], ' ');
        int cont = 0;
        for (double i = 0; i < 2 * 3.14159; i += 3.14159 / 12, cont++)
        {
            pontosX[cont] = std::stof(linha[0]) + (sin(i) * std::stof(linha[2]));
            pontosX[cont] *= escala;
            pontosY[cont] = std::stof(linha[1]) + (cos(i) * std::stof(linha[2]));
            pontosY[cont] *= escala;
        }
    }
    //Caso seja um poligono
    else
    {
		nPontos = nLinhas - 1;
        pontosX = new GLfloat[stoi(linha[0])];
        pontosY = new GLfloat[stoi(linha[0])];
        for (int i = 1; i < nLinhas; i++)
        {
            linha = FuncoesAuxiliares::split(linhas[i], ' ');
            pontosX[i] = stof(linha[0]) * escala;
            pontosY[i] = stof(linha[1]) * escala;
        }
    }
}

void Poligono::Desenha(GLfloat x, GLfloat y)
{
    glColor3f(cor[0], cor[1], cor[2]);
	if (nPontos > 2)
		glBegin(GL_TRIANGLE_FAN);
	else
		glBegin(GL_LINES);
    for (int i = 0; i < nPontos; i++)
    {
        glVertex2f(pontosX[i] + x, pontosY[i] + y);
    }
    glEnd();
}