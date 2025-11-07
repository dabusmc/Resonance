#pragma once

namespace Resonance
{
    enum class CardType
    {
        Waveform = 0,
        Amplitude, Frequency, Utility
    };

    class Card
    {
    public:
        Card(CardType type, int position);

        CardType GetType() const { return m_Type; }
        int GetPosition() const { return m_Position; }
        bool IsHovered() const { return m_Hovered; }
        bool IsSelected() const { return m_Selected; }

        void UpdateHovered(int mouseX, int mouseY);
        void SetHovered(bool hovered);

        void SetSelected(bool selected);

        virtual void Draw() = 0;

    protected:
        int GetXPosition();
        int GetYPosition();

    protected:
        CardType m_Type;
        int m_Position;

        bool m_Hovered;
        bool m_Selected;
    };
}