#include "list.h"
#include <iostream>

using namespace std;

// ----------------------------------------------------------------------
// - CarNode IMPLEMENTATIONS --------------------------------------------
// ----------------------------------------------------------------------

CarList::CarNode::CarNode() : next(nullptr) {}

CarList::CarNode::CarNode(unsigned w, unsigned sc, unsigned cc,
						  unsigned nw, unsigned nd, Car::FuelType ft, const char * c,
						  CarNode * n)
	: Car(w, sc, cc, nw, nd, ft, c), next(n) {}

void CarList::CarNode::set_next(CarNode * n)
{
	next = n;
}

CarList::CarNode * CarList::CarNode::get_next()
{
	return next;
}




// ----------------------------------------------------------------------
// - CarList IMPLEMENTATIONS --------------------------------------------
// ----------------------------------------------------------------------

CarList::CarList() : head(nullptr) {}

CarList::~CarList()
{
	while (head)
	{
		CarNode * temp = head;
		head = head->get_next();
		delete temp;
	}
}

void CarList::append(unsigned w, unsigned sc, unsigned cc,
					 unsigned nw, unsigned nd, Car::FuelType ft, const char * c)
{
	// 0. special case (the list is empty)
	if (!head) {
		head = new CarNode(w, sc, cc, nw, nd, ft, c, nullptr);
		return;
	}

	// 1. traverse to the tail
	CarNode * tail = head;
	while (tail->get_next()) {
		tail = tail->get_next();
	}

	// 2. create node after tail
	CarNode * new_node = new CarNode(w, sc, cc, nw, nd, ft, c, nullptr);
	tail->set_next(new_node);
}

void CarList::display() const
{
	for (CarNode * curr = head; curr; curr = curr->get_next())
	{
		curr->display();

		if (curr->get_next()) { // lets put a divider between entries
			cout << "--------------------------------------------------" << endl;
		}
	}
}
