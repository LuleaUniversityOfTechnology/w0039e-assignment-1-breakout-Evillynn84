#pragma once
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "constants.h"
#include "Play.h"
#include "Paddle.h"
#include "Highscore.h"

void SpawnBall();

void StepFrame(float elapsedTime);

int DrawBalls();

int SetupScene();

void HandleCollision();


