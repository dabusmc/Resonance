#include "TestEnemy.h"

#include "raylib.h"

namespace Resonance
{
	TestEnemy::TestEnemy()
		: Enemy()
	{

	}

	void TestEnemy::Draw()
	{
		DrawRectangle(1040, 270, 150, 190, WHITE);
	}
}