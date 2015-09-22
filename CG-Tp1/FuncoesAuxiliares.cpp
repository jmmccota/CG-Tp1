#include "FuncoesAuxiliares.h"


FuncoesAuxiliares::FuncoesAuxiliares()
{
}

FuncoesAuxiliares::~FuncoesAuxiliares()
{
}

vector<string> FuncoesAuxiliares::split(const string &s, char delim)
{
     vector<string> elems;
     stringstream ss(s);
     string item;
     while (getline(ss, item, delim)) {
         elems.push_back(item);
     }
     return elems;
 }