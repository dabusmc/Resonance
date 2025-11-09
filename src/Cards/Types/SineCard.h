#pragma once

#include "Cards/Card.h"

namespace Resonance
{
    class SineCard : public Card
    {
    public:
        SineCard(int position);

        void Draw() override;
    };
}