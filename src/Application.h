#pragma once

#include "Scene/SceneSwitcher.h"

namespace Resonance
{
    class Application
    {
    public:
        Application();
        ~Application();

        void Run();

    private:
        SceneSwitcher m_Switcher;
    };
}