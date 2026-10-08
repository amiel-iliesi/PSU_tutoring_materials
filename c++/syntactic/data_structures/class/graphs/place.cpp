#include "place.h"

using namespace std;

Place::Place(const string& name_in)
{
	name = name_in;
}

string Place::get_name() const
{
	return name;
}
