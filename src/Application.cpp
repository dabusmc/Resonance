#include "Application.h"

#include <iostream>

#include "raylib.h"

#include "Scene/GameScene.h"

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
        GameScene scene;
        scene.Init();

        while (!WindowShouldClose())
        {
            scene.Update();
        }
    }

}
