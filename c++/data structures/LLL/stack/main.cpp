#include "list.h"
#include <iostream>

using namespace std;

int main()
{
	Stack intStack;
	for (int i: {1, 3, 5, 2, 4}) {
		intStack.push(i);
	}

	intStack.display();

	cout << "\nthe top of the stack is: " << intStack.peek() << endl;

	cout << "\npopping the first three items..." << endl;
	for (int i = 0; i < 3; ++i) {
		intStack.pop();
	}
	intStack.display();

	return 0;
}
