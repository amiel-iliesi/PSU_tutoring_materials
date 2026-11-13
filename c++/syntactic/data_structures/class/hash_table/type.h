#pragma once

#include <string>

struct Track
{
	std::string name;
	std::string artist;
	float duration_seconds;

	Track(const std::string& _name,
		  const std::string _artist,
		  const float& _duration_seconds);
};
