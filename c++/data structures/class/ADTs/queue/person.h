#pragma once

#include <string>

struct Person {
	std::string name;
	int age;

	Person(std::string name, int age);
	Person(const Person& other);
};
