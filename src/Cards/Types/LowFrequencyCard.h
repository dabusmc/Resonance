#pragma once

#include "Cards/Base/FrequencyCard.h"

namespace Resonance
{
	class LowFrequencyCard : public FrequencyCard
	{
	public:
		LowFrequencyCard(int position);

		float GetArmorDamageModifier() override { return 2.0f; }
		float GetHealthDamageModifier() override { return 0.5f; }

		void Draw() override;
	};
}
