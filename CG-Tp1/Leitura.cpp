#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include "SplitString.h"
#include "Ponto.h"

using namespace std;

void carregar(string filename, ...) {
	string line;
	ifstream poligon(filename);
	if (poligon.is_open()) {
		while (poligon.good()) {

			getline(poligon, line);
			//cout << line << endl;
			SplitString ss(line);
			vector<string> flds = ss.split(' ', 1);
			if (flds.size() > 0) {
				if (flds[0] == "C" || flds[0] == "c") {
					float corR, corG, corB;
					corR = atof(flds[1].c_str());
					corG = atof(flds[2].c_str());
					corB = atof(flds[3].c_str());

					getline(poligon, line);
					SplitString ss(line);
					vector<string> flds = ss.split(' ', 0);
					float centroX, centroY, raio;
					centroX = atof(flds[0].c_str());
					centroY = atof(flds[1].c_str());
					raio = atof(flds[2].c_str());
					//cout << "Circulo" << centroX << centroY << raio << endl;
				}
				else if (flds[0] != " ")
				{
					int repeticao = atoi(flds[0].c_str());
					float corR, corG, corB;
					corR = atof(flds[1].c_str());
					corG = atof(flds[2].c_str());
					corB = atof(flds[3].c_str());
					Ponto **pontos = new Ponto*[repeticao];
					for (int i = 0; i < repeticao; i++) {
						getline(poligon, line);
						SplitString ss(line);
						vector<string> flds = ss.split(' ', 1);
						pontos[i] = new Ponto(atoi(flds[0].c_str()), atoi(flds[1].c_str()));
//						cout << *pontos[i] << endl;
					}
				}
			}
		}
	}
	//cout << "terminou?" << endl;
	poligon.close();
	//delete &line;
	//delete writable;
	//delete &poligon;
	//delete sVet;
}

int main(int argc, char **argv) {
	carregar("teste.txt"); //Colocar o caminho do arquivo, ou por ele dentro da pasta bin ou por ele nos resources
	cin.get();
}