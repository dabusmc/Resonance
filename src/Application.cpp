#include "Application.h"

#include "raylib.h"

#include "Cards/Hand.h"

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

        while (!WindowShouldClose())
        {
            hand.Update();

            BeginDrawing();
                ClearBackground(BLACK);
                hand.Draw();
            EndDrawing();
        }
    }

}