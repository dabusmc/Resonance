#pragma once

#include "Cards/Base/AmplitudeCard.h"

namespace Resonance
{
	class EchoCard : public AmplitudeCard
	{
	public:
		EchoCard(int position);

		void Draw(CardTextures& textures) override;
	};
}
