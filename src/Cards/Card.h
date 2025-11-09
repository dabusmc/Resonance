#pragma once

namespace Resonance
{
    enum class CardCategory
    {
        Waveform = 0,
        Amplitude, Frequency, Utility
    };

    enum class CardType
    {
        None = 0,
        Sine,
        Echo,
        LowFrequency,
        Phase
    };

    class Card
    {
    public:
        static CardCategory GetCategoryFromType(CardType type);

        Card(CardType type, int position);
        virtual ~Card() = default;

        CardType GetCardType() const { return m_Type; }
        CardCategory GetCategory() const { return m_Category; }
        int GetPosition() const { return m_Position; }
        bool IsHovered() const { return m_Hovered; }
        bool IsSelected() const { return m_Selected; }

        void SetPosition(int position);

        void UpdateHovered(int mouseX, int mouseY);
        void SetHovered(bool hovered);

        void SetSelected(bool selected);

        virtual void Draw() = 0;

    protected:
        int GetXPosition();
        int GetYPosition();

    protected:
        CardType m_Type;
        CardCategory m_Category;
        int m_Position;

        bool m_Hovered;
        bool m_Selected;
    };
}