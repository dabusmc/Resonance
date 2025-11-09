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
        for (auto card : m_Hand)
        {
            delete card;
        }
    }

    void Hand::Construct(Deck& deck)
    {
        int waveformIndex = Random::Range(0, 4);

        for (int i = 0; i < 5; i++)
        {
            delete m_Hand[i];

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
                std::cout << "Out of cards" << std::endl;
            }
            else
            {
                m_Hand[i] = ConstructCardFromType(type, i);
            }
        }
    }

    void Hand::Update()
    {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();

        int hoveredFound = -1;

        for (int i = 0; i < 5; i++)
        {
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
                m_Hand[hoveredFound]->SetSelected(true);
                m_Selected.push_back(hoveredFound);
            }
        }

        if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            for (int i = 0; i < 5; i++)
            {
                m_Hand[i]->SetSelected(false);
            }
            m_Selected.clear();
        }
    }

    void Hand::Draw()
    {
        for (int i = 0; i < 5; i++)
        {
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
}
