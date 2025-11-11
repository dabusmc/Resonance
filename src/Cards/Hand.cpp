#include "Hand.h"

#include <iostream>

#include "Types/SineCard.h"
#include "Types/EchoCard.h"

#include "raylib.h"
#include "Types/LowFrequencyCard.h"
#include "Types/PhaseCard.h"
#include "Utility/Random.h"

namespace Resonance
{
    const int c_SelectionLimit = 3;

    static Card* ConstructCardFromType(CardType type, int position)
    {
        switch (type)
        {
            case CardType::Sine:
                return new SineCard(position);
            case CardType::Phase:
                return new PhaseCard(position);
            case CardType::Echo:
                return new EchoCard(position);
            case CardType::LowFrequency:
                return new LowFrequencyCard(position);
            default:
                return new SineCard(position);
        }
    }

    Hand::Hand()
    {
        for (auto& card : m_Hand)
        {
            card.reset();
        }

        m_AttackRunning = false;
    }

    Hand::~Hand()
    {
        ClearHand();
    }

    void Hand::Reset()
    {
        ClearSelection();
        ClearHand();
        m_AttackRunning = false;
        m_Lost = false;
    }

    bool Hand::NextHand(Deck &deck)
    {
        if (m_Lost)
            return true;

        if (m_AttackRunning)
        {
            return false;
        }

        if (deck.CardsRemaining() == 0)
        {
            std::cout << "Out of Cards! YOU LOSE!!!!" << std::endl;
            m_Lost = true;
        }

        if (deck.WaveformCardsRemaining() == 0)
        {
            std::cout << "No more waveform cards! YOU LOSE!!!!" << std::endl;
            m_Lost = true;
        }

        ClearSelectedCardsFromHand();
        ClearSelection();
        Construct(deck);

        return true;
    }

    void Hand::Construct(Deck& deck)
    {
        if (m_Lost)
            return;

        m_WaveformCardSelected = false;
        m_HandHasWaveformCard = false;
        int waveformIndex = Random::Range(0, 4);

        for (int i = 0; i < 5; i++)
        {
            if (!m_Hand[i])
            {
                CardType type;
                if (m_ForceWaveformCard || (i == waveformIndex && !m_HandHasWaveformCard))
                {
                    type = deck.DrawWaveformCard();
                }
                else
                {
                    type = deck.DrawCard();
                }

                if (deck.WaveformCardsRemaining() == 0)
                {
                    if (!m_HandHasWaveformCard)
                    {
                        std::cout << "No more waveform cards! YOU LOSE!!!!" << std::endl;
                        m_Lost = true;
                        return;
                    }
                }

                if (type == CardType::None)
                {
                    m_Hand[i].reset();
                }
                else
                {
                    m_Hand[i] = std::unique_ptr<Card>(ConstructCardFromType(type, i));
                    if (m_Hand[i]->GetCategory() == CardCategory::Waveform)
                    {
                        m_HandHasWaveformCard = true;
                    }
                }
            }
        }
    }

    void Hand::ClearSelection()
    {
        for (auto& card : m_Hand)
        {
            if (card) card->SetSelected(false);
        }
        m_WaveformCardSelected = false;
        m_Selected.clear();
    }

    void Hand::ClearSelectedCardsFromHand()
    {
        int resetCount = 0;
        for (int index : m_Selected)
        {
            if (m_Hand[index])
            {
                m_Hand[index].reset();
                resetCount += 1;
            }
        }

        m_HandHasWaveformCard = false;
        for (auto& card : m_Hand)
        {
            if (!card) continue;

            if (card->GetCategory() == CardCategory::Waveform)
            {
                m_HandHasWaveformCard = true;
            }
        }

        if (resetCount == 1 && !m_HandHasWaveformCard)
        {
            m_ForceWaveformCard = true;
        }
    }

    void Hand::ClearHand()
    {
        for (auto& card : m_Hand)
        {
            card.reset();
        }
        m_HandHasWaveformCard = false;
    }

    void Hand::Update()
    {
        if (m_Lost)
            return;

        int mouseX = GetMouseX();
        int mouseY = GetMouseY();

        int hoveredFound = -1;

        for (int i = 0; i < 5; i++)
        {
            if (!m_Hand[i]) continue;

            if (hoveredFound != -1)
            {
                m_Hand[i]->SetHovered(false);
                continue;
            }

            m_Hand[i]->UpdateHovered(mouseX, mouseY);
            if (m_Hand[i]->IsHovered())
            {
                hoveredFound = i;
            }
        }

        if (m_Selected.size() < c_SelectionLimit)
        {
            if (hoveredFound != -1 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                if (!m_Hand[hoveredFound]) return;

                if (m_Hand[hoveredFound]->GetCategory() == CardCategory::Waveform)
                {
                    if (m_WaveformCardSelected)
                    {
                        std::cout << "You can only select one waveform card" << std::endl;
                        return;
                    }

                    m_WaveformCardSelected = true;
                }
                m_Hand[hoveredFound]->SetSelected(true);
                m_Selected.push_back(hoveredFound);
            }
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            ClearSelection();
        }
    }

    void Hand::Draw()
    {
        for (auto& card : m_Hand)
        {
            if (card && !m_Lost) card->Draw();
        }
    }

    bool Hand::CanAttack()
    {
        return m_WaveformCardSelected;
    }

    void Hand::Attack(Enemy& enemy)
    {
        m_AttackRunning = true;

        if (m_Selected.empty()) return;

        int damageAmount = 0;
        bool ignoreArmor = false;

        std::vector<Card*> selectedCards;
        for (int idx : m_Selected)
        {
            if (idx < 0 || idx >= 5) continue;
            if (!m_Hand[idx]) continue;

            selectedCards.push_back(m_Hand[idx].get());
        }

        int i = 0;
        for (Card* card : selectedCards)
        {
            switch (card->GetCategory())
            {
                case CardCategory::Waveform:
                {
                    if (auto* waveform = dynamic_cast<WaveformCard*>(card))
                    {
                        damageAmount += waveform->GetBaseDamage();
                    }
                    break;
                }
                case CardCategory::Amplitude:
                {
                    break;
                }
                case CardCategory::Frequency:
                {
                    break;
                }
                case CardCategory::Utility:
                {
                    if (card->GetCardType() == CardType::Phase)
                    {
                        ignoreArmor = true;
                    }

                    break;
                }
            }

            i += 1;
        }

        std::cout << "Damage Amount: " << damageAmount << std::endl;
        std::cout << "Ignore Armor: " << ignoreArmor << std::endl;

        enemy.Damage(damageAmount, ignoreArmor);

        std::cout << "Enemy Health: " << enemy.GetHealth() << std::endl;
        std::cout << "Enemy Armor: " << enemy.GetArmor() << std::endl;

        m_AttackRunning = false;
    }
}
