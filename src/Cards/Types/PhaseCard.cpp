#include "PhaseCard.h"

#include "raylib.h"

namespace Resonance
{
	PhaseCard::PhaseCard(int position)
		: UtilityCard(CardType::Phase, position)
	{
	}

	void PhaseCard::Draw()
	{
		DrawRectangle(GetXPosition(), GetYPosition(), 90, 135, YELLOW);
	}
}