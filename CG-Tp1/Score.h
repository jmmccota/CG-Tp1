#pragma once
#include "Score.h"
#include <string>
#include <fstream>
#include <iostream>
#include "FuncoesAuxiliares.h"

using namespace std;

class Score {
protected:
	friend std::ostream& operator<<(std::ostream&, const Score&);
	string jogador;
	int score;
public:
	Score(string jogador, int score);
	Score();
	~Score();

	//Cria o arquivo score.txt
	void static CriaArquivo();

	//Salva a pontuação do jogador, retornando se foi salvo ou não
	bool SaveScore(string jogador, int score);

	//Pega o melhor Score e o nome do jogador 
	Score static getBestScore();

	//Getters
	int getScore();
	string getJogador();
};



