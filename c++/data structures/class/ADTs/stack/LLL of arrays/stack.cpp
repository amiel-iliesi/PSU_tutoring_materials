#include <iostream>
#include "stack.h"

using namespace std;

Stack::Node::Node(size_t ARR_SIZE):
	data(nullptr),
	next(nullptr)
{
	data = new string[ARR_SIZE];
}

Stack::Node::~Node()
{
	delete [] data;
}

Stack::Stack(size_t _ARR_SIZE):
	top(nullptr),
	top_index(0),
	ARR_SIZE(_ARR_SIZE)
{}

Stack::~Stack()
{
	while(top) {
		Node* to_delete = top;
		top = top->next;
		delete to_delete;
	}
}

void Stack::push(string data)
{
	// position top
	if (!top or (top_index == ARR_SIZE-1)) {
		Node* new_top = new Node(ARR_SIZE);
		new_top->next = top;
		top = new_top;
		top_index = 0;
	}
	else {
		++top_index;
	}
	
	// perform push
	top->data[top_index] = data;
}

bool Stack::pop()
{
	if (!top) {
		return false;
	}
	else if (top_index == 0) {
		Node* to_delete = top;
		top = top->next;
		delete to_delete;

		top_index = ARR_SIZE-1;
	}
	else {
		--top_index;
	}

	return true;
}

optional<string> Stack::peek() const
{
	if (top) {
		return top->data[top_index];
	}
	else {
		return nullopt;
	}
}

void Stack::display() const
{
	if (!top) {
		return;
	}

	cout << top->data[0];
	for (int i = top_index; i >= 1; --i) {
		cout << ", " << top->data[i];
	}
	for (Node* curr = top->next; curr; curr = curr->next) {
		for (int i = ARR_SIZE-1; i >= 0; --i) {
			cout << ", " << curr->data[i];
		}
	}
	cout << '\n';
}
