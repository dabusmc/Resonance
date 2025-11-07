#pragma once

#include <string>
#include <functional>

#include "raylib.h"

namespace Resonance
{
    struct ButtonProps
    {
        std::string Text = "";
        int PosX = 0;
        int PosY = 0;
        float FontSize = 12;

        int PaddingX = 10;
        int PaddingY = 5;

        Color Background = WHITE;
        Color Foreground = BLACK;
    };

    class Button
    {
    public:
        Button(const ButtonProps& props);
        ~Button();

        void Update();
        void Draw();

        void Enable();
        void Disable();

        void SetOnClick(std::function<void()> callback) { m_OnClick = callback; }

    private:
        ButtonProps m_Props;

        Vector2 m_TextSize;

        std::function<void()> m_OnClick;

        bool m_Enabled;
        bool m_Hovered;
        bool m_Clicked;
    };
}