#include "Score.hpp"

#define FILE_NAME "PlayersScores.dat"


Score::Score() {
}

Score::~Score() {
}

Score::Score(string jogador, int score) {
	Score::player = jogador;
	Score::score = score;
}


void Score::criaArquivo() {
	ofstream makefile;
	makefile.open(FILE_NAME);
	makefile.close();
}

const int Score::quantScores()
{
	int contScores = 0;
	string line;
	ifstream file(FILE_NAME);
	if (file.is_open()) {
		while (file)
		{
			getline(file, line);
			if (line != "") {
				contScores++;
				line = "";
			}
		}
	}
	return contScores;
}

bool Score::saveScore(string jogador, int score) {
	try
	{
		ofstream file(FILE_NAME, ios::app);
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
	ifstream file(FILE_NAME);
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
		Score::getInstance().criaArquivo();
		return Score("Unknown", 0);
	}
}

vector<Score> Score::getBestScore(int qtScores)
{
	int totalScores = quantScores();
	Score *scores[100];

	vector<Score> bestScores(qtScores);
	string line;
	int i = 0;
	int maxScore = -1;

	ifstream file(FILE_NAME);
	while (file)
	{
		getline(file, line);
		if (line != "") {
			vector<string> vecSplit = FuncoesAuxiliares::split(line, '\t');
			Score *s = new Score(vecSplit[0], std::stoi(vecSplit[1]));
			scores[i] = s;
			line = "";
			i++;
		}
	}

	Score *pointB;
	int contBest = 0;
	int posBest_inMoment;

	//Percorre o vetor de scores
	while (contBest < totalScores && contBest < qtScores) {
		for (int x = 0; x < i; x++) {
			if (scores[x]->score >= maxScore) {
				maxScore = scores[x]->score;
				pointB = scores[x];
				posBest_inMoment = x;
			}
		}
		bestScores[contBest] = *pointB;

		//Retirar o apontamento
		free(scores[posBest_inMoment]);
		scores[posBest_inMoment] = scores[i - 1];
		i--;
		contBest++;
		maxScore = -1;
	}

	while (contBest < qtScores) {
		bestScores[contBest] = Score("Unknown", 0);
		contBest++;
	}

	return bestScores;
}


int Score::getScore() {
	return score;
}

string Score::getPlayer() {
	return player;
}

std::ostream& operator<<(std::ostream &strm, const Score &a) {
	return strm << a.player << " -> " << a.score << endl;
}

Score& Score::getInstance()
{
	static Score singleton;
	return singleton;
}