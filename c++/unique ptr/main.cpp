#include <iostream>
#include <memory> // for unique_ptr
#include "list.h"

using namespace std;

int main()
{
	List integers;
	for (int i: {1,3,2,5,6}) {
		integers.insert(move(i));
	}

	integers.display();
	return 0;
}
