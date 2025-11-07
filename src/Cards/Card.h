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

        bool IsHovered(int mouseX, int mouseY);

        virtual void Draw(bool hovered) = 0;

    protected:
        int GetXPosition();
        int GetYPosition();

    protected:
        CardType m_Type;
        int m_Position;
    };
}