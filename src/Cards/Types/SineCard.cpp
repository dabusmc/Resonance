#include "SineCard.h"

#include "raylib.h"

namespace Resonance
{
    SineCard::SineCard(int position)
        : WaveformCard(CardType::Sine, position)
    {
        m_BaseDamage = 10;
    }

    void SineCard::Draw()
    {
        DrawRectangle(GetXPosition(), GetYPosition(), 90, 135, WHITE);
    }
}