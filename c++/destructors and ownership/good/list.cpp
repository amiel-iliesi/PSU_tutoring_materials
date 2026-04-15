#include "list.h"
#include <cstring>
#include <print>

// -PersonInfo-----------------------------------------------------------
void PersonInfo::copy(const char* _name, const char* _favorite_color, const int& _age)
{
	name = new char[strlen(_name)+1];
	strcpy(name, _name);

	favorite_color = new char[strlen(_favorite_color)+1];
	strcpy(favorite_color, _favorite_color);

	age = _age;
}

void PersonInfo::clear()
{
	delete [] name;
	name = nullptr;
	delete [] favorite_color;
	favorite_color = nullptr;
}

PersonInfo::PersonInfo()
{
	name = nullptr;
	favorite_color = nullptr;
}

PersonInfo::PersonInfo(const PersonInfo& other)
{
	copy(other.name, other.favorite_color, other.age);
}

PersonInfo::PersonInfo(const char* _name, const char* _favorite_color, const int& _age)
{
	copy(_name, _favorite_color, _age);
}

void PersonInfo::operator=(const PersonInfo& other)
{
	clear();
	copy(other.name, other.favorite_color, other.age);
}

PersonInfo::~PersonInfo()
{
	clear();
}

// -List-----------------------------------------------------------------
List::Node::Node()
{
	next = nullptr;
}

List::List()
{
	head = nullptr;
}

List::~List()
{
	while (head) {
		Node* to_delete = head;
		head = head->next;
		delete to_delete;
	}
}

void List::add_person(const PersonInfo& info)
{
	Node* new_node = new Node;
	new_node->info = info;

	new_node->next = head;
	head = new_node;
}

void List::display() const
{
	if (not head) {
		std::println("The list is empty.");
		return;
	}

	std::println("People:");
	for (const Node* curr=head; curr; curr=curr->next) {
		std::println("- {}'s({}) favorite color is {}.",
				curr->info.name, curr->info.age, curr->info.favorite_color);
	}
}
