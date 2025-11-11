#include "CardColors.h"

namespace Resonance
{
	Color CardColors::GetColor1(ColorMode mode)
	{
		switch (mode)
		{
			case ColorMode::Low:
				return c_LowColor1;
			case ColorMode::Mid:
				return c_MidColor1;
			case ColorMode::High:
				return c_HighColor1;
		}
		return WHITE;
	}

	Color CardColors::GetColor2(ColorMode mode)
	{
		switch (mode)
		{
			case ColorMode::Low:
				return c_LowColor2;
			case ColorMode::Mid:
				return c_MidColor2;
			case ColorMode::High:
				return c_HighColor2;
		}
		return WHITE;
	}

	Color CardColors::GetColor3(ColorMode mode)
	{
		switch (mode)
		{
			case ColorMode::Low:
				return c_LowColor3;
			case ColorMode::Mid:
				return c_MidColor3;
			case ColorMode::High:
				return c_HighColor3;
		}
		return WHITE;
	}

	Color CardColors::GetColor4(ColorMode mode)
	{
		switch (mode)
		{
			case ColorMode::Low:
				return c_LowColor4;
			case ColorMode::Mid:
				return c_MidColor4;
			case ColorMode::High:
				return c_HighColor4;
		}
		return WHITE;
	}

	Color CardColors::GetColor5(ColorMode mode)
	{
		switch (mode)
		{
			case ColorMode::Low:
				return c_LowColor5;
			case ColorMode::Mid:
				return c_MidColor5;
			case ColorMode::High:
				return c_HighColor5;
		}
		return WHITE;
	}

	Color CardColors::GetColor6(ColorMode mode)
	{
		switch (mode)
		{
			case ColorMode::Low:
				return c_LowColor6;
			case ColorMode::Mid:
				return c_MidColor6;
			case ColorMode::High:
				return c_HighColor6;
		}
		return WHITE;
	}
}
