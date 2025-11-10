#include "LowFrequencyCard.h"

#include "raylib.h"

namespace Resonance
{
	LowFrequencyCard::LowFrequencyCard(int position)
		: FrequencyCard(CardType::LowFrequency, position)
	{
	}

	void LowFrequencyCard::Draw()
	{
		DrawRectangle(GetXPosition(), GetYPosition(), 90, 135, RED);
	}
}