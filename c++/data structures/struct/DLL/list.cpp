#include "list.h"
#include <random>
#include <iostream>

using namespace std;

// -predefined functions---------------------------------------
void build(Node*& head)
{
	if (head) {
		destroy(head);
	}

	random_device rd;

	int SIZE = 8 + rd() % 8;

	for (int i = 0; i < SIZE; ++i) {
		Node* new_node = new Node;
		new_node->data = rd() % 10;
		new_node->next = head;
		new_node->prev = nullptr;

		if (head) {
			head->prev = new_node;
		}

		head = new_node;
	}
}

void destroy(Node*& head)
{
	while (head) {
		Node* to_delete = head;
		head = head->next;
		delete to_delete;
	}
}

void display(const Node* head)
{
	if (!head) {
		cout << "list is empty" << endl;
	}
	else {
		cout << head->data;

		for (Node* curr = head->next; curr; curr = curr->next) {
			cout << " <-> " << curr->data;
		}

		cout << endl;
	}
}
// -predefined functions END-----------------------------------

// -custom implementations here--------------------------------
// ------------------------------------------------------------
