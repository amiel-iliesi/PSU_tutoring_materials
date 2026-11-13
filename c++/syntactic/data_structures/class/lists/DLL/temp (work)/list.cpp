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

		for (Node *curr=head->next; curr; curr=curr->next) {
			cout << " <-> " << curr->data;
		}

		cout << endl;
	}
}

// returns: sum of all removed nodes
int List::remove2Largest()
{
	int largest = -1;
	int second_largest = -1;

	return remove2Largest(head, largest, second_largest);
}

int List::remove2Largest(Node* curr,
		int& largest,
		int& second_largest)
{
	// base case
	if (not curr) {
		return 0;
	}
	
	// updating largest values should be done pre-loop
	if (curr->data > largest) {
		second_largest = largest;
		largest = curr->data;
	}

	if (curr->data > second_largest and curr->data != largest) {
		second_largest = curr->data;
	}

	// head recursion
	int sum_removed = remove2Largest(curr->next,
			largest,
			second_largest);

	// function body
	if (curr->data == largest or curr->data == second_largest) {
		sum_removed += curr->data;
		remove(curr);
	}

	return sum_removed;
}


void List::remove(Node* to_remove)
{
	// no-operation
	if (not to_remove) {
		return;
	}

	// update class pointers
	if (to_remove == head) {
		head = head->next;
	}

	if (to_remove == tail) {
		tail = tail->prev;
	}

	// perform removal
	if (to_remove->prev) {
		to_remove->prev->next = to_remove->next;
	}

	if (to_remove->next) {
		to_remove->next->prev = to_remove->prev;
	}

	delete to_remove;
}
