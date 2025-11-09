#pragma once

#include <cstdint>

namespace Resonance
{
	class Random
	{
	public:
		static uint32_t UInt32();
		static uint32_t Range(uint32_t min, uint32_t max);
		static float Float();
	};
}