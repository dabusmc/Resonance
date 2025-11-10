#pragma once

#include <array>
#include <vector>

#include "Card.h"
#include "Deck.h"
#include "Enemies/Enemy.h"

namespace Resonance
{
    class Hand
    {
    public:
        Hand();
        ~Hand();

        void NextHand(Deck& deck);
        void Construct(Deck& deck);

        void ClearSelection();
        void ClearHand();

        void Update();

        void Draw();

        bool CanAttack();
        void Attack(Enemy& enemy);

    private:
        std::array<Card*, 5> m_Hand;
        std::vector<int> m_Selected;
        bool m_WaveformCardSelected;
    };
}
