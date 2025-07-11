#include "CLL.h"
#include <cstdlib> // for rand
#include <ctime> // to seed rand
#include <iostream> // for std::cout in List::display

// NOTE: You will not be able to see these implementations in Karla's examples
// Just pretend that this file does not exist!

List::Node::Node(int data, Node* next): data(data), next(next) {}


List::List(int min, int max, std::size_t min_size, std::size_t size_var)
{
	srand(time(NULL));

	rear = nullptr;

	std::size_t size = min_size + rand() % (size_var + 1);
	
	if (size == 0) {
		return;
	}

	int range = max - min;

	rear = new Node((rand() % (range + 1)) + min);
	rear->next = rear;

	for (size_t _ = 1; _ < size; ++_) {
		rear->next = new Node((rand() % (range + 1)) + min, rear->next);
	}
}

List::~List()
{
	if (!rear) { return; }

	while (rear->next != rear) {
		Node* to_delete = rear->next;
		rear->next = rear->next->next;
		delete to_delete;
	}
	delete rear;
}

void List::display() const
{
	for (const Node* curr=rear->next; true; curr=curr->next) {
		std::cout << curr->data << " -> ";

		if (curr == rear) {
			break;
		}
	}

	std::cout << "..." << std::endl;
}
