#include "list.h"
#include <cstring>

int main()
{
	List people;

	PersonInfo info_table[2];

	info_table[0].name = new char[4];
	strcpy(info_table[0].name, "Bob");
	info_table[0].favorite_color = new char[4];
	strcpy(info_table[0].favorite_color, "red");
	info_table[0].age = 25;

	info_table[1].name = new char[6];
	strcpy(info_table[1].name, "Jenny");
	info_table[1].favorite_color = new char[10];
	strcpy(info_table[1].favorite_color, "turquoise");
	info_table[1].age = 25;

	for (int i=0; i < 2; ++i) {
		people.add_person(info_table[i]);
	}

	people.display();

	for (int i=0; i < 2; ++i) {
		delete [] info_table[i].name;
		delete [] info_table[i].favorite_color;
	}

	return 0;
}
