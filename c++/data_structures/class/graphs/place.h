#pragma once

#include <string>

class Place
{
	private:
		std::string name;
	
	public:
		Place(const std::string&);

		std::string get_name() const;
};
