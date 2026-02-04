#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
	Stack stack;

	for (const string name: {"John", "James", "Candice", "George", "Alexi", "Vinny"}) {
		cout << "> pushing: " << name << '\n';
		stack.push(name);
	}

	cout << "\nstack contents:\n";
	stack.display();

	cout << "\npopping twice...\n";
	stack.pop();
	stack.pop();

	if (auto top_name = stack.peek()) {
		cout << "\ntop name in stack = " << *top_name << '\n';
	}

	return 0;
}
