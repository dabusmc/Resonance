#include "Hand.h"

#include "SineCard.h"
#include "EchoCard.h"

#include "raylib.h"

namespace Resonance
{
    const int c_SelectionLimit = 3;

    Hand::Hand()
    {
        m_Hand = std::array<Card*, 5>();
    }

    Hand::~Hand()
    {
    }

    void Hand::Construct(Deck& deck)
    {
        for (int i = 0; i < 5; i++)
        {
            m_Hand[i] = deck.DrawCard();
            m_Hand[i]->SetPosition(i);
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
                if (m_Hand[i]->GetType() == CardType::Waveform)
                {
                    return true;
                }
            }

            return false;
        }

        return false;
    }
}