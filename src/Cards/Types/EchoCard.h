#pragma once

#include "Cards/Card.h"

namespace Resonance
{
	class EchoCard : public Card
	{
	public:
		EchoCard(int position);

		void Draw() override;
	};
}