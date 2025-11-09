#include "Random.h"

#include <random>
#include <chrono>

namespace Resonance
{
	static uint32_t g_Seed = []{
		using namespace std::chrono;
		uint64_t t1 = time(nullptr);
		uint64_t t2 = steady_clock::now().time_since_epoch().count();
		uint64_t addr = (uint64_t)(uintptr_t)&t1;
		uint64_t rd = (uint64_t)std::random_device{}();
		return (uint32_t)(t1 ^ (t2 << 1) ^ (addr >> 3) ^ (rd << 7));
	}();

	static uint32_t PCG_Hash(uint32_t seed)
	{
		uint32_t state = seed * 747796405u + 2891336453u;
		uint32_t word = ((state >> ((state >> 28u) + 4u)) ^ state) * 277803737u;
		return (word >> 22u) ^ word;
	}

	uint32_t Random::UInt32()
	{
		g_Seed += 0x9E3779B9u;
		return PCG_Hash(g_Seed);
	}

	uint32_t Random::Range(uint32_t min, uint32_t max)
	{
		if (min > max) std::swap(min, max);

		uint32_t range = max - min + 1;

		// Generate a uniformly distributed value in [0, range)
		uint32_t threshold = -range % range;

		uint32_t r;
		do {
			r = Random::UInt32();
		} while (r < threshold);

		return min + (r % range);
	}

	float Random::Float()
	{
		return (UInt32() >> 8) * (1.0f / 16777216.0f);
	}

}
