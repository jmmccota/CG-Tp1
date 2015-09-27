#include "Score.h"

Score::Score() {
}

Score::~Score() {
}

Score::Score(string jogador, int score) {
	Score::jogador = jogador;
	Score::score = score;
}


void Score::CriaArquivo() {
	ofstream makefile;
	makefile.open("PlayersScores.txt");
	makefile.close();
}

bool Score::SaveScore(string jogador, int score) {
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
	int maxScore = -1;
	string bestPlayer;
	ifstream file("PlayersScores.txt");
	if (file.is_open()) {
		while (file) {
			getline(file, line);
			if (line != "") {
				vector<string> vecSplit = FuncoesAuxiliares::split(line, '\t');

				int tempMaxScore = std::stoi(vecSplit[1]);

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

int Score::getScore() {
	return score;
}

string Score::getJogador() {
	return jogador;
}

std::ostream& operator<<(std::ostream &strm, const Score &a) {
	return strm << a.jogador << " -> " << a.score << endl;
}