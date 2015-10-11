#ifndef SCORE_H
#define SCORE_H


#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "FuncoesAuxiliares.hpp"

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
	friend std::ostream& operator<<(std::ostream&, const Score&);
	string player;
	int score;
public:
	Score(string player, int score);
	Score();
	~Score();

	//Cria o arquivo score.txt
	void criaArquivo();

	//Retorna a quantidade de Scores no arquivo
	const int quantScores();

	//Salva a pontuação do jogador, retornando se foi salvo ou não
	bool saveScore(string jogador, int score);

	//Pega o melhor Score e o nome do jogador 
	Score static getBestScore();

	//Pega as melhores pontuações de acordo com a quantidade desejada
	vector<Score> getBestScore(int quant);

	//Getters
	int getScore();
	string getPlayer();

	//Singleton
	static Score& getInstance();
};



#endif
