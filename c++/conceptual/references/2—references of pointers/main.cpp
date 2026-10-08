#include "linkedlist.h"
#include <iostream>

int main()
{
	List integers;
	
	for (int num: {1,2,3,4,5,6,7,8,9})
	{
		integers.push_back(num);
	}

	integers.display();

	// you can test function(s) here:

	/*
	integers.remove_first_even();
	integers.display();
	*/

	return 0;
}
