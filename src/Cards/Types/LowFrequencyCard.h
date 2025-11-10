#pragma once

#include "Cards/Base/FrequencyCard.h"

namespace Resonance
{
	class LowFrequencyCard : public FrequencyCard
	{
	public:
		LowFrequencyCard(int position);

		void Draw() override;
	};
}
