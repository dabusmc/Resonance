#include "SquareCard.h"

#include "raylib.h"

namespace Resonance
{
    SquareCard::SquareCard(int position)
        : WaveformCard(CardType::Square, position)
    {
        m_BaseDamage = 30;
    }

    void SquareCard::Draw(CardTextures& textures)
    {
        DrawRectangle(GetXPosition(), GetYPosition(), 90, 135, m_Border);
        DrawRectangle(GetXPosition() + 5, GetYPosition() + 5, 80, 125, m_Background);

        Texture2D texture = textures.GetTexture(CardTexture::Square);
        DrawTexture(texture, GetXPosition() + 5, GetYPosition() + 5, m_PrimaryColor);
    }
}