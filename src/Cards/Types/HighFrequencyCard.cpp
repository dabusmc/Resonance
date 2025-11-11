#include "HighFrequencyCard.h"

#include "raylib.h"

namespace Resonance
{
	HighFrequencyCard::HighFrequencyCard(int position)
		: FrequencyCard(CardType::HighFrequency, position)
	{
		m_ArmorDamage = 0.5f;
		m_HealthDamage = 2.0f;
	}

	void HighFrequencyCard::Draw(CardTextures& textures)
	{
		DrawRectangle(GetXPosition(), GetYPosition(), 90, 135, m_Border);
		DrawRectangle(GetXPosition() + 5, GetYPosition() + 5, 80, 125, m_Background);

		Texture2D texture = textures.GetTexture(CardTexture::HighFrequency);
		DrawTexture(texture, GetXPosition() + 5, GetYPosition() + 5, m_Border);
	}
}