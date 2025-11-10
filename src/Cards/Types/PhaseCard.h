#pragma once

#include "Cards/Base/UtilityCard.h"

namespace Resonance
{
	class PhaseCard : public UtilityCard
	{
	public:
		PhaseCard(int position);

		void Draw() override;
	};
}
