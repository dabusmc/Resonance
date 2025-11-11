#pragma once

#include <raylib.h>

namespace Resonance
{
	enum class ColorMode
	{
		Mid = 0,
		Low, High
	};

	const Color c_LowColor1 = GetColor(0x240124ff);
	const Color c_LowColor2 = GetColor(0x3d0234ff);
	const Color c_LowColor3 = GetColor(0x6d0355ff);
	const Color c_LowColor4 = GetColor(0x92055eff);
	const Color c_LowColor5 = GetColor(0xb60b53ff);
	const Color c_LowColor6 = GetColor(0xdb123cff);

	const Color c_MidColor1 = GetColor(0x313638ff);
	const Color c_MidColor2 = GetColor(0x574729ff);
	const Color c_MidColor3 = GetColor(0x975330ff);
	const Color c_MidColor4 = GetColor(0xc57938ff);
	const Color c_MidColor5 = GetColor(0xffad3bff);
	const Color c_MidColor6 = GetColor(0xffe596ff);

	const Color c_HighColor1 = GetColor(0x2a173bff);
	const Color c_HighColor2 = GetColor(0x3f2c5fff);
	const Color c_HighColor3 = GetColor(0x443f7bff);
	const Color c_HighColor4 = GetColor(0x4c5c87ff);
	const Color c_HighColor5 = GetColor(0x69809eff);
	const Color c_HighColor6 = GetColor(0x95c5acff);
}