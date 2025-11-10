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
        m_Hand = std::array<Card*, 5>();
    }

    Hand::~Hand()
    {
        ClearHand();
    }

    void Hand::NextHand(Deck &deck)
    {
        if (deck.CardsRemaining() == 0)
        {
            std::cout << "Out of Cards! YOU LOSE!!!!" << std::endl;
        }

        ClearSelection();
        ClearHand();
        Construct(deck);
    }

    void Hand::Construct(Deck& deck)
    {
        m_WaveformCardSelected = false;
        int waveformIndex = Random::Range(0, 4);

        for (int i = 0; i < 5; i++)
        {
            m_Hand[i] = nullptr;

            CardType type;
            if (i == waveformIndex)
            {
                type = deck.DrawWaveformCard();
            }
            else
            {
                type = deck.DrawCard();
            }

            if (type == CardType::None)
            {
                m_Hand[i] = nullptr;
            }
            else
            {
                m_Hand[i] = ConstructCardFromType(type, i);
            }
        }
    }

    void Hand::ClearSelection()
    {
        for (int i = 0; i < 5; i++)
        {
            if (!m_Hand[i]) continue;
            m_Hand[i]->SetSelected(false);
        }
        m_WaveformCardSelected = false;
        m_Selected.clear();
    }

    void Hand::ClearHand()
    {
        for (int i = 0; i < 5; i++)
        {
            delete m_Hand[i];
            m_Hand[i] = nullptr;
        }
    }

    void Hand::Update()
    {
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
        for (int i = 0; i < 5; i++)
        {
            if (!m_Hand[i]) continue;
            m_Hand[i]->Draw();
        }
    }

    bool Hand::CanAttack()
    {
        if (m_Selected.size() == 3)
        {
            for (auto& i : m_Selected)
            {
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
        int damageAmount = 0;

        for (int i = 0; i < m_Selected.size(); i++)
        {
            int index = m_Selected[i];
            Card* card = m_Hand[index];

            switch (card->GetCategory())
            {
                case CardCategory::Waveform:
                {
                    auto* waveform = dynamic_cast<WaveformCard*>(card);
                    damageAmount += waveform->GetBaseDamage();
                    break;
                }
                case CardCategory::Amplitude:
                {
                    auto* amplitude = dynamic_cast<AmplitudeCard*>(card);
                    break;
                }
                case CardCategory::Frequency:
                {
                    auto* frequency = dynamic_cast<FrequencyCard*>(card);
                    break;
                }
                case CardCategory::Utility:
                {
                    auto* utility = dynamic_cast<UtilityCard*>(card);
                    break;
                }
            }
        }

        enemy.Damage(damageAmount, false);

        std::cout << enemy.GetHealth() << std::endl;
        std::cout << enemy.GetArmor() << std::endl;
    }
}
