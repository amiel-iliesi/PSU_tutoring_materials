#include "person.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<Person> people;

	// emplace_back is like push_back, but it lets you construct your object!
	people.emplace_back("Amiel", 25);
	people.emplace_back("Jeff", 35);
	people.emplace_back("Karla", 58);


	
	// loop method 1: use indecies
	cout << "displaying people using method 1...\n";
	
	for (int i = 0; i < people.size(); ++i) {
		people[i].display();
	}

	cout << '\n';


	
	// loop method 2: use iterators
	cout << "displaying people using method 2...\n";
	
	for (auto it = people.begin(); it != people.end(); ++it) {
		it->display(); // need to dereference iterator to use object at location
	}

	cout << '\n';
	


	// loop method 3: container range based loop (this one is new! (and my favorite))
	cout << "displaying people using method 3...\n";
	
	for (const Person & person: people) { // read it like "for each person in people"
		person.display();
	}

	cout << '\n';


	
	// look how easy it is to remove an item
	cout << "removing Karla...\n";

	// the two below can be one line, just separated for clarity
	auto karlas_position = people.begin() + 2; // * people[0 + 2]
	people.erase(karlas_position);
		// * the type is: vector<People>::iterator

	for (const Person & person: people) {
		person.display();
	}

	return 0;
}
