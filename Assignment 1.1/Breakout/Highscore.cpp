#include "game.h"
#include "Highscore.h"
#include <iostream>
#include <string>



void DrawHighscore() {
    for (int i = 0; i < 5; ++i) {
        int value = hs.score[i];
        Play::DrawDebugText(Play::Point2D(DISPLAY_WIDTH - 100, (DISPLAY_HEIGHT / 3) - i * 20), std::to_string(value).c_str(), Play::cWhite, true);
    }  
}


void ResetScene() {
    const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(TYPE_BALL);
    Play::GameObject& ball = Play::GetGameObject(ballIds[0]);
    if (ball.pos.y < 0) {
        const std::vector<int> brickIds = Play::CollectGameObjectIDsByType(TYPE_BRICK);
        for (int id : brickIds) {
            Play::DestroyGameObject(id);
        }
        for (int id : ballIds) {
            Play::DestroyGameObject(id);
            hs.myScore[0] = 0;
        }
        int buffer = hs.myScore[0];
        for (int i = 4; i >= 0; i--) {
            if (buffer > hs.score[i]) {
                std::swap(buffer, hs.score[i]);
            }
        }
        SetupScene();
        SpawnBall();
    }
}