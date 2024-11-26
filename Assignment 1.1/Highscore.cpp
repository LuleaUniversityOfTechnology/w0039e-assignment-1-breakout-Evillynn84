#include "game.h"
#include "Highscore.h"
#include <iostream>
#include <string>

HS hs;

void DrawHighscore() {
	for (int i = 0; i < 5; ++i) {
		int value = hs.score[i];
		Play::DrawDebugText(Play::Point2D(DISPLAY_WIDTH -100, (DISPLAY_HEIGHT/3)-i*20), std::to_string(value).c_str(), Play::cWhite, true);
	}
    for (int i = 0; i < 5; ++i) {                                              //Handles the score
        if (hs.myScore[0] > hs.score[i])  {
                hs.score[i] = hs.myScore[0];
            
        }
    }
}


void ResetScene() {
    const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(TYPE_BALL);
    if (ballIds.size() == 1) {
        Play::GameObject& ball = Play::GetGameObject(ballIds[0]);
        if (ball.pos.y < 0) {
            const std::vector<int> brickIds = Play::CollectGameObjectIDsByType(TYPE_BRICK);
            for (int id : brickIds) {
                Play::DestroyGameObject(id);
            }
            SetupScene();
            SpawnBall();
        }
    }
}