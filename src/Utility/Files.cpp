#include "Files.h"

#include <filesystem>

namespace Resonance
{
	std::string Files::GetCWD()
	{
		std::filesystem::path cwd = std::filesystem::current_path();
		return cwd.string();
	}

	std::string Files::GetFileInRes(const std::string &localPath)
	{
		return GetCWD() + "/res/" + localPath;
	}
}