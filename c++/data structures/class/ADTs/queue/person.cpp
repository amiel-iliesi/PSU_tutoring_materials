#include "person.h"

using namespace std;

Person::Person(string _name, int _age):
	name(_name),
	age(_age)
{}

Person::Person(const Person& other):
	name(other.name),
	age(other.age)
{}
