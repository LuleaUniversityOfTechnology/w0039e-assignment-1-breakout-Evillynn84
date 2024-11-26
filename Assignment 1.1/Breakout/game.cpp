#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "game.h"


HS hs;

void SpawnBall() 
{
	const int objectId = Play::CreateGameObject(ObjectType::TYPE_BALL, { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT - 100 }, 4, "ball");  //Should have been in StepFrame. Spawns the ball at chosen coordinates
	GameObject& ball = Play::GetGameObject(objectId);
	ball.velocity = normalize({ 1, -1 }) * ballSpeed;
}


void StepFrame(float elapsedTime)
{
	UpdatePaddle(MyPaddle);           //Handles updating of objects such as ball and paddle so they can move (through calling functions), but also to updates frames for destroyed bricks bricks
	DrawPaddle(MyPaddle);
	DrawBalls();
	HandleCollision();
	ResetScene();
	DrawHighscore();

	const std::vector<int> brickIds = Play::CollectGameObjectIDsByType(TYPE_BRICK);
	for (int id : brickIds) {
		Play::GameObject& brick = Play::GetGameObject(id);
		Play::UpdateGameObject(brick);
		Play::DrawObject(brick);
	}
}

void HandleCollision()
{                                                                                         //Handles collisions of the bricks and removal of those bricks
	const std::vector<int> brickIds = Play::CollectGameObjectIDsByType(TYPE_BRICK);     
	for (int id : brickIds) {
		Play::GameObject& brick = Play::GetGameObject(id);
		const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(TYPE_BALL);
		for (int i = 0; i < ballIds.size(); ++i) {
			Play::GameObject& ball = Play::GetGameObject(ballIds[i]);
			if (Play::IsColliding(ball, brick))
			{
				Play::DestroyGameObject(id);
				const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(TYPE_BALL);
				Play::GameObject& object = Play::GetGameObject(ballIds[i]);
				object.velocity = -(object.velocity);
				int value = hs.myScore[0];				//Draws current player score
				hs.myScore[0] += 1;
				
			}
			int value = hs.myScore[0];
			Play::DrawDebugText(Play::Point2D(DISPLAY_WIDTH - 600, DISPLAY_HEIGHT / 10), std::to_string(value).c_str(), Play::cWhite, true);

		}
	}
	const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(TYPE_BALL);       //Handles change in velocity of the ball after collision if the conditions for IsColliding are met
	for (int i = 0; i < ballIds.size(); ++i) {
		Play::GameObject& ball = Play::GetGameObject(ballIds[i]);
		if (IsColliding(MyPaddle, ball)) {
			ball.velocity.x = -(ball.velocity.x);
			ball.velocity.y = -(ball.velocity.y);
		}
	}

}

int DrawBalls()
{
	const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(TYPE_BALL);				//Drawns the ball and changes the balls velicity after hitting the walls
		for (int i = 0; i < ballIds.size(); ++i) {
			Play::GameObject& object = Play::GetGameObject(ballIds[i]);
			Play::UpdateGameObject(object);
			Play::DrawObject(object);
			if (object.pos.x > DISPLAY_WIDTH || object.pos.x < 0) {
				object.velocity.x = -(object.velocity.x);
			}
			if (object.pos.y > DISPLAY_HEIGHT) {
				object.velocity.y = -(object.velocity.y);
			}
		}
	return 0;
}

int SetupScene()
{																					//Handles drawing the bricks at chosen coordinates with the right amount of spacing
	int stepx = 18;
	int stepy = 12;
	for (int x = 0; x < DISPLAY_WIDTH; x += stepx){
		for (int y = 275; y < DISPLAY_HEIGHT; y += stepy){
			Play::CreateGameObject(ObjectType::TYPE_BRICK, { x, y }, 6, "brick");
		}
	}




	return 0;
}

