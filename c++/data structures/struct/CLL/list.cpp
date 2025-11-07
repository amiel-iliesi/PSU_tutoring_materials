#include "list.h"
#include <random>
#include <iostream>

using namespace std;

// -predefined functions---------------------------------------
void build(Node*& rear)
{
	if (rear) {
		destroy(rear);
	}

	random_device rd;

	int SIZE = 8 + rd() % 8;

	rear = new Node;
	rear->data = rd() % 10;
	rear->next = rear;

	for (int i = 1; i < SIZE; ++i) {
		Node* new_node = new Node;
		new_node->data = rd() % 10;
		new_node->next = rear->next;
		rear->next = new_node;
	}
}

void destroy(Node*& rear)
{
	Node* head = rear->next;
	rear->next = nullptr;

	while (head) {
		Node* to_delete = head;
		head = head->next;
		delete to_delete;
	}

	rear = nullptr;
}

void display(const Node* rear)
{
	if (!rear) {
		cout << "list is empty" << endl;
	}
	else {
		for (Node* curr = rear->next; curr != rear; curr = curr->next) {
			cout << curr->data << " -> ";
		}

		cout << rear->data << " -> ..." <<  endl;
	}
}
// -predefined functions END-----------------------------------

// -custom implementations here--------------------------------
// ------------------------------------------------------------
