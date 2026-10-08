#include "list.h"
#include <iostream>

using namespace std;

List::Node::Node(int _data): data(_data), prev(nullptr)
{}

void List::insert(int _data)
{
	// case: first element
	if (not head) {
		head = std::make_unique<Node>(_data);
		return;
	}

	std::unique_ptr<Node> new_node = std::make_unique<Node>(_data);

	// case: new head
	if (_data <= head->data) {
		head->prev = new_node.get();

		new_node->next.swap(head); // new_node->next takes ownership of previous head
		head.swap(new_node); // give head pointer ownership of the new head node

		return;
	}

	// NOTE: we use std::unique_ptr.get() to access the raw pointer for traversal,
	// or weak access purposes
	Node* curr = head.get();

	while (curr->next) {
		// case: found spot in the middle of the list
		if (_data <= curr->next->data) {
			new_node->prev = curr;
			curr->next->prev = new_node.get();

			new_node->next.swap(curr->next); // new node assumes ownership of next
			curr->next.swap(new_node); // next assumes ownership of new node

			return;
		}

		curr = curr->next.get();
	}

	// case: new tail
	new_node->prev = curr;
	curr->next.swap(new_node);
}

void List::display() const
{
	if (not head) {
		std::cout << "<List @" << this << " is empty>\n";
		return;
	}

	std::cout << head->data;

	for (const Node* curr=head->next.get(); curr; curr=curr->next.get()) {
		std::cout << ", " << curr->data;
	}
	
	std::cout << '\n';
}
