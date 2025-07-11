#include "linkedlist.h"
#include <iostream>

//----------------------------CONSTRUCTOR FUNCTIONS-----------------------------
List::~List()
{
	while (head)
	{
		Node * to_delete = head;
		head = head->next;
		delete to_delete;
	}
}




//----------------------------PRE-IMPLEMENTED FUNCTIONS-------------------------
void List::push_back(int new_value)
{
	push_back(head, new_value);
}

void List::push_back(Node *& curr, int new_value)
{
	if (!curr) //we're at the end
	{
		curr = new Node(new_value); //see how nice struct constructors are :)
	}
	else
	{
		push_back(curr->next, new_value);
	}
}


void List::display() const
{
	for (const Node * current = head; current; current = current->next)
	{
		std::cout << current->data;

		if (current->next) //if there's another one after, put a delimiter
		{
			std::cout << " -> ";
		}
	}
	
	std::cout << std::endl;
}



//---------------------------ADDITIONAL FUNCTIONS HERE--------------------------
