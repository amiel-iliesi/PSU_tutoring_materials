#include "stack.h"
#include <iostream>
#include <cstdlib> // for rand, srand
#include <ctime> // for time to use with srand

using namespace std;

int main()
{
	const int ARR_SIZE = 3;
	Stack my_stack(ARR_SIZE);
	
	srand(time(NULL));
	
	//---push demo------------------------------------
	const int ORIGINAL_SIZE = (rand() % 10) + 1;
	
	cout << "added " << ORIGINAL_SIZE << (ORIGINAL_SIZE == 1 ? " item" : " items")
		 << " to the stack:" << endl;
	
	for (int i = 0; i < ORIGINAL_SIZE; ++i){
		my_stack.push(rand() % 10);
	}
	
	my_stack.display();

	//---pop demo------------------------------------
	const int COUNT_TO_POP = (rand() % ORIGINAL_SIZE) + 1;

	cout << "\npopping " << COUNT_TO_POP << ' '
		 << (COUNT_TO_POP == 1 ? "item" : "items") << "..." << endl;

	for (int i = 0; i < COUNT_TO_POP; ++i) {
		my_stack.pop();
	}

	my_stack.display();

	//---peek demo------------------------------------
	cout << "\nadding another item to stack..." << endl;
	
	my_stack.push(rand() % 10);
	
	cout << "it was a " << my_stack.peek() << ", take a look:" << endl;
	
	my_stack.display();

	return 0;
}
