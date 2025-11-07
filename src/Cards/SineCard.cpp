#include "SineCard.h"

#include "raylib.h"

namespace Resonance
{
    SineCard::SineCard(int position)
        : Card(CardType::Waveform, position)
    {

    }

    void SineCard::Draw(bool hovered)
    {
        DrawRectangle(GetXPosition(), GetYPosition() - hovered * 20, 90, 135, WHITE);
    }
}