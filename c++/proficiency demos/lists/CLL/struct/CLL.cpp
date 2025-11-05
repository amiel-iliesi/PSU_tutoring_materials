#include "CLL.h"
#include <ctime> // for time()
#include <cstddef> // for srand(), rand()
#include <iostream>

using namespace std;

// NOTE: you will not be able to see her functions
// in the proficiency demo
void build(Node*& rear)
{
    const int MIN = 0;
    const int MAX = 20;
    const int RANGE = (MAX - MIN) + 1;

	srand(time(NULL));

	int length = 10 + (rand() % 10);

	rear = new Node;
	rear->data = (rand() % RANGE) + MIN;
	rear->next = rear;
	
	for (int i = 1; i < length; ++i) {
		Node* new_node = new Node;
		new_node->data = (rand() % RANGE) + MIN;
		new_node->next = rear->next;

		rear->next = new_node;
	}
}

void destroy(Node*& rear)
{
	if (!rear) { return; }

	while (rear->next != rear) {
		Node* to_delete = rear->next;
		rear->next = rear->next->next;
		delete to_delete;
	}
	delete rear;
}

void display(const Node* rear)
{
	if (!rear) { return; }

	for (const Node* curr=rear->next; true; curr=curr->next) {
		cout << curr->data << " -> ";

		if (curr == rear) {
			break;
		}
	}
	cout << "..." << endl;
}
