#include "EchoCard.h"

#include "raylib.h"

namespace Resonance
{
	EchoCard::EchoCard(int position)
		: AmplitudeCard(CardType::Echo, position)
	{
	}

	void EchoCard::Draw()
	{
		DrawRectangle(GetXPosition(), GetYPosition(), 90, 135, GREEN);
	}
}