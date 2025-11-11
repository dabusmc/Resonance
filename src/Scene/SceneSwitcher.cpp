#include "SceneSwitcher.h"

namespace Resonance
{
	SceneSwitcher::SceneSwitcher()
	{
		m_Current = -1;
	}

	SceneSwitcher::~SceneSwitcher()
	{
		if (m_Current >= 0 && m_Current < m_Scenes.size())
		{
			m_Scenes[m_Current]->Finish();
		}

		for (auto scene : m_Scenes)
		{
			delete scene;
		}
	}

	void SceneSwitcher::SwitchTo(size_t index)
	{
		if (m_Current == index)
			return;

		if (m_Current >= 0 && m_Current < m_Scenes.size())
		{
			m_Scenes[m_Current]->Finish();
		}

		m_Current = index;
		m_Scenes[m_Current]->Init();
	}

	void SceneSwitcher::Update()
	{
		if (m_Current >= 0 && m_Current < m_Scenes.size())
		{
			m_Scenes[m_Current]->Update();
		}
	}

}