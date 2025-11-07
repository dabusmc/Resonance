#include "Hand.h"

#include "SineCard.h"

#include "raylib.h"

namespace Resonance
{
    Hand::Hand()
    {
        m_Hand = std::array<Card*, 5>();
    }

    Hand::~Hand()
    {
        for (int i = 0; i < m_Hand.size(); i++)
        {
            if (m_Hand[i] != nullptr)
            {
                delete m_Hand[i];
            }
        }
    }

    void Hand::Construct()
    {
        // NOTE: This will be replaced with drawing from the deck
        for (int i = 0; i < 5; i++)
        {
            m_Hand[i] = new SineCard(i);
        }
    }

    void Hand::Update()
    {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();

        bool hoveredFound = false;

        for (int i = 0; i < 5; i++)
        {
            if (hoveredFound)
            {
                m_Hand[i]->SetHovered(false);
                continue;
            }

            m_Hand[i]->UpdateHovered(mouseX, mouseY);
            hoveredFound = m_Hand[i]->IsHovered();
        }
    }

    void Hand::Draw()
    {
        for (int i = 0; i < 5; i++)
        {
            m_Hand[i]->Draw();
        }
    }
}