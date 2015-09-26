#include "Score.h"

Score::Score(string jogador, int32_t score) {
	Score::jogador = jogador;
	Score::score = score;
}

bool Score::SaveScore() {

	FILE *fp = NULL;
	
	try
	{
		fp = fopen("Scores/Scores.txt","rb");

		
		return true;
	}
	catch (const std::exception&)
	{
		fclose(fp);
		return false;
	}


}