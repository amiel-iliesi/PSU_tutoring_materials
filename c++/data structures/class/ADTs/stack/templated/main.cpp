#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
	Stack<int> stack;

	cout << "pushing {0, 1, 2, 3, 4, 5}..." << endl;
	for (int n: {0, 1, 2, 3, 4, 5}) {
		stack.push(n);
	}

	cout << "peek: " << stack.peek() << endl;

	cout << "popping twice..." << endl;
	for (int i = 0; i < 2; ++i) {
		stack.pop();
	}

	cout << "peek: " << stack.peek() << endl;

	cout << "pushing: {4, 5, 6, 7, 8}..." << endl;
	for (int n: {4, 5, 6, 7, 8}) {
		stack.push(n);
	}

	cout << "peek: " << stack.peek() << endl;

	cout << "clearing stack..." << endl;
	stack.clear();

	// NOTE: this will error; cannot peek an empty stack
	// cout << "peek: " << stack.peek() << endl;

	return 0;
}
