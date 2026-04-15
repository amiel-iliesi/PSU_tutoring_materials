#include "list.h"
#include <vector>

int main()
{
	List people;

	std::vector<PersonInfo> info_table;
	info_table.emplace_back("Bob", "red", 25);
	info_table.emplace_back("Jenny", "turquoise", 30);

	for (const PersonInfo& info: info_table) {
		people.add_person(info);
	}

	people.display();

	return 0;
}
