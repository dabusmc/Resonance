#include "Enemy.h"

#include <algorithm>

namespace Resonance
{
	Enemy::Enemy(int initialHealth, int initialArmor)
		: m_Health(initialHealth), m_Armor(initialArmor)
	{

	}

	void Enemy::Damage(int amount, bool ignoresArmor, float armorModifier, float healthModifier)
	{
		if (ignoresArmor || m_Armor <= 0)
		{
			m_Health -= static_cast<int>(amount * healthModifier);
		}
		else
		{
			int armorDamage = static_cast<int>(amount * armorModifier);

			int leftover = armorDamage - m_Armor;
			m_Armor -= armorDamage;
			m_Armor = std::max(m_Armor, 0);
			if (leftover > 0)
			{
				m_Health -= static_cast<int>(leftover * healthModifier);
			}
		}
	}
}
