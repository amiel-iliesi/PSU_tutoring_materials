#include "person.h"

using namespace std;


Person::Person(string _name, int _age): name(_name), age(_age) {}

string Person::who() const
{
	return name;
}
