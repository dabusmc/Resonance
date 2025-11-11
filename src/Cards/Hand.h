#pragma once

#include <array>
#include <vector>
#include <memory>

#include "Card.h"
#include "Deck.h"

#include "Enemies/Enemy.h"

#include "Graphics/Colors.h"

namespace Resonance
{
    class Hand
    {
    public:
        Hand();
        ~Hand();

        void Reset();

        bool NextHand(Deck& deck, ColorMode mode);
        void Construct(Deck& deck, ColorMode mode);

        void ClearSelection();
        void ClearSelectedCardsFromHand();
        void ClearHand();

        void Update();

        void Draw();
        void SwapColorMode(ColorMode mode);

        bool HasLost() { return m_Lost; }

        bool CanAttack();
        ColorMode Attack(Enemy& enemy);

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
