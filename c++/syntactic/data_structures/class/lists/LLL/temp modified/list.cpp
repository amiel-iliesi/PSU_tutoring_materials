#include "list.h"
#include <iostream>
#include <print>

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

		for (Node *curr=head->next; curr; curr=curr->next) {
			cout << " -> " << curr->data;
		}

		cout << endl;
	}
}

void List::displayRecWrapper() const
{
	displayRecHelper(head);

	print("\n");
}

void List::displayRecHelper(const Node* curr) const
{
	// base case
	if (not curr) {
		return;
	}
	
	// calling recursion before function behavior is tail-recursion, it prints 
	// backwards as a result
	
	// recurisve case
	displayRecHelper(curr->next);

	// function behavior
	print("{} ", curr->data);
}

void List::removeMatchLastWrapper()
{
	int last;
	removeMatchLastHelper(head, last);
}

/* STUDY POINTS:
 * head recursion vs tail recursion
 */
void List::removeMatchLastHelper(Node*& curr, int& last_value)
{
	// base case
	if (not curr) {
		return;
	}

	// found last value, lets set it so all the other function calls can use
	if (not curr->next) {
		last_value = curr->data;
	}

	// tail recursion, find the end--first
	removeMatchLastHelper(curr->next, last_value);

	// now perform function behavior
	if (curr->data == last_value) {
		Node* next = curr->next;
		delete curr;
		curr = next;
	}
}
