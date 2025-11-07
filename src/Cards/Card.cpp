#include "Card.h"

namespace Resonance
{
    Card::Card(CardType type, int position)
        : m_Type(type), m_Position(position)
    {

    }

    bool Card::IsHovered(int mouseX, int mouseY)
    {
        int x = GetXPosition();
        int y = GetYPosition();
        int width = 90;
        int height = 135;

        return mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height;
    }

    int Card::GetXPosition()
    {
        return 640 - (m_Position - 2) * 120 - 45;
    }

    int Card::GetYPosition()
    {
        return 720 - 155;
    }
}