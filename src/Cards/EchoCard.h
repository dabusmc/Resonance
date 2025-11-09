#pragma once

#include "Card.h"

namespace Resonance
{
	class EchoCard : public Card
	{
	public:
		EchoCard();
		EchoCard(int position);

		void Draw() override;
	};
}