#include "Score.h"

Score::Score() {

}

Score::~Score() {}

Score::Score(string jogador, int32_t score) {
	Score::jogador = jogador;
	Score::score = score;
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

	try
	{
		ifstream file("Scores/Scores.txt");
		while (file.good()) {
			getline(file, line);

			SplitString splitLine(line);
			vector<string> vecSplit = splitLine.split('/t', 2);

			int32_t tempMaxScore = (int)vecSplit[1].c_str();

			if (tempMaxScore >= maxScore) {
				maxScore = tempMaxScore;
				bestPlayer = vecSplit[0];
			}

		}
		file.close();

		return Score(bestPlayer, maxScore);
	}
	catch (const std::exception&)
	{

		return Score("Unknow", 0);
	}
}

int32_t Score::getScore() {
	return score;
}

string Score::getJogador() {
	return jogador;
}