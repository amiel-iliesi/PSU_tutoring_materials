#include "people.h"
#include <cstring>
#include <print>

// -Person---------------------------------------------------------------------
Person::Person(): name(nullptr)
{}

Person::~Person()
{
	clear();
}

Person::Person(const char* n, const int a)
{
	copy(n, a);
}

Person::Person(const Person& other)
{
	copy(other.name, other.age);
}

void Person::operator=(const Person& other)
{
	clear();
	copy(other.name, other.age);
}

void Person::copy(const char* name_input, const int age_input)
{
	name = new char[strlen(name_input)+1];
	strcpy(name, name_input);

	age = age_input;
}

void Person::clear()
{
	delete [] name;
	name = nullptr;
}

// -People---------------------------------------------------------------------
People::Node::Node(): next(nullptr)
{}

People::Node::Node(const Person& person_in):
	data(person_in),
	next(nullptr)
{}

void People::copy(const People& other)
{
	if (not other.head) {
		return;
	}

	head = new Node(other.head->data);

	Node* curr = head;
	Node* other_curr = other.head;

	while (other_curr->next) {
		curr->next = new Node(other_curr->next->data);

		curr = curr->next;
		other_curr = other_curr->next;
	}
}

void People::clear()
{
	while (head) {
		Node* to_delete = head;
		head = head->next;
		delete to_delete;
	}
}

People::People(): head(nullptr)
{}

People::~People()
{
	clear();
}

People::People(const People& other): head(nullptr)
{
	copy(other);
}
		
People& People::operator=(const People& other)
{
	clear();
	copy(other);

	return *this;
}

// insert alphabetically
void People::push(const Person& person_in)
{
	Node* new_node = new Node(person_in);

	// case 0: empty list
	if (not head) {
		head = new_node;
		return;
	}

	// case 1: replaces head
	if (strcmp(person_in.name, head->data.name) <= 0) {
		new_node->next = head;
		head = new_node;
		return;
	}

	// case 2: in the middle of the list somewhere
	for (Node* curr=head; curr->next; curr=curr->next) {
		if (strcmp(person_in.name, curr->next->data.name) <= 0) {
			new_node->next = curr->next;
			curr->next = new_node;
			return;
		}
	}

	// case 3: tail
	Node* tail = head;
	while (tail->next) {
		tail = tail->next;
	}
	tail->next = new_node;
}

void People::display() const
{
	if (not head) {
		return;
	}

	std::print("{}({})", head->data.name, head->data.age);
	
	for (Node* curr=head->next; curr; curr=curr->next) {
		std::print(", {}({})", curr->data.name, curr->data.age);
	}
}
