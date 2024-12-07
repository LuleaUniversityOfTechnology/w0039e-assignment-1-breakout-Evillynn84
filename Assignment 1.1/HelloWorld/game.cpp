#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "game.h"

void SpawnBall() 
{
	const int objectId = Play::CreateGameObject(ObjectType::TYPE_BALL, { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT - 60 }, 4, "ball");
	GameObject& ball = Play::GetGameObject(objectId);
	ball.velocity = normalize({ 1, -1 }) * ballSpeed;
}


void StepFrame(float elapsedTime)
{
	DrawBalls();
}

int DrawBalls()
{
	const std::vector<int> ballIds = Play::CollectGameObjectIDsByType(TYPE_BALL);

		for (int i = 0; i < ballIds.size(); ++i) {
			Play::GameObject& object = Play::GetGameObject(ballIds[i]);
			Play::UpdateGameObject(object);
			Play::DrawObject(object);
			if (object.pos.x > DISPLAY_WIDTH || object.pos.x < 0) {
				object.velocity.x = -(object.velocity.x);
			}
			if (object.pos.y > DISPLAY_HEIGHT || object.pos.y < 0) {
				object.velocity.y = -(object.velocity.y);
			}
		}
	return 0;
}



