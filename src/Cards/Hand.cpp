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

    bool Hand::NextHand(Deck &deck)
    {
        std::cout << "Begin NextHand()" << std::endl;

        if (m_AttackRunning)
        {
            std::cout << "Attack is currently running. Deferring to next frame" << std::endl;
            std::cout << "End NextHand()" << std::endl;
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

        ClearSelection();
        ClearHand();
        Construct(deck);

        std::cout << "End NextHand()" << std::endl;

        return true;
    }

    void Hand::Construct(Deck& deck)
    {
        std::cout << "Begin Construct()" << std::endl;

        m_WaveformCardSelected = false;
        m_HandHasWaveformCard = false;
        int waveformIndex = Random::Range(0, 4);

        for (int i = 0; i < 5; i++)
        {
            CardType type = (i == waveformIndex) ? deck.DrawWaveformCard() : deck.DrawCard();

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

        std::cout << "End Construct()" << std::endl;
    }

    void Hand::ClearSelection()
    {
        std::cout << "Begin ClearSelection()" << std::endl;

        for (auto& card : m_Hand)
        {
            if (card) card->SetSelected(false);
        }
        m_WaveformCardSelected = false;
        m_Selected.clear();

        std::cout << "End ClearSelection()" << std::endl;
    }

    void Hand::ClearHand()
    {
        std::cout << "Begin ClearHand()" << std::endl;

        for (auto& card : m_Hand)
        {
            card.reset();
        }

        std::cout << "End ClearHand()" << std::endl;
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
        if (m_Selected.size() == 3)
        {
            for (auto i : m_Selected)
            {
                if (i < 0 || i >= 5) continue;            // bounds check
                if (!m_Hand[i]) continue;                 // null check
                if (m_Hand[i]->GetCategory() == CardCategory::Waveform)
                {
                    return true;
                }
            }

            return false;
        }

        return false;
    }

    void Hand::Attack(Enemy& enemy)
    {
        m_AttackRunning = true;

        std::cout << "Attack Called (current state)" << std::endl;
        std::cout << "\tm_WaveformCardSelected = " << m_WaveformCardSelected << std::endl;
        std::cout << "\tm_Selected.size() = " << m_Selected.size() << std::endl;
        std::cout << "\tm_Selected = {" << std::endl;
        for (int i = 0; i < m_Selected.size(); i++)
        {
            std::cout << "\t\t" << m_Selected[i] << std::endl;
        }
        std::cout << "\t}" << std::endl;
        std::cout << "\tm_Hand = {" << std::endl;
        for (int i = 0; i < 5; i++)
        {
            std::cout << "\t\t" << m_Hand[i].get() << std::endl;
        }
        std::cout << "\t}" << std::endl;

        if (m_Selected.empty()) return;
        std::cout << "m_Selected Not Empty" << std::endl;

        int damageAmount = 0;
        bool ignoreArmor = false;

        std::vector<Card*> selectedCards;
        std::cout << "Creating selected cards" << std::endl;
        for (int idx : m_Selected)
        {
            if (idx < 0 || idx >= 5)
            {
                std::cout << "\tInvalid Index: " << idx << std::endl;
                continue;
            }

            if (!m_Hand[idx])
            {
                std::cout << "\tm_Hand[" << idx << "] = nullptr" << std::endl;
                continue;
            }

            selectedCards.push_back(m_Hand[idx].get());
        }
        std::cout << "Created selected cards" << std::endl;

        int i = 0;
        for (Card* card : selectedCards)
        {
            std::cout << "Data for Card[" << i << "]" << std::endl;
            switch (card->GetCategory())
            {
                case CardCategory::Waveform:
                {
                    std::cout << "\tCard Category is Waveform" << std::endl;
                    if (auto* waveform = dynamic_cast<WaveformCard*>(card))
                    {
                        std::cout << "\tCard has " << waveform->GetBaseDamage() << " base damage" << std::endl;
                        damageAmount += waveform->GetBaseDamage();
                    }
                    break;
                }
                case CardCategory::Amplitude:
                {
                    std::cout << "\tCard Category is Amplitude" << std::endl;
                    break;
                }
                case CardCategory::Frequency:
                {
                    std::cout << "\tCard Category is Frequency" << std::endl;
                    break;
                }
                case CardCategory::Utility:
                {
                    std::cout << "\tCard Category is Utility" << std::endl;
                    if (card->GetCardType() == CardType::Phase)
                    {
                        std::cout << "\tCard is a Phase Card" << std::endl;
                        ignoreArmor = true;
                    }

                    break;
                }
            }

            i += 1;
        }

        std::cout << "Damage Amount: " << damageAmount << std::endl;
        std::cout << "Ignore Armor: " << ignoreArmor << std::endl;

        std::cout << "Calling damage" << std::endl;
        enemy.Damage(damageAmount, ignoreArmor);
        std::cout << "Called damage" << std::endl;

        std::cout << "Enemy Health: " << enemy.GetHealth() << std::endl;
        std::cout << "Enemy Armor: " << enemy.GetArmor() << std::endl;

        std::cout << std::endl;

        m_AttackRunning = false;
    }
}
