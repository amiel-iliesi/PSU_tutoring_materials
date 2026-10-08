#include "place.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	// read `vector<A> B`, as "a vector holding elements of type A, called B"
	vector<Place> places;

	// -ADDING-----------------------------------------------------
	// There are 2 main ways to add to a vector,
	// 1. push existing element
	Place temp_place("McDonalds", "Restaurant");
	places.push_back(temp_place);
	
	// 2. construct a new element without an intermediate
	places.emplace_back("Germany", "Country");

	// NOTE: this requires you to have a constructor for your object; emplace_back
	// calls that constructor. I have supplied that constructor for you, in this
	// case.

	// -ITERATING--------------------------------------------------
	// There are also 3 main ways to iterate through a vector,
	// 1. counting
	cout << "1. counting loop:\n";
	for (size_t i = 0; i < places.size(); ++i) {
		cout << "- " << places[i].name << '(' << places[i].type << ")\n";
	}

	// 2. iterator looping (standard library style; makes code more flexible than
	//    counting)
	cout << "\n2. iterator loop:\n";
	for (auto it = places.begin(); it != places.end(); ++it) {
		cout << "- " << it->name << '(' << it->type << ")\n";
	}

	// 3. range-based looping (my favorite)
	cout << "\n3. range loop:\n";
	for (const Place& p: places) {
		cout << "- " << p.name << '(' << p.type << ")\n";
	}

	return 0;
}
