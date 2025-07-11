#include "DLL.h"
#include <ctime> // for time()
#include <cstddef> // for srand(), rand()
#include <iostream>

using namespace std;

// NOTE: you will not be able to see her functions
// in the proficiency demo
void build(Node*& head)
{
	srand(time(NULL));

	int length = 10 + (rand() % 10);

	head = new Node;
	head->data = rand() % 10;
	head->next = head->prev = nullptr;

	for (int _ = 1; _ < length; ++_) {
		Node* new_node = new Node;
		new_node->data = rand() % 10;
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
}

void destroy(Node*& head)
{
	while (head) {
		Node* to_delete = head;
		head = head->next;
		delete to_delete;
	}
}

void display(const Node* head)
{
	for (const Node* curr = head; curr; curr = curr->next) {
		cout << curr->data;
		if (curr->next) {
			cout << " <-> ";
		}
	}
	cout << endl;
}
