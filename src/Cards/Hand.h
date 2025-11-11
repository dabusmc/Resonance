#pragma once

#include <array>
#include <vector>
#include <memory>

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

        void Reset();

        bool NextHand(Deck& deck);
        void Construct(Deck& deck);

        void ClearSelection();
        void ClearSelectedCardsFromHand();
        void ClearHand();

        void Update();

        void Draw();

        bool HasLost() { return m_Lost; }

        bool CanAttack();
        void Attack(Enemy& enemy);

    private:
        std::array<std::unique_ptr<Card>, 5> m_Hand;
        std::vector<int> m_Selected;

        CardTextures m_CardTextures;

        bool m_HandHasWaveformCard;
        bool m_WaveformCardSelected;

        bool m_Lost;

        bool m_AttackRunning;
    };
}
