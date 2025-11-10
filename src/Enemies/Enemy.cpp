#include "Enemy.h"

#include <algorithm>

namespace Resonance
{
	Enemy::Enemy(int initialHealth, int initialArmor)
		: m_Health(initialHealth), m_Armor(initialArmor)
	{

	}

	void Enemy::Damage(int amount, bool ignoresArmor)
	{
		if (ignoresArmor || m_Armor <= 0)
		{
			m_Health -= amount;
		}
		else
		{
			int leftover = amount - m_Armor;
			m_Armor -= amount;
			m_Armor = std::max(m_Armor, 0);
			if (leftover > 0)
			{
				m_Health -= leftover;
			}
		}
	}


}
