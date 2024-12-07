#pragma once
#include "constants.h"
struct Paddle
{
	float x = 37, y = 5;
};

void DrawPaddle(const Paddle& paddleMove);
void UpdatePaddle(Paddle& paddleMove);
bool IsColliding(const Paddle& padCol, const Play::GameObject& object);

static Paddle MyPaddle;