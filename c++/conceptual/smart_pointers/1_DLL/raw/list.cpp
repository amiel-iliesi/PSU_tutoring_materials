#include "list.h"
#include <iostream>

using namespace std;

List::Node::Node(int _data): data(_data), next(nullptr), prev(nullptr)
{}

List::List(): head(nullptr)
{}

List::~List()
{
	while (head) {
		Node* to_delete = head;
		head = head->next;
		delete to_delete;
	}
}

void List::insert(int _data)
{
	// case: first element
	if (not head) {
		head = new Node(_data);
		return;
	}

	Node* new_node = new Node(_data);

	// case: new head
	if (_data <= head->data) {
		new_node->next = head;
		head->prev = new_node;
		head = new_node;

		return;
	}

	Node* curr = head;

	while (curr->next) {
		// case: found spot in the middle of the list
		if (_data <= curr->next->data) {
			new_node->next = curr->next;
			new_node->prev = curr;

			curr->next->prev = new_node;
			curr->next = new_node;
			return;
		}

		curr = curr->next;
	}

	// case: new tail
	curr->next = new_node;
	new_node->prev = curr;
}

void List::display() const
{
	if (not head) {
		std::cout << "<List @" << this << " is empty>\n";
		return;
	}

	std::cout << head->data;

	for (const Node* curr=head->next; curr; curr=curr->next) {
		std::cout << ", " << curr->data;
	}
	
	std::cout << '\n';
}
