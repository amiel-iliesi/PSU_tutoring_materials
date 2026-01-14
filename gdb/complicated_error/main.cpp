#include "list.h"
#include <iostream>

using namespace std;

int main()
{
	List people;
	people.emplace("Jeff", 39);
	people.emplace("Josiah", 27);
	people.emplace("Johnathan", 22);
	people.emplace("Jimmy", 75);
	people.emplace("James", 36);
	people.emplace("Joan", 28);
	people.emplace("Juan", 41);

	people.display();
	people.display_neighbors("Jimmy");
	people.display_neighbors("Jeff");
	people.display_neighbors("Xavier");
}
