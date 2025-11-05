#include "list.h"
#include <iostream>

using namespace std;

List::List()
{
	head = nullptr;
}

List::~List()
{
	while (head) {
		Node *temp = head;
		head = head->next;
		delete temp;
	}
}


void List::push(int data)
{
	Node *new_node = new Node;
	new_node->data = data;
	new_node->next = head;

	head = new_node;
}

void List::push_back(int data)
{
	Node *new_node = new Node;
	new_node->data = data;
	new_node->next = nullptr;

	if (head) {
		Node *tail = head;
		
		while (tail->next) {
			tail = tail->next;
		}

		tail->next = new_node;
	}
	else {
		head = new_node;
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
			cout << " -> " << curr->data;
		}

		cout << endl;
	}
}

