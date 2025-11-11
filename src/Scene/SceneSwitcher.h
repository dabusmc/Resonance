#pragma once

#include <vector>

#include "Scene.h"

namespace Resonance
{
	class SceneSwitcher
	{
	public:
		SceneSwitcher();
		~SceneSwitcher();

		template<typename T, typename... Args>
		size_t AddScene(Args&& ... args)
		{
			T* scene = new T(std::forward<Args>(args)...);
			m_Scenes.push_back(scene);
			scene->m_Switcher = this;

			if (m_Scenes.size() == 1)
			{
				SwitchTo(0);
			}

			return m_Scenes.size() - 1;
		}

		void SwitchTo(size_t index);

		void Update();

	private:
		std::vector<Scene*> m_Scenes;
		int m_Current;
	};
}