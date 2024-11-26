#pragma once
#include "game.h"

struct HS
{
	int score[5] = { 0, 0, 0, 0, 0 };
	int myScore[1] = { 0 };
};

extern HS hs;

void DrawHighscore();
void ResetScene();


