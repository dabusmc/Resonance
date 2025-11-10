#pragma once

#include "Cards/Base/WaveformCard.h"

namespace Resonance
{
    class SineCard : public WaveformCard
    {
    public:
        SineCard(int position);

        void Draw() override;
    };
}
