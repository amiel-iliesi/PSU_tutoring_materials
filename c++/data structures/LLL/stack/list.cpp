#include "list.h"
#include <iostream>

/*--------------------------BASIC FUNCTIONS-----------------------------*/
Stack::~Stack()
{
	while (head)
	{
		Node * toDelete = head;
		head = head->next;
		delete toDelete;
	}
}

void Stack::display() const
{
	display(head);
	std::cout << std::endl;
}

void Stack::display(const Node *current) const
{
	if (!current) { return; }

	std::cout << current->data;

	if (current->next) {
		std::cout << " -> ";
		display(current->next);
	}
}

size_t Stack::size() const
{
	return size(head);
}

size_t Stack::size(const Node * current) const
{
	if (!current) { return 0; }

	return 1 + size(current->next);
}



/*-------------------------CUSTOM FUNCTIONS-----------------------------*/
void Stack::push(int d)
{
	Node * new_node = new Node(d);
	new_node->next = head;
	head = new_node;
}

void Stack::pop()
{
	if (!head) { return; }

	Node * to_delete = head;
	head = head->next;
	delete to_delete;
}

int Stack::peek() const
{
	if (head) {
		return head->data;
	}
	else {
		return 0;
	}
}
