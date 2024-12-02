#pragma once
#include "game.h"
#include <vector>

struct HS {
    std::vector<unsigned int> score;
    unsigned int myScore[1] = { 0 };
};

extern HS hs;

void DrawHighscore();
void ResetScene();
void scoreswap();
void HSFile(const std::string& scorefile);
void ReadScores(const std::string& scorefile);


