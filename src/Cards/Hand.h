#pragma once

#include <array>

#include "Card.h"

namespace Resonance
{
    class Hand
    {
    public:
        Hand();
        ~Hand();

        void Construct();

        void Update();

        void Draw();

    private:
        std::array<Card*, 5> m_Hand;
    };
}