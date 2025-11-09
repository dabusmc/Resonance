#pragma once

#include "Cards/Card.h"

namespace Resonance
{
	class PhaseCard : public Card
	{
	public:
		PhaseCard(int position);

		void Draw() override;
	};
}