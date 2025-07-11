#include <iostream>

#include <cstdlib>
#include <ctime>

#include "list.h"

using namespace std;

int main()
{
	srand(time(NULL));

	// original list
	List dll;

	// 8 random values from [0, 256)
	for (int i = 0; i < 8; ++i) {
		dll.push(rand()%256);
	}

	// make a copy
	List copy_of_dll;

	// copy except largest; capture largest in variable
	int max_of_dll = copy_of_dll.copy_except_largest(dll);

	// display results
	cout << "original list:\n";
	dll.display();

	cout << "\ncopy of list without max value:\n";
	copy_of_dll.display();

	cout << "\nlargest in dll: " << max_of_dll << endl;
	
	return 0;
}
