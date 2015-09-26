#pragma once
#include "Score.h"
#include <string>
#include <fstream>
#include <iostream>
#include "FuncoesAuxiliares.h"

using namespace std;

class Score {
protected:
	string jogador;
	int32_t score;
public:
	Score(string jogador, int32_t score);
	Score();
	~Score();

	//Cria o arquivo score.txt
	void CriaArquivo();

	//Salva a pontuação do jogador, retornando se foi salvo ou não
	bool SaveScore();

	//Pega o melhor Score e o nome do jogador 
	Score getBestScore();

	//Retorna o Score
	int32_t getScore();

	//Retorna o nome do jogador
	string getJogador();
};

