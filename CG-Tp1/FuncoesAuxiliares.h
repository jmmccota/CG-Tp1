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
public:
    FuncoesAuxiliares();
    ~FuncoesAuxiliares();

    vector<string> static split(const string &s, char delim);
};

#endif