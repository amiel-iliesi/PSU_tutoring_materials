#include "list.h"
#include <print>

using namespace std;

// -supplied functions---------------------------------------------------
List::List()
{
	rear = nullptr;
}

List::~List()
{
	if (!rear) {
		return;
	}

	Node *head = rear->next;
	rear->next = nullptr;
	
	while (head) {
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	rear = nullptr;
}


void List::push(int data)
{
	Node *new_node = new Node;
	new_node->data = data;
	new_node->next = nullptr;

	if (!rear) {
		rear = new_node;
		rear->next = rear;
	}
	else {
		new_node->next = rear->next;
		rear->next = new_node;
	}
}

void List::push_back(int data)
{
	push(data);
	rear = rear->next; //rotate
}

void List::display() const
{
	if (!rear) {
		println("<List @{} is empty>", (void*)this);
	}
	else {
		for (Node *curr=rear->next; curr != rear; curr=curr->next) {
			print("{} -> ", curr->data);
		}

		println("{} -> ...", rear->data);
	}
}

// -custom functions-----------------------------------------------------
void List::recursive_display_wrapper() const
{
	if (!rear) {
		println("The list is empty!");
		return;
	}

	recursive_display(rear->next);

	println(" -> ...");
}

void List::recursive_display(const Node* curr) const
{
	print("{}", curr->data);

	// if we aren't on the last CLL node, we can loop again
	if (curr != rear) {
		print(" -> ");
		recursive_display(curr->next);
	}
}
