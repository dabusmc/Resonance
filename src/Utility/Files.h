#pragma once

#include <string>

namespace Resonance
{
	class Files
	{
	public:
		static std::string GetCWD();
		static std::string GetFileInRes(const std::string& localPath);
	};
}
