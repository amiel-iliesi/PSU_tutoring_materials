#include "list.h"
#include <iostream>

using namespace std;

// -PROBLEM 1--------------------------------------------------
// Move the head node to the end of the list.

// we are going to cut head, and move it to be after tail
bool move_head_to_tail(Node*& head);

// remove the head node from the list, and return it's value
int remove_head(Node*& head);

// puts given value at the end of the list
// NOTE: recursive function, use curr instead of head
bool append(Node*& curr, int new_data); 
// ------------------------------------------------------------

// -PROBLEM 2--------------------------------------------------
// Take a LLL and insert them into an array, but only if that data item doesn’t
// already appear in the list.

// To rephrase it, in my understanding: insert all *unique* elements from the
// LLL into an array? EX: {2, 2, 3, 3, 5, 6} -> [2, 3, 5, 6]

// Takes a LLL into `head` parameter, stores all unique values into `arr_ptr`,
// and returns the size of `arr_ptr`.
int LLL_to_array_unique(const Node* head, int*& arr_ptr);

// return the size of the list
int length(const Node* curr);

// returns amount of elements inserted
int LLL_to_array_unique_r(const Node* curr, int*& arr_ptr, int arr_i);

// return true if the list contains the match
bool contains(const Node* curr, int match);
// ------------------------------------------------------------

// -PROBLEM 3--------------------------------------------------
// Remove the last node of the list, and count the remaining nodes.

// returns remaining nodes in the list after removal
int remove_last(Node*& head);

// returns remaining nodes in the list after removal
int remove_last_r(Node*& curr);
// ------------------------------------------------------------

int main()
{
	Node* head = nullptr;
	build(head);

	// -put function calls here------------------------------------
	display(head);

	// PROBLEM 1:
	{
		cout << "\nmoving head to tail...\n";
		move_head_to_tail(head);

		display(head);
	}

	// PROBLEM 2:
	{
		cout << "\nstoring unique LLL values into array...\n";

		int* unique_array = nullptr;
		int unique_array_size = LLL_to_array_unique(head, unique_array);

		cout << '[';
		if (unique_array_size >= 1) {
			cout << unique_array[0];
		}
		for (int i = 1; i < unique_array_size; ++i) {
			cout << ", " << unique_array[i];
		}
		cout << "]\n";

		delete [] unique_array;
	}

	// PROBLEM 3:
	{
		cout << "\nremoving the last node...\n";

		int remaining_nodes = remove_last(head);

		display(head);
		
		cout << "There are " << remaining_nodes << " node(s) left.\n";
	}
	// ------------------------------------------------------------

	destroy(head);

	return 0;
}

// -PROBLEM 1--------------------------------------------------
bool move_head_to_tail(Node*& head)
{
	// case: do nothing
	if (!head or !head->next) { // 0 or 1 elements: moving has no effect, so do nothing
		return false;
	}

	// above cases: asserts 2+ elements below

	int prev_head_value = remove_head(head);

	// now: do recursive part, append head value to end
	append(head, prev_head_value);

	return true;
}

int remove_head(Node*& head)
{
	// NOTE: because of assert in wrapper; head has 2+ elements for sure
	Node* temp = head;
	head = head->next;
	int temp_value = temp->data;
	delete temp;
	return temp_value;
}

bool append(Node*& curr, int new_data)
{
	// NOTE: because of assert in wrapper; curr will never be nullptr (2+ elements)
	if (!curr->next) {
		Node* temp = new Node;
		curr->next = temp;
		temp->data = new_data;
		temp->next = nullptr;
		return true;
	}
	else {
		return append(curr->next, new_data);
	}
}
// ------------------------------------------------------------

// -PROBLEM 2--------------------------------------------------
int LLL_to_array_unique(const Node* head, int*& arr_ptr)
{
	// 1. get the size of the LLL, so we can allocate the array
	int LLL_size = length(head); // get size
	arr_ptr = new int[LLL_size]; // then allocate the array

	// 2. recurse through list, adding unique values to arr_ptr
	int arr_size = LLL_to_array_unique_r(head, arr_ptr, 0);

	// 3. optional: shrink `arr_ptr` to actual content size (WE WILL NOT DO THIS)

	// 4. return amount of unique elements stored; IE array size
	return arr_size;
}

int length(const Node* curr)
{
	if (!curr) {
		return 0;
	}
	else {
		return 1 + length(curr->next);
	}
}

int LLL_to_array_unique_r(const Node* curr, int*& arr_ptr, int arr_i)
{
	// base case: end of LLL
	if (!curr) {
		return 0;
	}

	// 1. look ahead to see if the node we're looking at is unique
	bool is_unique = not contains(curr->next, curr->data);

	// 	1.a. add to array if it is, and increase the array size by 1
	if (is_unique) {
		arr_ptr[arr_i] = curr->data; // add to array
		return 1 + LLL_to_array_unique_r(curr->next, arr_ptr, arr_i + 1); // recurse
	}
	// 	1.b. skip adding the current value if it is *not* unique
	else {
		return LLL_to_array_unique_r(curr->next, arr_ptr, arr_i);
	}
}

bool contains(const Node* curr, int match)
{
	// base case: did not find
	if (!curr) {
		return false;
	}
	// base case: did find
	else if (curr->data == match) {
		return true;
	}
	// recursive case
	else {
		return contains(curr->next, match);
	}
}
// ------------------------------------------------------------

// -PROBLEM 3--------------------------------------------------
int remove_last(Node*& head)
{
	// case: empty list
	if (not head) {
		return 0;
	}

	int remaining = remove_last_r(head);

	return remaining;
}

int remove_last_r(Node*& curr)
{
	// NOTE: because of the wrapper, curr is guaranteed to exist
	
	// base case: we are last
	if (!curr->next) {
		delete curr;
		curr = nullptr;
		return 0;
	}
	else {
		return 1 + remove_last_r(curr->next);
	}
}
// ------------------------------------------------------------
