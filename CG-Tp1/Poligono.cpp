#include "Poligono.h"

Poligono::Poligono(float escala)
{
    this->escala = escala;
}
Poligono::~Poligono()
{
}

void Poligono::carrega(std::vector<std::string> linhas)
{
    //Lendo primeira linha
    std::vector<std::string> linha = FuncoesAuxiliares::split(linhas[0], ' ');
    pontosX.clear();
    pontosY.clear();

    //Lendo a cor do poligono
    for (int i = 1; i < linha.size(); i++)
    {
        cor[i - 1] = std::stof(linha[i]);
    }

    //Caso seja um circulo
    if (linha[0] == "C")
    {
        linha = FuncoesAuxiliares::split(linhas[1], ' ');
        for (double i = 0; i < 2 * 3.14159; i += 3.14159 / 12)
        {
            pontosX.push_back(std::stof(linha[0]) + (sin(i) * std::stof(linha[2])));
            pontosX.back() *= escala;
            pontosY.push_back(std::stof(linha[1]) + (cos(i) * std::stof(linha[2])));
            pontosY.back() *= escala;
        }
    }
    //Caso seja um poligono
    else
    {
        for (int i = 1; i < linhas.size(); i++)
        {
            linha = FuncoesAuxiliares::split(linhas[i], ' ');
            int aux = stof(linha[1]);
            pontosX.push_back(stof(linha[0]) * escala);
            pontosY.push_back(stof(linha[1]) * escala);
        }
    }
}

void Poligono::desenha(GLfloat x, GLfloat y)
{
    glColor3f(cor[0], cor[1], cor[2]);
	if (pontosX.size() > 2)
		glBegin(GL_TRIANGLE_FAN);
	else
		glBegin(GL_LINES);
    for (int i = 0; i < pontosX.size(); i++)
    {
        glVertex2f(pontosX[i] + x, pontosY[i] + y);
    }
    glEnd();
}


GLfloat Poligono::getPontoX(int indice)
{
    return pontosX[indice];
}
GLfloat Poligono::getPontoY(int indice)
{
    return pontosY[indice];
}
int Poligono::getNPontos()
{
    return pontosX.size();
}