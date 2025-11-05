#include "list.h"
#include <iostream>

using namespace std;

List::List()
{
	head = nullptr;
	tail = nullptr;
}

List::~List()
{
	while (head) {
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	tail = nullptr;
}


void List::push(int data)
{
	Node *new_node = new Node;
	new_node->data = data;
	new_node->next = head;

	if (head) {
		head->prev = new_node;
	}
	head = new_node;

	if (!tail) {
		tail = head;
	}
}

void List::push_back(int data)
{
	Node *new_node = new Node;
	new_node->data = data;
	new_node->next = nullptr;
	new_node->prev = tail;

	if (tail) {
		tail->next = new_node;
		tail = new_node;
	}
	else {
		head = tail = new_node;
	}
}

void List::display() const
{
	if (!head) {
		cout << "<List @" << this << " is empty>" << endl;
	}
	else {
		cout << head->data;

		for (Node *curr=head; curr; curr=curr->next) {
			cout << " <-> " << curr->data;
		}

		cout << endl;
	}
}

