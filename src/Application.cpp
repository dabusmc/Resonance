#include "Application.h"

#include "raylib.h"

namespace Resonance
{
    const int c_ScreenWidth = 900;
    const int c_ScreenHeight = c_ScreenWidth / 16 * 10;

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
        while (!WindowShouldClose())
        {
            BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawText("Congrats! You created your first window!", c_ScreenWidth / 2 - 200, c_ScreenHeight / 2 - 30, 20, LIGHTGRAY);
            EndDrawing();
        }
    }

}