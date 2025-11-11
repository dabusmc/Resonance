#include "CardTextures.h"

#include <iostream>
#include <ostream>

#include "Utility/Files.h"

namespace Resonance
{
	CardTextures::CardTextures()
	{
		LoadTexture(CardTexture::Blank, "blank");

		// Waveforms
		LoadTexture(CardTexture::Sine, "sine");
		LoadTexture(CardTexture::Square, "square");

		// Frequencies
		LoadTexture(CardTexture::LowFrequency, "low_frequency");
		LoadTexture(CardTexture::HighFrequency, "high_frequency");

		// Amplitude
		LoadTexture(CardTexture::Echo, "echo");

		// Utility
		LoadTexture(CardTexture::Phase, "phase");
	}

	CardTextures::~CardTextures()
	{
		for (auto& el : m_Textures)
		{
			UnloadTexture(el.second);
		}
	}

	Texture2D& CardTextures::GetTexture(CardTexture texture)
	{
		return m_Textures[texture];
	}

	void CardTextures::LoadTexture(CardTexture texture, const std::string& textureName)
	{
		std::string path = Files::GetFileInRes("textures/" + textureName + ".png");
		Image image = LoadImage(path.c_str());
		m_Textures[texture] = LoadTextureFromImage(image);
		UnloadImage(image);
	}
}