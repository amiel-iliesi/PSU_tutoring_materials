#include "linkedlist.h"

bool List::remove_first_even() //wrapper
{
	return remove_first_even(head);
}

bool List::remove_first_even(Node * & current)
{
	if (!current) { return false; } // base case: end of list, no evens found

	if (current->data % 2 == 0) // base case: the value is even, time to remove!
	{
		Node * to_delete = current;
		current = current->next;
		delete to_delete;
		
		return true;
	}
	else // no match, continue searching
	{
		return remove_first_even(current->next);
	}
}
