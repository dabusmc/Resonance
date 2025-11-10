#include "GameScene.h"

#include <iostream>

#include "raylib.h"

namespace Resonance
{
	GameScene::GameScene()
	{
		for (int i = 0; i < 5; i++)
		{
			m_Deck.AddCard(CardType::Sine);
			m_Deck.AddCard(CardType::Echo);
			m_Deck.AddCard(CardType::LowFrequency);
			m_Deck.AddCard(CardType::Phase);
		}

		ButtonProps attackProps;
		attackProps.Text = "Attack";
		attackProps.PosX = 1050;
		attackProps.PosY = 610;
		attackProps.FontSize = 36;

		m_AttackButton.SetProps(attackProps);
		m_AttackButton.Disable();
	}

	GameScene::~GameScene()
	{

	}

	void GameScene::Init()
	{
		m_Hand.Reset();
		m_Hand.Construct(m_Deck);
		m_RequestNextHand = false;

		m_AttackButton.SetOnClick([&]()
		{
			m_Hand.Attack(m_Enemy);
			m_RequestNextHand = true;
		});
	}

	void GameScene::Update()
	{
		m_Hand.Update();

		if (m_RequestNextHand)
		{
			m_RequestNextHand = !m_Hand.NextHand(m_Deck);
		}

		if (m_Hand.CanAttack())
		{
			m_AttackButton.Enable();
		}
		else
		{
			m_AttackButton.Disable();
		}

		m_AttackButton.Update();

		BeginDrawing();
			ClearBackground(BLACK);
			DrawFPS(12, 12);
			m_Enemy.Draw();
			m_Hand.Draw();
			m_AttackButton.Draw();
		EndDrawing();
	}

	void GameScene::Finish()
	{

	}
}