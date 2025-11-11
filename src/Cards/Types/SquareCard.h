#pragma once

#include "Cards/Base/WaveformCard.h"

namespace Resonance
{
    class SquareCard : public WaveformCard
    {
    public:
        SquareCard(int position);

        void Draw(CardTextures& textures) override;
    };
}
