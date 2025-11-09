#include "Application.h"

#include <iostream>

#include "raylib.h"

#include "Cards/Hand.h"
#include "Cards/Deck.h"
#include "Cards/SineCard.h"
#include "Cards/EchoCard.h"

#include "Utility/Button.h"
#include "Utility/Random.h"

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
        deck.AddCard<SineCard>();
        deck.AddCard<SineCard>();
        deck.AddCard<SineCard>();
        deck.AddCard<EchoCard>();
        deck.AddCard<EchoCard>();

        Hand hand;
        hand.Construct(deck);

        ButtonProps attackProps;
        attackProps.Text = "Attack";
        attackProps.PosX = 1050;
        attackProps.PosY = 610;
        attackProps.FontSize = 36;

        Button attackButton(attackProps);
        attackButton.Disable();

        attackButton.SetOnClick([]()
        {
            std::cout << "Attack!!!!!" << std::endl;
        });

        while (!WindowShouldClose())
        {
            hand.Update();

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
                hand.Draw();
                attackButton.Draw();
            EndDrawing();
        }
    }

}
