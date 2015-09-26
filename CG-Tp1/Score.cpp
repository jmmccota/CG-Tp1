#include "Score.h"

Score::Score() {

}

Score::~Score(){}

Score::Score(string jogador, int32_t score) {
	Score::jogador = jogador;
	Score::score = score;
}

bool Score::SaveScore() {

	FILE *fp = NULL;

	try
	{
		//fp = fopen("Scores/Scores.txt", "rb");


		return true;
	}
	catch (const std::exception&)
	{
		fclose(fp);
		return false;
	}


}

Score Score::getBestScore() {

	FILE *fp = NULL;
	try
	{
		//fp = fopen("Scores/Scores.txt", "rb");


		return Score("André Malta", 200000);
	}
	catch (const std::exception&)
	{
		fclose(fp);
		return Score("Unknow", 0);
	}
}

int32_t Score::getScore() {
	return score;
}

string Score::getJogador() {
	return jogador;
}