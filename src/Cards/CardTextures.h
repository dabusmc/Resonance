#pragma once
#include <string>
#include <unordered_map>

#include "raylib.h"

namespace Resonance
{
	enum class CardTexture
	{
		Blank = 0,
		Sine, Square,
		LowFrequency, HighFrequency,
		Echo,
		Phase
	};

	class CardTextures
	{
	public:
		CardTextures();
		~CardTextures();

		Texture2D& GetTexture(CardTexture texture);

	private:
		void LoadTexture(CardTexture texture, const std::string& textureName);

	private:
		std::unordered_map<CardTexture, Texture2D> m_Textures;
	};
}
