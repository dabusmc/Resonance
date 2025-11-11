#include "EchoCard.h"

#include "raylib.h"

namespace Resonance
{
	EchoCard::EchoCard(int position)
		: AmplitudeCard(CardType::Echo, position)
	{
	}

	void EchoCard::Draw(CardTextures& textures)
	{
		DrawRectangle(GetXPosition(), GetYPosition(), 90, 135, m_Border);
		DrawRectangle(GetXPosition() + 5, GetYPosition() + 5, 80, 125, m_Background);

		Texture2D texture = textures.GetTexture(CardTexture::Echo);
		DrawTexture(texture, GetXPosition() + 5, GetYPosition() + 5, m_PrimaryColor);
	}
}