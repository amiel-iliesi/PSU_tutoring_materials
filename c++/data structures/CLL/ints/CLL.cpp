#include "CLL.h"
#include <iostream>

using std::cout, std::endl;

// [DE]CONSTRUCTORS
CLL::~CLL()
{
	clear();
}

CLL::CLL(const CLL & other)
{
	rear = nullptr;
	copy(other);
}

void CLL::copy(const CLL & other)
{
	if (rear) { clear(); }

	if (!other.rear) { return; }
	
	copy(other.rear, other.rear->next);
}

void CLL::copy(const Node * rear, const Node * current)
{
	Node * new_node = new Node(current->data);
	if (!this->rear) {
		new_node->next = new_node;
		this->rear = new_node;
	}
	else {
		new_node->next = this->rear->next;
		this->rear->next = new_node;
		this->rear = this->rear->next;
	}

	if (current != rear) {
		copy(rear, current->next);
	}
}

// HELPER FUNCTIONS
void CLL::clear()
{
	if (!rear) { return; }

	clear(rear);
}

void CLL::clear(Node*& curr)
{
	if (curr->next != rear) { // continue recursion if we're not at the end
		clear(curr->next);
	}

	delete curr;
	curr = nullptr;
}

void CLL::insert(int _data, size_t index)
{
	if (!rear) {
		rear = new Node(_data);
		rear->next = rear;
	}
	else {
		insert(_data, index, rear->next);
	}
}

void CLL::insert(int _data, size_t index, Node*& curr)
{
	// base case 1: insert after rear (this becomes the new rear)
	if ((index == 1) and (curr == rear))
	{
		rear->next = new Node(_data, rear->next);
		rear = rear->next;
	}
	// base case 2: insert before the rear
	else if (index == 0) {
		curr = new Node(_data, curr);
	}

	// recursive case
	else {
		insert(_data, index-1, curr->next);
	}
}

void CLL::display_backwards() const
{
	display_backwards(rear->next);
	cout << "->..." << endl;
}

void CLL::display_backwards(const Node* const & curr) const
{
	if (curr != rear) {
		display_backwards(curr->next);
		cout << "->";
	}
	cout << curr->data;
}

void CLL::display() const
{
	display(rear->next);
	cout << "->..." << endl;
}

void CLL::display(const Node* const & curr) const
{
    if (!curr) {
        return;
    }

	cout << curr->data;

	if (curr != rear) {
		cout << "->";
		display(curr->next);
	}
}

size_t CLL::size() const
{
	if (!rear) { return 0u; }

	return size(rear->next);
}

size_t CLL::size(const Node* const & curr) const
{
	if (curr == rear) {
		return 1;
	}
	else {
		return 1 + size(curr->next);
	}
}

// --------------------------------------------------
// - CUSTOM FUNCTIONS -------------------------------
// --------------------------------------------------

int CLL::sum_of_even_indecies() const
{
	if (!rear) { return 0; }

	return sum_of_even_indecies(rear->next, 0);
}

int CLL::sum_of_even_indecies(const Node * curr, int index) const
{
	// do our calculations
	int sum = 0;
	if (index % 2 == 0) {
		sum = curr->data;
	}

	// conditionally do our recursion
	if (curr == rear) { // don't loop if we are at the end
		return sum;
	}
	else { // otherwise, we *can* loop
		return sum + sum_of_even_indecies(curr->next, index+1);
	}
}



void CLL::copy_except(const CLL & other, int match)
{
	clear();

	copy_except(other.rear->next, other.rear, match);
}

void CLL::copy_except(const Node * other_curr, const Node * other_rear, int match)
{
	// 1. copy (if we can)
	if (other_curr->data != match) { // we are allowed to copy!
		if (!rear) { // we're inserting our first element
			rear = new Node;
			rear->data = other_curr->data;
			rear->next = rear;
		}
		else { // we have 1+ elements already
			Node * beginning = rear->next;
			rear->next = new Node;
			rear = rear->next;
			rear->data = other_curr->data;
			rear->next = beginning;
		}
	}

	// 2. loop (if we can)
	if (other_curr != other_rear) {
		copy_except(other_curr->next, other_rear, match);
	}
}
