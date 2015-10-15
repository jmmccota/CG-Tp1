#ifndef SCORE_H
#define SCORE_H


#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "FuncoesAuxiliares.hpp"
#include <list>

using namespace std;

/*
	===============SINGLETON===============
	Somente uma instancia vai ser usada no programa todo.
	Como usar:
		Score::getInstance().FUNCAOQUEEUQUEROCHAMAR(PARAMETROS);
		...
	Porque:
		Somente uma instancia pode existir para que as informacoes
		de estado da tela sejam consistentes durante o jogo todo.

*/

class Score {

protected:
	string player;
	int score;
public:
	Score(string player, int score);
	Score();
	~Score();

	//Cria o arquivo score.txt
	void static criaArquivo();

	//Retorna a quantidade de Scores no arquivo
	const static int quantScores();

	//Salva a pontua��o do jogador, retornando se foi salvo ou n�o
	bool saveScore(string jogador, int score);

	//Pega o melhor Score e o nome do jogador 
	Score static getBestScore();

	//Pega as melhores pontua��es de acordo com a quantidade desejada
	vector<Score> static getBestScore(int quant);

	//Getters
	int getScore();
	string getPlayer();
};



#endif
