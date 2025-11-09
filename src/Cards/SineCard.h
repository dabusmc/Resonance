#pragma once

#include "Card.h"

namespace Resonance
{
    class SineCard : public Card
    {
    public:
        SineCard();
        SineCard(int position);

        void Draw() override;
    };
}