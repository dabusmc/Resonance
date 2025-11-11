#include "LoseScene.h"

#include "raylib.h"

namespace Resonance
{
	LoseScene::LoseScene()
	{

	}

	LoseScene::~LoseScene()
	{

	}

	void LoseScene::Init()
	{

	}

	void LoseScene::Update()
	{
		BeginDrawing();
			ClearBackground(BLACK);
			DrawText("YOU LOSE!!", 520, 320, 48, WHITE);
		EndDrawing();
	}

	void LoseScene::Finish()
	{

	}
}