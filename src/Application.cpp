#include "Application.h"

#include "raylib.h"

#include "Cards/SineCard.h"

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
        SineCard testCard(0);
        SineCard testCard2(1);
        SineCard testCard3(2);
        SineCard testCard4(3);
        SineCard testCard5(4);

        while (!WindowShouldClose())
        {
            BeginDrawing();
                ClearBackground(BLACK);
                testCard.Draw(testCard.IsHovered(GetMouseX(), GetMouseY()));
                testCard2.Draw(testCard2.IsHovered(GetMouseX(), GetMouseY()));
                testCard3.Draw(testCard3.IsHovered(GetMouseX(), GetMouseY()));
                testCard4.Draw(testCard4.IsHovered(GetMouseX(), GetMouseY()));
                testCard5.Draw(testCard5.IsHovered(GetMouseX(), GetMouseY()));
            EndDrawing();
        }
    }

}