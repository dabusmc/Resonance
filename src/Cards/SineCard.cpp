#include "SineCard.h"

#include "raylib.h"

namespace Resonance
{
    SineCard::SineCard()
        : Card(CardType::Waveform)
    {

    }

    SineCard::SineCard(int position)
        : Card(CardType::Waveform, position)
    {

    }

    void SineCard::Draw()
    {
        DrawRectangle(GetXPosition(), GetYPosition(), 90, 135, WHITE);
    }
}