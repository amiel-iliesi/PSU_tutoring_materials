#include "list.h"
#include <iostream>

using namespace std;

List::List()
{
	rear = nullptr;
}

List::~List()
{
	if (!rear) {
		return;
	}

	Node *head = rear->next;
	rear->next = nullptr;
	
	while (head) {
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	rear = nullptr;
}


void List::push(int data)
{
	Node *new_node = new Node;
	new_node->data = data;
	new_node->next = nullptr;

	if (!rear) {
		rear = new_node;
		rear->next = rear;
	}
	else {
		new_node->next = rear->next;
		rear->next = new_node;
	}
}

void List::push_back(int data)
{
	push(data);
	rear = rear->next; //rotate
}

void List::display() const
{
	if (!rear) {
		cout << "<List @" << this << " is empty>" << endl;
	}
	else {
		for (Node *curr=rear->next; curr != rear; curr=curr->next) {
			cout << curr->data << " -> ";
		}

		cout << rear->data << " -> ..." << endl;
	}
}

