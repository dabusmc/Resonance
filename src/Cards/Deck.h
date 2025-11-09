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

		template<typename T, typename... Args>
		size_t AddCard(Args&& ... args)
		{
			T* card = new T(std::forward<Args>(args)...);
			m_Deck.push_back(card);
			return m_Deck.size() - 1;
		}

		void RemoveCard(size_t index);

		Card* DrawCard();

		void Reset();

	private:
		std::vector<Card*> m_Deck;
		std::vector<size_t> m_SkipCards;
	};
}