#include "list.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

/*--------------------------BASIC FUNCTIONS-----------------------------*/

void List::insert(int newData)
{
	insert(newData, head);
}

void List::insert(int newData, Uptr& current)
{
	if (!current)
		//current = new Node(newData);
		current = std::make_unique<Node>(newData);
	else
		insert(newData, current->next);
}

void List::display() const
{
	display(head.get());
	std::cout << std::endl;
}

void List::display(const Node *current) const
{
	if (!current) { return; }

	std::cout << current->data;

	if (current->next.get()) {
		std::cout << " -> ";
		display(current->next.get());
	}
}

void List::build(size_t size, const int min, const int max)
{
	std::srand(std::time(NULL));
	
	while (size--) //insert size entries of rand from [min, max] inclusive
		insert((std::rand() % ((max+1) - min)) + min);
}




/*-------------------------CUSTOM FUNCTIONS-----------------------------*/
