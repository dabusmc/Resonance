#pragma once

namespace Resonance
{
	class Enemy
	{
	public:
		Enemy(int initialHealth, int initialArmor);
		virtual ~Enemy() = default;

		virtual void Draw() = 0;

		void Damage(int amount, bool ignoresArmor);

		int GetHealth() const { return m_Health; }
		int GetArmor() const { return m_Armor; }

	protected:
		int m_Health;
		int m_Armor;
	};
}