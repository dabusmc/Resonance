#include "Hand.h"

#include "SineCard.h"

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
}