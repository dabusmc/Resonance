#pragma once

#include <array>
#include <vector>

#include "Card.h"
#include "Deck.h"

namespace Resonance
{
    class Hand
    {
    public:
        Hand();
        ~Hand();

        void Construct(Deck& deck);

        void Update();

        void Draw();

        bool CanAttack();

    private:
        std::array<Card*, 5> m_Hand;
        std::vector<int> m_Selected;
    };
}