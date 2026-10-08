#include "fraction.h"
#include <iostream>

using std::cout, std::endl;

void FractionList::insert(Node * new_fraction)
{
	if (head == nullptr) //list is currently empty
	{
		head = new_fraction;
	}
	else //list has stuff in it 
	{
		Node * tail = head;
		while (tail->next != nullptr) {
			tail = tail->next;
		}

		tail->next = new_fraction;
	}
}

FractionList::Node * FractionList::make_new_fraction(int a, int b)
{
	Node * new_fraction = new Node;

	new_fraction->data.numerator = a;
	new_fraction->data.denominator = b;
	new_fraction->next = nullptr;
	return new_fraction;
}

void FractionList::add(int inputted_numerator, int inputted_denominator)
{
	Node * temp = nullptr;
	temp = make_new_fraction(inputted_numerator, inputted_denominator);

	insert(temp);
}

void FractionList::display() const
{
	for (Node * curr = head; curr != nullptr; curr = curr->next) {
		cout << curr->data.numerator << "/" << curr->data.denominator;
		if (curr->next != nullptr) {
			cout << " -> ";
		}
	}
	cout << endl;
}
