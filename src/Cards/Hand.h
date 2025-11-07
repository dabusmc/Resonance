#pragma once

#include <array>
#include <vector>

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

        int GetSelectedCount() const { return m_Selected.size(); }

    private:
        std::array<Card*, 5> m_Hand;
        std::vector<int> m_Selected;
    };
}