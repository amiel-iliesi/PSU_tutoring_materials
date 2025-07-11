#include "list.h"
#include <iostream>
#include <vector>
#include <ctime> //time function; helps initialize srand
#include <cstdlib> //rand, and srand

using std::vector;

List::List(): head(nullptr), tail(nullptr) 
{
	std::srand(std::time(NULL));
}

List::~List()
{
	clear();
}

void List::clear()
{
	if (head) {
		Node * temp = head;
		head = head->next;
		delete temp;

		clear();
	}
	else {
		tail = nullptr;
	}
}

void List::insert_after(Node *& curr, int d)
{
	if (!curr) { return; }

	curr->next = new Node(d, curr, curr->next);
	curr = curr->next;

	if (curr->next) {
		curr->next->prev = curr;
	}

	if (curr->prev == tail) {
		tail = curr;
	}
}

void List::insert_before(Node *& curr, int d)
{
	if (!curr) { return; }

	curr->prev = new Node(d, curr->prev, curr);
	curr = curr->prev;

	if (curr->prev) {
		curr->prev->next = curr;
	}

	if (curr->next == head) {
		head = curr;
	}
}

bool List::insert(int pos, int d)
{
	if (pos >= 0) {
		return insert_forward(head, (size_t)pos, d);
	}
	else {
		return insert_backward(tail, (size_t)((-pos)-1), d);
	}
}

bool List::insert_forward(Node *& curr, size_t pos, int d)
{
	if (!curr) { return false; }

	if (pos == 0) {
		insert_before(curr, d);
		return true;
	}
	else if (pos == 1 and not curr->next) {
		insert_after(curr, d);
		return true;
	}
	else {
		return insert_forward(curr->next, pos-1, d);
	}
}

bool List::insert_backward(Node *& curr, size_t pos, int d)
{
	if (!curr) { return false; }

	if (pos == 0) {
		insert_after(curr, d);
		return true;
	}
	else if (pos == 1 and not curr->prev) {
		insert_before(curr, d);
		return true;
	}
	else {
		return insert_forward(curr->prev, pos-1, d);
	}
}

void List::append(int d)
{
	if (!tail) {
		tail = head = new Node(d);
	}
	else {
		insert_after(tail, d);
	}
}

void List::push(int d)
{
	if (!head) {
		head = tail = new Node(d);
	}
	else {
		insert_before(head, d);
	}
}

void List::display() const
{
	if (head) {
		display(head);
		std::cout << std::endl;
	}
}

void List::display(const Node * curr) const
{
	std::cout << curr->data;
	if (curr->next) {
		std::cout << " <-> ";
		display(curr->next);
	}
}

void List::remove_all_evens()
{
	remove_all_evens(head);
}

void List::remove_all_evens(Node * curr)
{
	if (!curr) { return; }

	if (curr->data % 2 == 0) {
		remove_node(curr);
	}

	remove_all_evens(curr->next);
}

void List::remove_node(Node *& to_delete)
{
	if (!to_delete) { return; }

	Node * saved_next = to_delete->next;

	if (to_delete == head) {
		head = head->next;
	}

	if (to_delete == tail) {
		tail = tail->prev;
	}

	if (to_delete->next) {
		to_delete->next->prev = to_delete->prev;
	}

	if (to_delete->prev) {
		to_delete->prev->next = to_delete->next;
	}

	delete to_delete;

	//for convention, after deleting, the next
	//value is stored into the deleted node
	to_delete = saved_next;
}

int List::size() const
{
	return size(head);
}

int List::size(const Node * curr) const
{
	if (!curr) { return 0; }

	return 1 + size(curr->next);
}

void List::shuffle()
{
	int dll_size = size();
	if (dll_size <= 1) { return; }

	//this will be used to make a permutation set for us
	vector<int> random_indecies(dll_size);
	for (int i = 0; i < dll_size; ++i) {
		random_indecies[i] = i;
	}

	//this will be our permutation vector
	vector<int> new_indecies(dll_size);
	for (int i = 0; i < dll_size; ++i) {
		int j = rand() % dll_size;
		while (random_indecies[j] == -1) {
			++j;
			j %= dll_size;
		}
		new_indecies[i] = random_indecies[j];
		random_indecies[j] = -1;
	}

	//this will hold the nodes so they don't break when we move around pointers
	vector<Node *> new_positions(dll_size);
	{
		int i = 0;
		Node * curr = head;
		while (curr) {
			for (int j = 0; j < dll_size; ++j) {
				if (new_indecies[j] == i) {
					new_positions[j] = curr;
				}
			}
			++i;
			curr = curr->next;
		}
	}

	// -------------- NOW: we reassign the pointer linkages -------------

	//relink up new head
	new_positions[0]->prev = nullptr;
	new_positions[0]->next = new_positions[1];
	head = new_positions[0];

	//relink all middle nodes
	for (int i = 1; i < (dll_size-1); ++i) {
		new_positions[i]->prev = new_positions[i-1];
		new_positions[i]->next = new_positions[i+1];
	}

	//relink up new tail
	new_positions[dll_size-1]->prev = new_positions[dll_size-2];
	new_positions[dll_size-1]->next = nullptr;
	tail = new_positions[dll_size-1];
}


// CUSTOM USER FUNCTIONS------------------------------
int List::copy_except_largest(const List & other)
{
	// 1. find max value
	int value_to_ignore = other.max();

	// 2. clear out this current list
	clear();

	// 3. copy the list except for the match
	copy_except_match(this->head, other.head, value_to_ignore);
	head->prev = nullptr; // from r-function: @2.; we didn't set head->prev

	// 4. return the max value
	return max_value;
}

// recursive call
void List::copy_except_match(Node *& dest, const Node * src, int match)
{
	// 0. base case: no more list to copy from
	if (!src) { return; }

	// 1. when should we copy?
	if (src->data != match) { // yes, copy the current src node
		dest = new Node;
		dest->data = src->data;
		copy_except_match(dest->next, src->next, match);
	}
	else { // no, we skip the current node
		copy_except_match(dest, src->next, match);
	}

	// 2. set the previous values
	if (dest->next) {
		dest->next->prev = dest;
	}
}

int List::max() const
{
	return max(head);
}

int List::max(const Node * curr) const
{
	// base cases
	if (!curr) { return 0; }
	if (!curr->next) { return curr->data; }

	int next_max = max(curr->next);
	return (next_max > curr->data ? next_max : curr->data);
}
