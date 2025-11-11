#pragma once

#include <raylib.h>

namespace Resonance
{
	enum class ColorMode
	{
		Mid = 0,
		Low, High
	};

	const Color c_LowColor1 = GetColor(0x0A202FFF);
	const Color c_LowColor2 = GetColor(0x302D6AFF);
	const Color c_LowColor3 = GetColor(0x871C3EFF);
	const Color c_LowColor4 = GetColor(0xD32836FF);

	const Color c_MidColor1 = GetColor(0x3E3A42FF);
	const Color c_MidColor2 = GetColor(0x877286FF);
	const Color c_MidColor3 = GetColor(0xF0B695FF);
	const Color c_MidColor4 = GetColor(0xE9F5DAFF);

	const Color c_HighColor1 = GetColor(0x131626FF);
	const Color c_HighColor2 = GetColor(0x4D4D80FF);
	const Color c_HighColor3 = GetColor(0xE6A1CfFF);
	const Color c_HighColor4 = GetColor(0xFFE6EAFF);
}