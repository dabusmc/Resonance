#pragma once

#include "Scene.h"

#include "Cards/Deck.h"
#include "Cards/Hand.h"

#include "Enemies/TestEnemy.h"

#include "Utility/Button.h"

#include "Graphics/Colors.h"

namespace Resonance
{
	class GameScene : public Scene
	{
	public:
		GameScene();
		~GameScene();

		void Init() override;
		void Update() override;
		void Finish() override;

	private:
		Deck m_Deck;
		Hand m_Hand;
		bool m_RequestNextHand;

		TestEnemy m_Enemy;

		Button m_AttackButton;

		ColorMode m_ColorMode;
	};
}