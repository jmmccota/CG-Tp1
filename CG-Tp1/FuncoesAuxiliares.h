#ifndef FUNCOES_AUXILIARES_H
#define FUNCOES_AUXILIARES_H

#include <string>
#include <sstream>
#include <vector>

using namespace std;

/*
Classe usada para guardar funcoes uteis mas que
nao pertencem a uma classe em especifico
*/


class FuncoesAuxiliares
{
private:
	void static desenha(int ix, int iy);

public:
	FuncoesAuxiliares();
	~FuncoesAuxiliares();

	vector<string> static split(const string &s, char delim);
	void static bresenham(int x1, int y1, int x2, int y2);
	void static bresenhamCircle(int x, int y, int a, int b);

};

#endif