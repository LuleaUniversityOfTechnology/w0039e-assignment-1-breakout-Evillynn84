#include "game.h"
#include "Highscore.h"
#include <iostream>
#include <string>



void DrawHighscore() { //Drawn the highscores to the screen
    for (int i = 0; i < hs.score.size(); ++i) {
        int value = hs.score[i]; 
        Play::DrawDebugText(Play::Point2D(DISPLAY_WIDTH - 100, (DISPLAY_HEIGHT / 3) - i * 20), std::to_string(value).c_str(), Play::cWhite, true);
    }
}

void HSFile(const std::string& scorefile) {   //creates a file and also appends to the file 
    std::ofstream file(scorefile, std::ios::app);
    for (unsigned int i = 0; i < hs.score.size(); ++i) {
        file << hs.score[i] << "\n";
    }
    file.close();
}

void scoreswap() {
    if (hs.myScore[0] > 0) {
        if (hs.score.empty()) {
            hs.score.push_back(hs.myScore[0]);
        }
        else if (hs.myScore[0] != hs.score.back()) {
            hs.score.push_back(hs.myScore[0]);
        }
    }
    for (size_t i = 0; i < hs.score.size(); ++i) {
        for (size_t j = i + 1; j < hs.score.size(); ++j) {
            if (hs.score[j] > hs.score[i]) {
                std::swap(hs.score[i], hs.score[j]);
            }
        }
    }
    if (hs.score.size() > 5) {
        hs.score.resize(5);
    }
}

void ReadScores(const std::string& scorefile) {
    hs.score.clear();
    std::ifstream file(scorefile);
    if (!file.is_open()) return;
    unsigned int value;
    while (file >> value) {
        hs.score.push_back(value);
    }
    scoreswap();
    file.close();
}

void ResetScene() {                     //resets the scene, swaps the scores and saves the file once the ball exits the screen
    const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(TYPE_BALL);
    if (!ballIds.empty()) {
        Play::GameObject& ball = Play::GetGameObject(ballIds[0]);
        if (ball.pos.y < 0) {
            scoreswap();
            HSFile("highscores.txt");
            hs.myScore[0] = 0;
            const std::vector<int> brickIds = Play::CollectGameObjectIDsByType(TYPE_BRICK);
            for (int id : brickIds) {
                Play::DestroyGameObject(id);
            }
            for (int id : ballIds) {
                Play::DestroyGameObject(id);
            }
            SetupScene();
            SpawnBall();
        }
    }
}