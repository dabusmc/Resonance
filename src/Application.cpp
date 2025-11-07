#include "Application.h"

#include <iostream>
#include <bits/ostream.tcc>

#include "raylib.h"

#include "Cards/Hand.h"
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
        Hand hand;
        hand.Construct();

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

            if (hand.GetSelectedCount() == 3)
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
