#pragma once

namespace Resonance
{
	class Enemy
	{
	public:
		Enemy();
		virtual ~Enemy() = default;

		virtual void Draw() = 0;
	};
}