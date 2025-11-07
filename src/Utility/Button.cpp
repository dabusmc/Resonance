#include "Button.h"

namespace Resonance
{
    static Color ModifyColor(const Color& start, float value)
    {
        Color ret;
        ret.r = static_cast<unsigned char>(start.r) * value;
        ret.g = static_cast<unsigned char>(start.g) * value;
        ret.b = static_cast<unsigned char>(start.b) * value;
        ret.a = start.a;
        return ret;
    }

    Button::Button(const ButtonProps &props)
        : m_Props(props)
    {
        m_Enabled = true;
    }

    Button::~Button()
    {

    }

    void Button::Update()
    {
        if (!m_Enabled)
            return;

        int mouseX = GetMouseX();
        int mouseY = GetMouseY();

        if (mouseX >= m_Props.PosX && mouseX <= m_Props.PosX + m_TextSize.x && mouseY >= m_Props.PosY && mouseY <= m_Props.PosY + m_TextSize.y)
        {
            m_Hovered = true;
        }
        else
        {
            m_Hovered = false;
        }

        if (m_Hovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            m_OnClick();
            m_Clicked = true;
        }
    }

    void Button::Draw()
    {
        float colorModifier = 1.0f;
        if (!m_Enabled)
        {
            colorModifier = 0.25f;
        }
        else if (m_Clicked)
        {
            colorModifier = 0.5f;
            m_Clicked = false;
        }
        else if (m_Hovered)
        {
            colorModifier = 0.75f;
        }

        Color bg = ModifyColor(m_Props.Background, colorModifier);
        Color fg = ModifyColor(m_Props.Foreground, colorModifier);

        // TODO: Make it so that this isn't recalculated every frame
        m_TextSize = MeasureTextEx(GetFontDefault(), m_Props.Text.c_str(), m_Props.FontSize, 3);
        DrawRectangle(m_Props.PosX, m_Props.PosY, m_TextSize.x + m_Props.PaddingX * 2, m_TextSize.y + m_Props.PaddingY * 2, bg);
        DrawTextEx(GetFontDefault(),
            m_Props.Text.c_str(),
            { static_cast<float>(m_Props.PosX + m_Props.PaddingX), static_cast<float>(m_Props.PosY + m_Props.PaddingY) },
            m_Props.FontSize,
            3,
            fg);
    }

    void Button::Enable()
    {
        m_Enabled = true;
    }

    void Button::Disable()
    {
        m_Enabled = false;
    }


}