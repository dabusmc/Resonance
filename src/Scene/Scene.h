#pragma once

namespace Resonance
{
	class SceneSwitcher;

	class Scene
	{
	public:
		Scene() : m_Switcher(nullptr) { }
		virtual ~Scene() = default;

		virtual void Init() = 0;
		virtual void Update() = 0;
		virtual void Finish() = 0;

	protected:
		SceneSwitcher* m_Switcher;

		friend class SceneSwitcher;
	};
}