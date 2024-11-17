#pragma once
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "constants.h"
#include "Play.h"
#include "Paddle.h"

void SpawnBall();

void StepFrame(float elapsedTime);

int DrawBalls();

int SetupScene();

void HandleCollision();

