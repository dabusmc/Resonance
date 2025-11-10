#pragma once

namespace Resonance
{
	class Scene
	{
	public:
		Scene() { }
		virtual ~Scene() = default;

		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Finish() = 0;
	};
}