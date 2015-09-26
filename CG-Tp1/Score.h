#pragma once
#include "Score.h"
#include <string>
#include <stdio.h>

using namespace std;

class Score {
protected:
	string jogador;
	int32_t score;
public:
	Score(string jogador, int32_t score);
	~Score();

	bool SaveScore();
};