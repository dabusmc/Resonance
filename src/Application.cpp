#include "Application.h"

#include <iostream>

#include "raylib.h"

#include "Scene/GameScene.h"
#include "Scene/LoseScene.h"

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
        m_Switcher.AddScene<GameScene>();
        m_Switcher.AddScene<LoseScene>();

        while (!WindowShouldClose())
        {
            m_Switcher.Update();
        }
    }

}
