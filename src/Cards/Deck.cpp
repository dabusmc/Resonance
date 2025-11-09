#include "Deck.h"

#include <algorithm>
#include <iostream>

#include "Utility/Random.h"

namespace Resonance
{
	Deck::Deck()
	{

	}

	Deck::~Deck()
	{
		for (auto card : m_Deck)
		{
			delete card;
		}
	}

	Card* Deck::DrawCard()
	{
		if (m_Deck.size() - m_SkipCards.size() == 0)
		{
			return nullptr;
		}

		int index;
		bool inSkip;

		do
		{
			index = Random::Range(0, static_cast<uint32_t>(m_Deck.size() - 1));

			inSkip = false;
			for (size_t skipped : m_SkipCards)
			{
				if (skipped == index)
				{
					inSkip = true;
					break;
				}
			}
		} while (inSkip);

		m_SkipCards.push_back(index);
		return m_Deck[index];
	}

	void Deck::RemoveCard(size_t index)
	{
		m_Deck.erase(m_Deck.begin() + index);
	}

	void Deck::Reset()
	{
		m_SkipCards.clear();
	}
}