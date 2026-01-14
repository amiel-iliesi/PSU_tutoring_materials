#include "list.h"
#include <iostream>

using namespace std;

List::List(): head(nullptr) {}

List::~List()
{
	while (head) {
		Node* to_delete = head;
		head = head->next;
		delete to_delete;
	}
}

List::Node::Node(): next(nullptr), prev(nullptr) {}

void List::emplace(string _name, int _age)
{
	Node* new_person = new Node;
	new_person->data = Person(_name, _age);
	
	if (head) {
		new_person->next = head;
		head->prev = new_person;
	}
	head = new_person;
}

void List::display() const
{
	if (!head) {
		return;
	}

	cout << head->data.who();
	for (Node* curr=head->next; curr; curr=curr->next) {
		cout << ", " << curr->data.who();
	}
	cout << '\n';
}

void List::display_neighbors(string _name) const
{
	bool found_person = false;
	
	for (Node* curr=head; curr; curr=curr->next) {
		if (curr->data.who() == _name) {
			cout << curr->data.who() << " is neighbors with "
				 << curr->prev->data.who() << " and " << curr->next->data.who()
				 << '\n'; 
			
			found_person = true;
			
			break;
		}
	}

	if (not found_person) {
		cout << "I don't know who " << _name << " is!\n";
	}
}
