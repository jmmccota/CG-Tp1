#include "Score.h"

Score::Score() {
}

Score::~Score() {
}

Score::Score(string jogador, int32_t score) {
	Score::jogador = jogador;
	Score::score = score;
}


void Score::CriaArquivo() {
	ofstream makefile;
	makefile.open("Score.txt");
	makefile.close();
}

bool Score::SaveScore() {
	try
	{
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

Score Score::getBestScore() {
	string line;
	int32_t maxScore = -1;
	string bestPlayer;
	ifstream file("Scores.txt");
	if (file.is_open()) {
		while (file.good()) {
			getline(file, line);
			vector<string> vecSplit = FuncoesAuxiliares::split(line, '/t');

			int32_t tempMaxScore = (int)vecSplit[1].c_str();

			if (tempMaxScore >= maxScore) {
				maxScore = tempMaxScore;
				bestPlayer = vecSplit[0];
			}
		}
		file.close();
		if (maxScore == -1) {
			return Score("Unknown", 0);
		}
		else {
			return Score(bestPlayer, maxScore);
		}
	}
	else {
		CriaArquivo();
		return Score("Unknown", 0);
	}
}

int32_t Score::getScore() {
	return score;
}

string Score::getJogador() {
	return jogador;
}
