#pragma once

#include <string>

class Person
{
	private:
		std::string name;
		int age;
	
	public:
		Person() = default;
		Person(std::string, int);

		std::string who() const;
};
