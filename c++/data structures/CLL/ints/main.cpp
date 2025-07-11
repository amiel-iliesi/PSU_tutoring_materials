#include "CLL.h"
#include <iostream>
#include <cstdlib> // rand(), srand(..)
#include <ctime> // time(..)

using std::cout, std::cerr, std::endl;

int main() {
	CLL list;

	srand(time(NULL));

	for (int i = 0; i < 10; ++i)
		list.insert(rand()%5+1, 0);
	
	list.display();
	cout << "The CLL has " << list.size() << " elements" << endl;

	cout << "Copying all elements except for 2s..." << endl;
	CLL new_list;
	new_list.copy_except(list, 2);
	cout << "New list:\n";
	new_list.display();

	return 0;
}
