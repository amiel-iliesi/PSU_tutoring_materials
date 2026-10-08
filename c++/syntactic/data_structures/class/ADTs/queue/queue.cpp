#include "queue.h"

#include <iostream>

using namespace std;

Queue::Node::Node(const Person& _data):
	data(_data),
	next(nullptr)
{}

Queue::Queue():
	rear(nullptr)
{}

Queue::~Queue()
{
	while (rear->next != rear) {
		Node* to_delete = rear->next;
		rear->next = rear->next->next;
		delete to_delete;
	}

	delete rear;
}

void Queue::enqueue(const Person& data)
{
	Node* new_node = new Node(data);

	if (!rear) {
		rear = new_node;
		rear->next = rear;
	}
	else {
		new_node->next = rear->next;
		rear->next = new_node;
		rear = new_node;
	}
}

bool Queue::dequeue()
{
	if (!rear) {
		return false;
	}

	if (rear == rear->next) {
		delete rear;
		rear = nullptr;
	}
	else {
		Node* to_delete = rear->next;
		rear->next = rear->next->next;
		delete to_delete;
	}

	return true;
}

optional<Person> Queue::peek() const
{
	if (!rear) {
		return nullopt;
	}
	else {
		return rear->next->data;
	}
}

void Queue::display() const
{
	if (!rear) {
		return;
	}

	Node* curr = rear->next;
	while (true) {
		cout << curr->data.name << '(' << curr->data.age << ')';
		
		if (curr == rear) {
			break;
		}

		cout << ", ";
		curr = curr->next;
	}

	cout << endl;
}
