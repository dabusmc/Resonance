#pragma once

#include "Cards/Card.h"

namespace Resonance
{
	class FrequencyCard : public Card
	{
	public:
		FrequencyCard(CardType type, int position);

		float GetArmorDamageModifier() const { return m_ArmorDamage; }
		float GetHealthDamageModifier() const { return m_HealthDamage; }

	protected:
		float m_ArmorDamage = 1.0f;
		float m_HealthDamage = 1.0f;
	};
}