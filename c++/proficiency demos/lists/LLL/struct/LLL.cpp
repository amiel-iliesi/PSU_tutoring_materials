#include "LLL.h"
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
	head->data = rand() % 20;
	head->next = nullptr;

	Node* tail = head;

	for (int i = 1; i < length; ++i) {
		tail->next = new Node;
		tail = tail->next;
		tail->next = nullptr;
		tail->data = rand() % 20;
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
	int sum = 0;
	for (const Node* curr = head; curr; curr = curr->next) {
		sum += curr->data;
		cout << curr->data;
		if (curr->next) {
			cout << " -> ";
		}
	}
	cout << "\nThe sum of the data is " << sum << ".\n";
}
