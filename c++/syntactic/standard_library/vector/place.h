#pragma once

#include <string>

struct Place {
	std::string name;
	std::string type;

	Place() = default;
	Place(std::string _name, std::string _type);
};
