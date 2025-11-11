#pragma once

#include "Cards/Base/FrequencyCard.h"

namespace Resonance
{
	class HighFrequencyCard : public FrequencyCard
	{
	public:
		HighFrequencyCard(int position);

		void Draw(CardTextures& textures) override;
	};
}
