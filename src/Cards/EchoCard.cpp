#include "EchoCard.h"

#include "raylib.h"

namespace Resonance
{
	EchoCard::EchoCard()
		: Card(CardType::Amplitude)
	{

	}

	EchoCard::EchoCard(int position)
		: Card(CardType::Amplitude, position)
	{
	}

	void EchoCard::Draw()
	{
		DrawRectangle(GetXPosition(), GetYPosition(), 90, 135, GREEN);
	}
}