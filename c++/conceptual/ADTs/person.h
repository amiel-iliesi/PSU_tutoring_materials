#pragma once

#include <string>

struct Person
{
	std::string name;
	unsigned age;

	Person(const std::string& _name, const unsigned& _age):
		name(_name), age(_age)
	{}
};
