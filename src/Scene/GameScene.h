#pragma once

#include "Scene.h"

#include "Cards/Deck.h"
#include "Cards/Hand.h"

#include "Enemies/TestEnemy.h"

#include "Utility/Button.h"

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

		TestEnemy m_Enemy;

		Button m_AttackButton;

		bool m_RequestNextHand;
	};
}