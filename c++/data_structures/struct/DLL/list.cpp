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
bool swap(Node* A, Node* B, Node*& head)
{
	// don't self-swap
	if (A == B) {
		return false;
	}
	// need two nodes
	else if (not A or not B) {
		return false;
	}

	Node* AP = A->prev;
	Node* AN = A->next;
	Node* BP = B->prev;
	Node* BN = B->next;

	// *from* our pointers
	A->prev = BP;
	A->next = BN;
	B->prev = AP;
	B->next = AN;

	// *to* our pointers
	if (AP) {
		AP->next = B;
	}
	if (AN) {
		AN->prev = B;
	}
	if (BP) {
		BP->next = A;
	}
	if (BN) {
		BN->prev = A;
	}

	// reassign head, if we swapped it
	if (not A->prev) {
		head = A;
	}
	if (not B->prev) {
		head = B;
	}

	return true;
}
// ------------------------------------------------------------
