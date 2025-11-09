#pragma once

#include "Cards/Card.h"

namespace Resonance
{
	class LowFrequencyCard : public Card
	{
	public:
		LowFrequencyCard(int position);

		void Draw() override;
	};
}