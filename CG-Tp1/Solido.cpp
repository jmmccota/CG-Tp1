#include "Solido.h"

Solido::Solido()
{
    poligonos = nullptr;
    nPoligonos = 0;
}

Solido::~Solido()
{
    delete[] poligonos;
}

void Solido::carrega(std::string arquivo)
{
	std::ifstream fs;
	fs.open(arquivo, std::fstream::in);
	while (!fs.eof())
	{
		int nLinhas;
		std::vector<std::string> vLinha;
		std::string linha, linhas;
		std::getline(fs, linha);
		vLinha = FuncoesAuxiliares::split(linha, ' ');
		linhas = linha;
		//Caso seja circulo
		if (vLinha[0] == "C")
		{
			std::getline(fs, linha);
			linhas += "\n" + linha;
			nLinhas = 2;
		}
		//Caso seja poligono
		else
		{
			for (int i = 0; i < stoi(vLinha[0]); i++)
			{
				std::getline(fs, linha);
				linhas += "\n" + linha;
			}
			nLinhas = stoi(vLinha[0]) + 1;
		}
		poligonos.push_back(*(new Poligono(300 / 10000)));
	}
}

void Solido::desenha()
{
    for (int i = 0; i < nPoligonos; i++)
    {
        poligonos[i].desenha(posX, posY);
    }
}
