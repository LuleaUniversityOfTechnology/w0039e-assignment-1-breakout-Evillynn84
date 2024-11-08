#pragma once
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "constants.h"
#include "Play.h"

void SpawnBall() {
	const int objectId = Play::CreateGameObject(ObjectType::TYPE_BALL, { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT - 60 }, 4, "ball");
}