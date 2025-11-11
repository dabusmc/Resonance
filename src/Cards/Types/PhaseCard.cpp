#include "PhaseCard.h"

#include "raylib.h"

namespace Resonance
{
	PhaseCard::PhaseCard(int position)
		: UtilityCard(CardType::Phase, position)
	{
	}

	void PhaseCard::Draw(CardTextures& textures)
	{
		DrawRectangle(GetXPosition(), GetYPosition(), 90, 135, m_Border);
		DrawRectangle(GetXPosition() + 5, GetYPosition() + 5, 80, 125, m_Background);

		Texture2D texture = textures.GetTexture(CardTexture::Phase);
		DrawTexture(texture, GetXPosition() + 5, GetYPosition() + 5, m_Border);
	}
}