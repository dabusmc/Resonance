#include "Card.h"

#include "Utility/Files.h"

namespace Resonance
{
    CardCategory Card::GetCategoryFromType(CardType type)
    {
        switch (type)
        {
            case CardType::Sine:
            case CardType::Square:
                return CardCategory::Waveform;
            case CardType::Echo:
                return CardCategory::Amplitude;
            case CardType::LowFrequency:
            case CardType::HighFrequency:
                return CardCategory::Frequency;
            case CardType::Phase:
                return CardCategory::Utility;
            default:
                return CardCategory::Waveform;
        }
    }

    Card::Card(CardType type, int position)
        : m_Type(type), m_Position(position), m_Hovered(false), m_Selected(false)
    {
        m_Category = GetCategoryFromType(type);
    }

    void Card::SetPosition(int position)
    {
        m_Position = position;
    }

    void Card::UpdateHovered(int mouseX, int mouseY)
    {
        int x = GetXPosition();
        int y = GetYPosition();
        int width = 90;
        int height = 135;

        if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height)
        {
            m_Hovered = true;
        }
        else
        {
            m_Hovered = false;
        }
    }

    void Card::SetHovered(bool hovered)
    {
        m_Hovered = hovered;
    }

    void Card::SetSelected(bool selected)
    {
        m_Selected = selected;
    }

    int Card::GetXPosition()
    {
        return 640 - (m_Position - 2) * 120 - 45;
    }

    int Card::GetYPosition()
    {
        if (m_Selected)
        {
            return 720 - 195;
        }

        return 720 - 155 - m_Hovered * 20;
    }
}
