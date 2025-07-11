#include "hashtable.h"
#include <iostream>
#include <fstream>

using namespace std;

// constants
const char FILENAME[] = "data.txt";
const int STRSIZE = 0xFFF;




// main helper functions
void in_table(const Hashtable & table, const char * name)
{
	cout << "is someone named \"" << name << "\" in the table?: "
		 << (table.has(name) ? "yes" : "no") << endl;
}

void remove(Hashtable & table, const char * name)
{
	cout << "testing remove, removing \"" << name << "\"... "
		 << (table.remove(name) ? "success" : "failure") << endl;
}




int main()
{
	Hashtable people(5);
	char temp_name[STRSIZE];
	int temp_age;

	fstream file(FILENAME, ios_base::in);
	if (!file) {
		cout << "error opening file, closing..." << endl;
		return 1;
	}

	while (!file.eof()) {
		file.getline(temp_name, STRSIZE, ',');
		file >> temp_age;
		file.ignore();

		people.insert(temp_name, temp_age);

		file.peek();
	}

	cout << "displaying everybody:" << endl;
	cout << "---------------------------------" << endl;
	people.display();
	cout << "---------------------------------" << endl;

	cout << '\n';

	cout << "testing retreive, retrieving \"Amiel\"..." << endl;
	people.retrieve("Amiel").display();

	cout << '\n';

	in_table(people, "Snowball");
	in_table(people, "abcdefg");

	cout << '\n';

	remove(people, "Amiel");
	in_table(people, "Amiel");
	remove(people, "Amiel");

	return 0;
}
