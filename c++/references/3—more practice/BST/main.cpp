#include "BST.h"
#include <iostream>
#include <climits>

using std::cout, std::endl;

int main()
{
	Tree integers;

	// I made a function you can use to build random trees; use it if you'd like to
	/*
	const int MIN = 0;
	const int MAX = 10;
	const int AMOUNT = 10;
	integers.build(MIN, MAX, AMOUNT);
	*/

	for (int i: {4,2,6,1,3,5,7})
		integers.insert(i);

	integers.display();

	return 0;
}
