#include "Solido.h"

Solido::Solido(GLfloat pX, GLfloat pY, GLfloat vel, float esc)
{
    posX = pX;
    posY = pY;
    velocidade = vel;
    escala = esc;
}

Solido::~Solido()
{
}

void Solido::carrega(std::string arquivo)
{
    //utilizado para descobrir o tamanho do solido
    GLfloat tamY1 = 0, tamY2 = 0, tamX = 0;


	std::ifstream fs;
	fs.open(arquivo, std::fstream::in);
	while (!fs.eof())
	{
		std::string linha;
		std::getline(fs, linha);
		if (linha == "")
			continue;
		int nLinhas;
		std::vector<std::string> vLinha, linhas;
		vLinha = FuncoesAuxiliares::split(linha, ' ');
		linhas.push_back(linha);
		//Caso seja circulo
		if (vLinha[0] == "C")
		{
			std::getline(fs, linha);
			linhas.push_back(linha);
		}
		//Caso seja poligono
		else
		{
			for (int i = 0; i < stoi(vLinha[0]); i++)
			{
				std::getline(fs, linha);
				linhas.push_back(linha);
			}
		}
		poligonos.push_back(*(new Poligono(escala)));
		poligonos.back().carrega(linhas);

        //Busca o maior ponto do poligono
        for (int i = 0; i < poligonos.back().getNPontos(); i++)
        {
            //maior Y
            tamY1 = (poligonos.back().getPontoY(i) > tamY1 ? poligonos.back().getPontoY(i) : tamY1);
            //menor Y
            tamY2 = (poligonos.back().getPontoY(i) < tamY2 ? poligonos.back().getPontoY(i) : tamY2);
            //maior X
            tamX = (poligonos.back().getPontoX(i) > tamX ? poligonos.back().getPontoX(i) : tamX);
        }
	}

    this->tamX = tamX * escala;
    this->tamY = ( (abs(tamY1) > abs(tamY2)) ? abs(tamY1) : abs(tamY2) ) * escala;
}

void Solido::desenha()
{
	for (int i = 0; i < poligonos.size(); i++)
	{
		poligonos[i].desenha(posX, posY);
	}
}
