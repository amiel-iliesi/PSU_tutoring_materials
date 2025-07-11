#include "redblack.h"

#include <iostream>

using namespace std;

int main()
{
	Tree ints;

	for (int & i: {10,9,8,4,5,2,6,7,3,1}) {
		ints.insert(i);
	}

	ints.display_tree();

	return 0;
}
