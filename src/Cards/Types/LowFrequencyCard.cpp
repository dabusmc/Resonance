#include "LowFrequencyCard.h"

#include "raylib.h"

namespace Resonance
{
	LowFrequencyCard::LowFrequencyCard(int position)
		: FrequencyCard(CardType::LowFrequency, position)
	{
		m_ArmorDamage = 2.0f;
		m_HealthDamage = 0.5f;
	}

	void LowFrequencyCard::Draw(CardTextures& textures)
	{
		DrawRectangle(GetXPosition(), GetYPosition(), 90, 135, m_Border);
		DrawRectangle(GetXPosition() + 5, GetYPosition() + 5, 80, 125, m_Background);

		Texture2D texture = textures.GetTexture(CardTexture::LowFrequency);
		DrawTexture(texture, GetXPosition() + 5, GetYPosition() + 5, m_PrimaryColor);
	}
}