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
	makefile.open("PlayersScores.txt");
	makefile.close();
}

bool Score::SaveScore(string jogador, int32_t score) {
	try
	{
		ofstream file("PlayersScores.txt", ios::app);
		file << jogador << "\t" << score << "\n";
		file.close();
		return 1;
	}
	catch (const std::exception&)
	{
		return 0;
	}
}

Score Score::getBestScore() {
	string line;
	int32_t maxScore = -1;
	string bestPlayer;
	ifstream file("PlayersScores.txt");
	if (file.is_open()) {
		while (file) {
			getline(file, line);
			if (line != "") {
				vector<string> vecSplit = FuncoesAuxiliares::split(line, '\t');

				int32_t tempMaxScore = std::stoi(vecSplit[1]);

				if (tempMaxScore >= maxScore) {
					maxScore = tempMaxScore;
					bestPlayer = vecSplit[0];
				}
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
