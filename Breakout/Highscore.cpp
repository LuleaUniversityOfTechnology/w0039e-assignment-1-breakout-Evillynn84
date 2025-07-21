#include "game.h"
#include "Highscore.h"
#include <iostream>
#include <string>



void DrawHighscore() { //Draws the highscores to the screen
    for (int i = 0; i < 5; ++i) {
        int value = hs.score[i]; 
        Play::DrawDebugText(Play::Point2D(DISPLAY_WIDTH - 100, (DISPLAY_HEIGHT / 3) - i * 20), std::to_string(value).c_str(), Play::cWhite, true);
    }
}

void HSFile(const std::string& scorefile) { //overwrites the highscore in the file 
    std::ofstream file(scorefile, std::ios::trunc); 
    for (int i = 0; i < hs.nums; i++) {
        file << hs.score[i] << "\n";
    }
    file.close();
}

void scoreswap() { //swaps the scores in the array and sorts them
    if (hs.myScore[0] > 0) {
        hs.score[hs.nums] = hs.myScore[0];
        hs.nums++;
    }

    for (int i = 0; i < hs.nums; i++) {
        for (int j = i + 1; j < hs.nums; j++) {
            if (hs.score[j] > hs.score[i]) {
                std::swap(hs.score[i], hs.score[j]);
            }
        }
    }
}

void ReadScores(const std::string& scorefile) { //reads the scores from the file
    std::ifstream file(scorefile);
    if (file.is_open()) {
        int count = 0;
        unsigned int temp;
        while (file >> temp) count++;
        file.clear(); file.seekg(0);

        hs.nums = (count > 5) ? count : 5;
        hs.score = new int[hs.nums];

        int index = 0;
        while (file >> temp) {
            hs.score[index++] = temp;
        }
        file.close();
        return;
    }

    hs.nums = 5;
    hs.score = new int[hs.nums];
    for (int i = 0; i < hs.nums; i++) hs.score[i] = 0;
}


void ResetScene() { //resets the scene, but saves the highscore if the ball exits the screen
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
