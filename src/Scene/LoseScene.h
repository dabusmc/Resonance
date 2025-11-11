#pragma once

#include "Scene.h"

namespace Resonance
{
	class LoseScene : public Scene
	{
	public:
		LoseScene();
		~LoseScene();

		void Init() override;
		void Update() override;
		void Finish() override;
	};
}