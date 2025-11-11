#include "SineCard.h"

#include "raylib.h"

namespace Resonance
{
    SineCard::SineCard(int position)
        : WaveformCard(CardType::Sine, position)
    {
        m_BaseDamage = 10;
    }

    void SineCard::Draw(CardTextures& textures)
    {
        DrawRectangle(GetXPosition(), GetYPosition(), 90, 135, m_Border);
        DrawRectangle(GetXPosition() + 5, GetYPosition() + 5, 80, 125, m_Background);

        Texture2D texture = textures.GetTexture(CardTexture::Sine);
        DrawTexture(texture, GetXPosition() + 5, GetYPosition() + 5, m_Border);
    }
}