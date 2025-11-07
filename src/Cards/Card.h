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

        CardType GetType() { return m_Type; }
        int GetPosition() { return m_Position; }
        bool IsHovered() { return m_Hovered;}

        void UpdateHovered(int mouseX, int mouseY);
        void SetHovered(bool hovered);

        virtual void Draw() = 0;

    protected:
        int GetXPosition();
        int GetYPosition();

    protected:
        CardType m_Type;
        bool m_Hovered;
        int m_Position;
    };
}