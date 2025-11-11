#pragma once

#include "Cards/Card.h"

namespace Resonance
{
	class FrequencyCard : public Card
	{
	public:
		FrequencyCard(CardType type, int position);

		virtual float GetArmorDamageModifier() = 0;
		virtual float GetHealthDamageModifier() = 0;
	};
}