#pragma once

#include "Cards/Card.h"

namespace Resonance
{
	class WaveformCard : public Card
	{
	public:
		WaveformCard(CardType type, int position);

		int GetBaseDamage() const { return m_BaseDamage; }

	protected:
		int m_BaseDamage;
	};
}