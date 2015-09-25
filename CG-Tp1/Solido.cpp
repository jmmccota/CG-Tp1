#include "Solido.h"

Solido::Solido()
{
}

Solido::~Solido()
{
}

void Solido::carrega(std::string arquivo)
{
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
		poligonos.push_back(*(new Poligono((float) 500 / 10000)));
        poligonos.back().carrega(linhas);
	}
}

void Solido::desenha()
{
    for (int i = 0; i < poligonos.size(); i++)
    {
        poligonos[i].desenha(posX, posY);
    }
}
