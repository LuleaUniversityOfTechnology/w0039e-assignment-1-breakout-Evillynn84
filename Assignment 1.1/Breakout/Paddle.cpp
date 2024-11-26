#include "game.h"
#include <algorithm>
#include <iostream>  




void DrawPaddle(const Paddle& paddleMove) {
	Play::Point2D pointOne { paddleMove.x-25, paddleMove.y-6 };					//Handles the paddles size and color
	Play::Point2D pointTwo { paddleMove.x+25, paddleMove.y+6 };
	Play::Colour paddleColor{ Play::cBlue };
	Play::DrawRect(pointOne, pointTwo, paddleColor, true);
}

void UpdatePaddle(Paddle& paddleMove) {										//Handles the movement of the paddle when the keys are pressed. The number 25 was chosen due to the paddles size given in DrawPaddle
	int movex = 10;
	if (Play::KeyDown(Play::KEY_LEFT)) {
		if (paddleMove.x > 25) {
			paddleMove.x = paddleMove.x - 10;
		}
	}
	if(Play::KeyDown(Play::KEY_RIGHT)){
		if (paddleMove.x < DISPLAY_WIDTH-25) {
			paddleMove.x = paddleMove.x + 10;
		}
	}
}

bool IsColliding(const Paddle& padCol, const Play::GameObject& object) {		//Handles the conditions for the balls collision with the paddle. The actual change in velocity happens in HandleCollision
	const float dx = object.pos.x - ((object.pos.x < padCol.x - 25) ? 
		padCol.x - 25 : (object.pos.x > padCol.x + 25) ? 
		padCol.x + 25 : object.pos.x);
	const float dy = object.pos.y - ((object.pos.y < padCol.y - 6) ?
		padCol.y - 6 : (object.pos.y > padCol.y + 6) ?
		padCol.y + 6 : (object.pos.y));
	return (dx * dx + dy * dy) < (object.radius * object.radius);
}