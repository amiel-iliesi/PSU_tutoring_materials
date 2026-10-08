#include <iostream>
#include <cstring>

using namespace std;

struct Place
{
	char* name;
	char* description;
	char* attractions;
};

int main()
{
	char temp[2048];

	Place france; // {"Paris", "Captial of France", "Eiffel Tower, Bakery"}

	// name
	cout << ">>> name: ";
	cin.getline(temp, 2048);

	france.name = new char[strlen(temp) + 1];
	strcpy(france.name, temp);

	// description
	cout << ">>> description: ";
	cin.getline(temp, 2048);

	france.description = new char[strlen(temp) + 1];
	strcpy(france.description, temp);

	// attractions
	cout << ">>> attractions: ";
	cin.getline(temp, 2048);

	france.attractions = new char[strlen(temp) + 1];
	strcpy(france.attractions, temp);


	cout << "France:\n-------\n";
	cout << "name: " << france.name << endl;
	cout << "description: " << france.description << endl;
	cout << "attractions: " << france.attractions << endl;


	return 0;
}
