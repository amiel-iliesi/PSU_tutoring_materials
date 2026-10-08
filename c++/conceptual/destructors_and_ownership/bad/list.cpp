#include "list.h"
#include <cstring>
#include <print>

List::List()
{
	head = nullptr;
}

List::~List()
{
	while (head) {
		Node* curr = head;
		head = head->next;

		delete [] curr->info.name;
		curr->info.name = nullptr;
		delete [] curr->info.favorite_color;
		curr->info.favorite_color = nullptr;

		delete curr;
	}
}

void List::add_person(const PersonInfo& new_person)
{
	Node* new_node = new Node;
	
	new_node->info.name = new char[strlen(new_person.name)+1];
	strcpy(new_node->info.name, new_person.name);
	
	new_node->info.favorite_color = new char[strlen(new_person.favorite_color)+1];
	strcpy(new_node->info.favorite_color, new_person.favorite_color);

	new_node->info.age = new_person.age;

	new_node->next = head;
	head = new_node;
}

void List::display() const
{
	if (not head) {
		std::println("List is empty.");
		return;
	}

	std::println("People:");
	for (const Node* curr=head; curr; curr=curr->next) {
		std::println("- {}'s({}) favorite color is {}.",
				curr->info.name,
				curr->info.age,
				curr->info.favorite_color);
	}
}
