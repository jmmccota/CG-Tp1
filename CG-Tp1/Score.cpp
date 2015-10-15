#include "Score.hpp"
#define FILE_NAME "PlayersScores.dat"

Score::Score() {
}

Score::~Score() {
}

Score::Score(string player, int score) {
	this->player = player;
	this->score = score;
}

Score::Score(string player)
{
	this->player = player;
	this->score = 0;
}

void Score::criaArquivo() {
	ofstream makefile;
	makefile.open(FILE_NAME);
	makefile.close();
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
		Score::criaArquivo();
		return Score("Unknown", 0);
	}
}

vector<Score> Score::getBestScore(int qtScores)
{
	vector<Score *> fileScores;
	vector<Score> bestScores;

	string line;
	ifstream file(FILE_NAME);

	//Carregar arquivo em um vetor na memoria
	while (file) {
		getline(file, line);
		if (line != "") {
			vector<string> vecSplit = FuncoesAuxiliares::split(line, '\t');
			Score *score = new Score(vecSplit[0], std::stoi(vecSplit[1]));
			fileScores.push_back(score);
			line = "";
		}
	}

	int sizefileScores = fileScores.size();
	//Pega os melhores Scores
	while (qtScores && sizefileScores > 0) {
		int maxScore = -1;
		string maxPlayer = "";
		int posBest = 0;

		for (int i = 0; i < sizefileScores; i++) {
			if (fileScores[i]->score >= maxScore) {
				maxPlayer = fileScores[i]->player;
				maxScore = fileScores[i]->score;
				posBest = i;
			}
		}
		Score tempBestScore;
		tempBestScore.player = maxPlayer;
		tempBestScore.score = maxScore;
		bestScores.push_back(tempBestScore);

		Score temp;
		temp.player = fileScores[sizefileScores - 1]->player;
		temp.score = fileScores[sizefileScores - 1]->score;
		free(fileScores[sizefileScores - 1]);
		if ((sizefileScores - 1) != posBest) {
			fileScores[posBest]->player = temp.player;
			fileScores[posBest]->score = temp.score;
		}
		qtScores--;
		sizefileScores--;
	}

	return bestScores;
}

int Score::getScore() {
	return score;
}

string Score::getPlayer() {
	return player;
}
