#include "list.h"
#include <iostream>
#include <print>

using namespace std;

List::List()
{
	head = nullptr;
	tail = nullptr;
}

List::~List()
{
	clear();
}

void List::clear()
{
	while (head) {
		Node* to_delete = head;
		head = head->next;
		delete to_delete;
	}
	tail = nullptr;
}


void List::push(int data)
{
	Node *new_node = new Node;
	new_node->data = data;
	new_node->next = head;
	new_node->prev = nullptr;

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

//-CUSTOM FUNCTIONS-----------------------------------------------------
std::size_t List::count() const
{
	return count(head);
}

std::size_t List::count(const Node* curr) const
{
	if (not curr) {
		return 0;
	}
	else {
		return 1 + count(curr->next);
	}
}


bool List::insert(size_t index, int value)
{
	if (index == 0) {
		Node* new_node = new Node;
		new_node->data = value;
		new_node->next = head;
		new_node->prev = nullptr;
		if (head) {
			head->prev = new_node;
		}

		head = new_node;

		return true;
	}
	else {
		return insert(index, value, head);
	}
}

bool List::insert(size_t index, int value, Node*& curr)
{
	if (not curr) {
		return false;
	}
	else if (index == 1) {
		Node* new_node = new Node;
		new_node->data = value;
		new_node->next = curr->next;
		new_node->prev = curr;

		curr->next = new_node;

		if (new_node->next) {
			new_node->next->prev = new_node;
		}

		if (curr == tail) {
			tail = new_node;
		}

		return true;
	}
	else {
		return insert(index-1, value, curr->next);
	}
}


size_t List::remove(int count, int value)
{
	return remove(count, value, head);
}

size_t List::remove(int count, int value, Node* curr)
{
	if (count == 0 or not curr) {
		return 0;
	}
	else if (curr->data == value) {
		Node* next = curr->next;
		remove(curr);
		return 1 + remove((count < 0 ? count : count-1), value, next);
	}
	else {
		return remove(count, value, curr->next);
	}
}

void List::remove(Node*& to_remove)
{
	if (not to_remove) {
		return;
	}

	// 1. adjust surrounding adjacent pointers

	// 1.a. prev
	if (to_remove->prev) {
		to_remove->prev->next = to_remove->next;
	}
	else {
		head = to_remove->next;
	}

	// 1.b. next
	if (to_remove->next) {
		to_remove->next->prev = to_remove->prev;
	}
	else {
		tail = to_remove->prev;
	}
	
	// 2. delete the pointer
	to_remove->next = nullptr;
	to_remove->prev = nullptr;
	delete to_remove;
	to_remove = nullptr;
}

List::List(const List& other)
{
	head = nullptr;
	tail = nullptr;

	copy(head, other.head);
}

void List::operator=(const List& other)
{
	if (this == &other) {
		return;
	}

	clear();
	copy(head, other.head);
}

void List::copy(Node*& dst, const Node* src)
{
	if (src) {
		dst = new Node;
		dst->data = src->data;
		dst->next = nullptr;
		dst->prev = nullptr;

		copy(dst->next, src->next);

		if (not dst->next) {
			tail = dst;
		}
	}
}

size_t List::remove_evens()
{
	return remove_evens(head);
}

size_t List::remove_evens(Node* curr)
{
	if (not curr) {
		return 0;
	}
	else if (curr->data % 2 == 0) {
		Node* next = curr->next;
		remove(curr);
		return 1 + remove_evens(next);
	}
	else {
		return remove_evens(curr->next);
	}
}

size_t List::remove_if(std::function<bool(const int&)> filter)
{
	return remove_if(filter, head);

}

size_t List::remove_if(std::function<bool(const int&)> filter, Node* curr)
{
	if (not curr) {
		return 0;
	}
	else if (filter(curr->data)) {
		Node* next = curr->next;
		remove(curr);
		return 1 + remove_if(filter, next);
	}
	else {
		return remove_if(filter, curr->next);
	}
}

void List::reverse()
{
	if (not head) {
		return;
	}

	reverse(head);
	std::swap(head, tail);
}

void List::reverse(Node* curr)
{
	if (not curr) {
		return;
	}

	Node* next = curr->next; // so we don't lose track; technically un-needed

	std::swap(curr->prev, curr->next);

	reverse(next);
}
