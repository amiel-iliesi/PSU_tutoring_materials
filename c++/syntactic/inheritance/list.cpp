#include "list.h"
#include <iostream>

using namespace std;

// -CONSTRUCTORS/DESTRUCTORS---------------------------------------------
List::Node::Node(): next(nullptr) {}

List::Node::Node(string _name, int _age, string _job_title, int _salary):
	Worker(_name, _age, _job_title, _salary), next(nullptr)
{}

List::List(): head(nullptr) {}

List::~List()
{
	clear();
}

// -NODE FUNCTIONS-------------------------------------------------------
List::Node*& List::Node::get_next()
{
	return next;
}
				
const List::Node* List::Node::get_next() const
{
	return next;
}

void List::Node::set_next(Node* _next)
{
	next = _next;
}

// -LIST FUNCTIONS-------------------------------------------------------

void List::clear()
{
	clear(head);
}

void List::clear(Node*& curr)
{
	if (not curr) {
		return;
	}

	clear(curr->get_next());
	delete curr;
}

void List::add(string _name, int _age, string _job_title, int _salary)
{
	Node* new_node = new Node(_name, _age, _job_title, _salary);
	new_node->set_next(head);
	head = new_node;
}

void List::display() const
{
	cout << "Workers:\n--------\n";
	display(head);
	cout << '\n';
}

void List::display(const Node* curr) const
{
	if (!curr) {
		return;
	}

	cout << "* ";
	curr->display();
	if (curr->get_next()) {
		cout << '\n';
	}
	display(curr->get_next());
}
