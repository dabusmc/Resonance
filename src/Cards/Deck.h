#pragma once

#include <vector>

#include "Card.h"

namespace Resonance
{
	class Deck
	{
	public:
		Deck();
		~Deck();

		size_t AddCard(CardType type);
		void RemoveCard(size_t index);

		CardType DrawWaveformCard();
		CardType DrawCard();

		int CardsRemaining() { return m_Deck.size() - m_SkipCards.size(); }

		void Reset();

	private:
		std::vector<CardType> m_Deck;
		std::vector<size_t> m_SkipCards;
		std::vector<size_t> m_WaveformCards;
	};
}