#include "person.h"
#include <cstring>
#include <iostream>

using namespace std;

// CONSTRUCTORS
Person::Person(): name(nullptr), age(0) {}

Person::Person(const char * new_name, int new_age): name(nullptr)
{
	set(new_name, new_age);
}

Person::Person(const Person & other): name(nullptr)
{
	*this = other;
}

Person::~Person()
{
	clear();
}



// HELPER FUNCTIONS
void Person::operator=(const Person & other)
{
	set(other.name, other.age);
}

void Person::clear()
{
	delete [] name;
	name = nullptr;
}

void Person::set(const char * new_name, int new_age)
{
	clear();

	name = new char[strlen(new_name) + 1];
	strcpy(name, new_name);

	age = new_age;
}



// OUTPUT
void Person::display() const
{
	cout << "name: " << name
		 << "\nage: " << age << '\n';
}
