#include "stack.h"
#include <cstring>
#include <iostream>

using namespace std;

// ------------------------------------------------------------
// - NODE CLASS IMPLEMENTATIONS -------------------------------
// ------------------------------------------------------------
Node::Node()
{
	for (int i = 0; i < NODE_ARR_SIZE; ++i) {
		stack[i] = nullptr;
	}

	top = 0;
	next = nullptr;
}

Node::~Node()
{
	while (top != 0) {
		delete [] stack[--top];
	}
}

bool Node::push(const char * c)
{
	// if they try to add when it's full
	if (top == NODE_ARR_SIZE)
	{
		return false;
	}

	stack[top] = new char[strlen(c) + 1];
	strcpy(stack[top], c);

	++top;

	return true;
}

bool Node::pop()
{
	if (top == 0) {
		return false;
	}

	--top;

	delete [] stack[top];
	stack[top] = nullptr;

	return true;
}

bool Node::peek(char * str) const
{
	if (is_empty()) { return false; }

	strcpy(str, stack[top-1]);

	return true;
}

bool Node::is_empty() const
{
	return top == 0;
}

bool Node::is_full() const
{
	return top == NODE_ARR_SIZE;
}

void Node::set_next(Node * next)
{
	this->next = next;
}

Node * Node::get_next()
{
	return next;
}

bool Node::display_top() const
{
	if (is_empty()) { return false; }
	
	cout << stack[top-1];
	
	return true;
}



// ------------------------------------------------------------
// - STACK CLASS IMPLEMENTATIONS ------------------------------
// ------------------------------------------------------------
Stack::Stack()
{
	top = nullptr;
}

Stack::~Stack()
{
	while (top) {
		Node * prev = top;
		top = top->get_next();
		delete prev;
	}
}

void Stack::push(const char * str)
{
	// make more room
	if (!top) {
		top = new Node;
	}
	else if (top->is_full())
	{
		Node * prev_top = top;
		top = new Node;
		top->set_next(prev_top);
	}
	
	// push
	top->push(str);
}

bool Stack::pop()
{
	if (is_empty()) { return false; }

	top->pop();

	if (top->is_empty()) {
		Node * prev_top = top;
		top = top->get_next();
		delete prev_top;
	}

	return true;
}

bool Stack::peek(char * str) const
{
	if (is_empty()) { return false; }

	top->peek(str);

	return true;
}

bool Stack::is_empty() const
{
	return !top;
}
