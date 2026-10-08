#include <iostream>
#include "stack.h"

using namespace std;

void Stack::push(string data)
{
	stack_vector.push_back(data);
}

bool Stack::pop()
{
	if (stack_vector.empty()) {
		return false;
	}

	stack_vector.resize(stack_vector.size() - 1);

	return true;
}

optional<string> Stack::peek() const
{
	if (stack_vector.empty()) {
		return nullopt;
	}
	else {
		return stack_vector.back();
	}
}

void Stack::display() const
{
	cout << stack_vector.back();
	for (auto rit = stack_vector.rbegin() + 1;
		 rit != stack_vector.rend();
		 ++rit)
	{
		cout << ", " << *rit;
	}
}
