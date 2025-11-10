#include "Application.h"

#include <iostream>

#include "raylib.h"

#include "Cards/Hand.h"
#include "Cards/Deck.h"

#include "Enemies/TestEnemy.h"

#include "Utility/Button.h"

namespace Resonance
{
    const int c_ScreenWidth = 1280;
    const int c_ScreenHeight = 720;

    Application::Application()
    {
        InitWindow(c_ScreenWidth, c_ScreenHeight, "Resonance");
        SetTargetFPS(60);
    }

    Application::~Application()
    {
        CloseWindow();
    }

    void Application::Run()
    {
        Deck deck;

        for (int i = 0; i < 5; i++)
        {
            deck.AddCard(CardType::Sine);
            deck.AddCard(CardType::Echo);
            deck.AddCard(CardType::LowFrequency);
            deck.AddCard(CardType::Phase);
        }

        Hand hand;
        hand.Construct(deck);
        bool requestNextHand = false;

        TestEnemy testEnemy;

        ButtonProps attackProps;
        attackProps.Text = "Attack";
        attackProps.PosX = 1050;
        attackProps.PosY = 610;
        attackProps.FontSize = 36;

        Button attackButton(attackProps);
        attackButton.Disable();

        attackButton.SetOnClick([&]()
        {
            hand.Attack(testEnemy);
            requestNextHand = true;
        });

        while (!WindowShouldClose())
        {
            hand.Update();

            if (requestNextHand)
            {
                requestNextHand = !hand.NextHand(deck);
            }

            if (hand.CanAttack())
            {
                attackButton.Enable();
            }
            else
            {
                attackButton.Disable();
            }

            attackButton.Update();

            BeginDrawing();
                ClearBackground(BLACK);
                DrawFPS(12, 12);
                testEnemy.Draw();
                hand.Draw();
                attackButton.Draw();
            EndDrawing();
        }
    }

}
