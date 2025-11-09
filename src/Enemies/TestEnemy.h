#pragma once

#include "Enemy.h"

namespace Resonance
{
	class TestEnemy : public Enemy
	{
	public:
		TestEnemy();

		void Draw() override;
	};
}