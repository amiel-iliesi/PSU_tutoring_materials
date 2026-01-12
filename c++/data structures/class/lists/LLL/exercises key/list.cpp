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
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

void List::push(int data)
{
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = head;

	head = new_node;
}

void List::push_back(int data)
{
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = nullptr;


	if (!head) {
		head = new_node;
	}
	else {
		Node* tail = head;
		
		while (tail->next) {
			tail = tail->next;
		}

		tail->next = new_node;
	}
}

void List::display() const
{
	if (!head) {
		cout << "<List @" << this << " is empty>" << endl;
	}
	else {
		cout << head->data;

		for (Node* curr=head->next; curr; curr=curr->next) {
			cout << " -> " << curr->data;
		}

		cout << endl;
	}
}

// -EXERCISES: Easy-------------------------------------------------------------
void List::append(int x)
{
	append(head, x);
}

void List::append(Node*& curr, int x)
{
	if (!curr) {
		curr = new Node;
		curr->data = x;
		curr->next = nullptr;
	}
	else {
		append(curr->next, x);
	}
}

int List::length() const
{
	return length(head);
}

int List::length(const Node* curr) const
{
	if (!curr) {
		return 0;
	}
	else {
		return 1 + length(curr->next);
	}
}

int List::sum() const
{
	return sum(head);
}

int List::sum(const Node* curr) const
{
	if (!curr) {
		return 0;
	}
	else {
		return curr->data + sum(curr->next);
	}
}
// -----------------------------------------------------------------------------

// -EXERCISES: medium-----------------------------------------------------------
bool List::insert(int x, int pos)
{
	return insert(head, x, pos);
}

bool List::insert(Node*& curr, int x, int pos)
{
	if (!curr and pos != 0) {
		return false;
	}
	else if (pos == 0) {
		Node* new_node = new Node;
		new_node->data = x;
		new_node->next = curr;

		curr = new_node;

		return true;
	}
	else {
		return insert(curr->next, x, pos-1);
	}
}

bool List::pop(int pos)
{
	return pop(head, pos);
}

bool List::pop(Node*& curr, int pos)
{
	if (!curr) {
		return false;
	}
	else if (pos == 0) {
		Node* to_pop = curr;
		curr = curr->next;
		delete to_pop;

		return true;
	}
	else {
		return pop(curr->next, pos-1);
	}
}

void List::remove(int x, int count)
{
	remove(head, x, count);
}

void List::remove(Node*& curr, int x, int count)
{
	if (!curr or count == 0) {
		return;
	}
	else if (curr->data == x) {
		Node* to_remove = curr;
		curr = curr->next;
		delete to_remove;

		remove(curr, x, count-1);
	}
	else {
		remove(curr->next, x, count);
	}
}

List::List(const List& other)
{
	head = nullptr;
	copy(head, other.head);
}

void List::copy(Node*& curr, const Node* other_curr)
{
	if (!other_curr) {
		return;
	}
	else {
		curr = new Node;
		curr->data = other_curr->data;
		curr->next = nullptr;

		copy(curr->next, other_curr->next);
	}
}

void List::operator=(const List& other)
{
	if (this == &other) { // don't self-assign
		return;
	}
	clear(head); // this is what makes assignment different from copy
	copy(head, other.head);
}

void List::clear(Node*& curr)
{
	if (!curr) {
		return;
	}
	else {
		Node* to_delete = curr;
		curr = curr->next;
		delete to_delete;

		clear(curr);
	}
}
// -----------------------------------------------------------------------------

// -EXERCISES: Hard-------------------------------------------------------------
void List::filter_evens()
{
	filter_evens(head);
}

void List::filter_evens(Node*& curr)
{
	if (!curr) {
		return;
	}
	else {
		if (curr->data % 2 == 0) {
			Node* to_delete = curr;
			curr = curr->next;
			delete to_delete;

			filter_evens(curr);
		}
		else {
			filter_evens(curr->next);
		}
	}
}

void List::reverse()
{
	if (head) {
		reverse(head);
	}
}

void List::reverse(Node* curr)
{
	if (!curr->next) {
		head = curr;
	}
	else {
		reverse(curr->next); // tail recursion (call order is crucial)
		curr->next->next = curr; // we do work, after backtrack
		curr->next = nullptr; // cut cycle
	}
}

void List::pop_back(int n)
{
	if (n <= 0 or !head) {
		return;
	}

	int dist_from_back = -1;
	pop_back(head, n, dist_from_back);
}

void List::pop_back(Node*& curr, int n, int& dist_from_back)
{
	if (!curr->next) {
		dist_from_back = 0;
	}
	else {
		pop_back(curr->next, n, dist_from_back);
		++dist_from_back;
	}

	if (dist_from_back < n) {
		Node* to_delete = curr;
		curr = curr->next;
		delete to_delete;
	}
}
// -----------------------------------------------------------------------------

// -EXERCISES: Absurd-----------------------------------------------------------
void List::remove_if(std::function<bool(const int&)> f)
{
	remove_if(head, f);
}

void List::remove_if(Node*& curr, std::function<bool(const int&)> f)
{
	if (!curr) {
		return;
	}

	if (f(curr->data)) {
		Node* to_delete = curr;
		curr = curr->next;
		delete to_delete;

		remove_if(curr, f);
	}
	else {
		remove_if(curr->next, f);
	}
}

int List::sum_if(std::function<bool(const int&)> f) const
{
	return sum_if(head, f);
}

int List::sum_if(const Node* curr, std::function<bool(const int&)> f) const
{
	if (!curr) {
		return 0;
	}
	else if (f(curr->data)) {
		return curr->data + sum_if(curr->next, f);
	}
	else {
		return sum_if(curr->next, f);
	}
}
// -----------------------------------------------------------------------------
