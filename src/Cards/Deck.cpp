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
	}

	CardType Deck::DrawWaveformCard()
	{
		if (m_Deck.size() - m_SkipCards.size() == 0)
		{
			return CardType::None;
		}

		int index;
		bool inSkip;

		do
		{
			int idx = Random::Range(0, static_cast<uint32_t>(m_WaveformCards.size() - 1));
			index = m_WaveformCards[idx];

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

	CardType Deck::DrawCard()
	{
		if (m_Deck.size() - m_SkipCards.size() == 0)
		{
			return CardType::None;
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

	int Deck::WaveformCardsRemaining()
	{
		int remainingCards = 0;
		for (size_t idx : m_WaveformCards)
		{
			if (std::find(m_SkipCards.begin(), m_SkipCards.end(), idx) == m_SkipCards.end())
			{
				remainingCards += 1;
			}
		}

		return remainingCards;
	}

	size_t Deck::AddCard(CardType type)
	{
		m_Deck.push_back(type);
		if (Card::GetCategoryFromType(type) == CardCategory::Waveform)
		{
			m_WaveformCards.push_back(m_Deck.size() - 1);
		}
		return m_Deck.size() - 1;
	}

	void Deck::RemoveCard(size_t index)
	{
		if (index >= m_Deck.size()) return;

		auto itW = std::find(m_WaveformCards.begin(), m_WaveformCards.end(), index);
		if (itW != m_WaveformCards.end()) m_WaveformCards.erase(itW);

		auto itS = std::find(m_SkipCards.begin(), m_SkipCards.end(), index);
		if (itS != m_SkipCards.end()) m_SkipCards.erase(itS);

		m_Deck.erase(m_Deck.begin() + index);

		for (auto& idx : m_WaveformCards)
		{
			if (idx > index) --idx;
		}

		for (auto& idx : m_SkipCards)
		{
			if (idx > index) --idx;
		}
	}

	void Deck::Reset()
	{
		m_SkipCards.clear();
	}
}