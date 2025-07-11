#include "list.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

/*--------------------------BASIC FUNCTIONS-----------------------------*/
List::~List()
{
	while (head)
	{
		Node * toDelete = head;
		head = head->next;
		delete toDelete;
	}
}

void List::insert(int newData)
{
	insert(newData, head);
}

void List::insert(int newData, Node *&current)
{
	if (!current) {
		current = new Node(newData);
	}
	else {
		insert(newData, current->next);
	}
}

void List::display() const
{
	display(head);
	std::cout << std::endl;
}

void List::display(const Node *current) const
{
	if (!current) { return; }

	std::cout << current->data;

	if (current->next) {
		std::cout << " -> ";
		display(current->next);
	}
}

bool List::remove(size_t index)
{
	return remove(index, head);
}

bool List::remove(size_t index, Node *&current)
{
	if (!current) {
		return false;
	}

	if (index == 0) {
		Node * toDelete = current;
		current = current->next;
		delete toDelete;
		return true;
	}
	else {
		return remove(--index, current->next);
	}
}

int List::get(size_t index) const
{
	return get(index, head);
}

int List::get(size_t index, const Node *current) const
{
	if (!current) { return 0; } //XXX 0 is used as failure case

	if (index == 0) {
		return current->data;
	}
	else {
		return get(--index, current->next);
	}
}

size_t List::size() const
{
	return size(head);
}

size_t List::size(const Node * current) const
{
	if (!current) { return 0; }

	return 1 + size(current->next);
}

void List::build(size_t size, const int min, const int max)
{
	std::srand(std::time(NULL));
	
	while (size--) //insert size entries of rand from [min, max] inclusive
		insert((std::rand() % ((max+1) - min)) + min);
}




/*-------------------------CUSTOM FUNCTIONS-----------------------------*/
void List::insert_ascending(int new_data)
{
	insert_ascending(new_data, head);
}


void List::insert_ascending(int new_data, Node*& current_node)
{
	// end of list
	if (!current_node) {
		// SAME AS:
		// current->node = new Node();
		// current->data = new_data;
		// current->next = nullptr;
		current_node = new Node(new_data);
	}

	// we're somewhere in the middle of the list
	else {
		// we found our match
		if (current_node->data >= new_data) {
			Node * old_next = current_node; // saved!
			current_node = new Node(new_data);
			current_node->next = old_next;
		}
		// no match... just keep iterating
		else {
			insert_ascending(new_data, current_node->next);
		}
	}
}


int List::count_first() const
{
	return count_match(head->data, head);
}

int List::count_match(int match, const Node * current) const
{
	if (not current) { return 0; }

	if (current->data == match) {
		return 1 + count_match(match, current->next);
	}
	else {
		return count_match(match, current->next);
	}
}

int List::count_primes() const
{
	int count = 0;
	Node * current = head;
	while (current) {
		if (is_prime(current)) {
			++count;
		}

		current = current->next;
	}

	return count;
}

int List::count_composites() const
{
	int count = 0;
	Node * current = head;
	while (current) {
		if (not is_prime(current)) {
			++count;
		}

		current = current->next;
	}

	return count;
}

bool List::is_prime(Node * current) const
{
	int num = current->data;

	for (int i = 2; i < num; ++i) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

void List::swap_head_tail()
{
	if (!head or !head->next) {
		return;
	}

	swap_head_tail(head->next);
}

void List::swap_head_tail(Node *& curr)
{
	if (!curr->next) {
		//1: swap node bodies
		Node * tail = curr; //tail is the temp for the swap
		curr = head;
		head = tail;

		//2: swap their next pointers back
		head->next = curr->next;
		curr->next = nullptr;
	}
	else {
		swap_head_tail(curr->next);
	}
}

int List::count_greater_than_tail() const
{
	if (!head or !head->next) {
		return 0;
	}

	int last;
	return count_greater_than_tail(head, last);
}

int List::count_greater_than_tail(Node * curr, int & last_value) const
{
	if (!curr->next) {
		last_value = curr->data;
		return 0;
	}
	else {
		int counts_after_curr = count_greater_than_tail(curr->next, last_value);

		if (curr->data > last_value) {
			return counts_after_curr + 1;
		}
		else {
			return counts_after_curr;
		}
	}
}

int List::remove_all_after_last_2()
{
	bool found_a_2_behind = false;
	return remove_all_after_last_2(head, found_a_2_behind);
}

int List::remove_all_after_last_2(Node *& curr, bool & found_a_2_behind)
{
	/*
	f2   f   f   t   t   t   t   t
		 1 - 4 - 2 - 3 - 2 - 1 - 4
	f2   f   f   f   f   f   t   t
	*/

	if (!curr) { return 0; }

	int removed = 0;

	if (curr->data == 2) {
		found_a_2_behind = true; // mark all after 2 true, on the way up
		removed = remove_all_after_last_2(curr->next, found_a_2_behind);
		found_a_2_behind = false; // mark all before 2 false, on the way down
	}
	else {
		removed = remove_all_after_last_2(curr->next, found_a_2_behind);
		if (found_a_2_behind) {
			Node * to_delete = curr;
			curr = curr->next;
			delete to_delete;
			++removed;
		}
	}

	return removed;
}

int List::remove_last_2()
{
	bool found_a_2_ahead = false;
	return remove_last_2(head, found_a_2_ahead);
}

int List::remove_last_2(Node *& curr, bool & found_a_2_ahead)
{
	/*
	f2   f   f   t   t   t   t   t
		 1 - 4 - 2 - 3 - 2 - 1 - 4
	f2   f   f   f   f   f   t   t
	*/

	if (!curr) { return 0; }

	int count_of_2 = 0;

	if (curr->data == 2) {
		found_a_2_ahead = true; // mark all after 2 true, on the way up
		count_of_2 = remove_last_2(curr->next, found_a_2_ahead);

		if (found_a_2_ahead) { // we are at the last 2
			Node * to_delete = curr;
			curr = curr->next;
			delete to_delete;
		}
		else{ //another 2 ahead marked as false on the way back
			++count_of_2;
		}

		found_a_2_ahead = false; // mark all before 2 false, on the way down
	}
	else {
		count_of_2 = remove_last_2(curr->next, found_a_2_ahead);
	}

	return count_of_2;
}
