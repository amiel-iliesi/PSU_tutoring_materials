#include <iostream>

// NOTE: to make this more flexible, use templates!
#include "queue.h"
#include "person.h"

using namespace std;

int main()
{
	Queue queue;

	queue.enqueue(Person("John", 35));
	queue.enqueue(Person("Jane", 33));
	queue.enqueue(Person("Jeff", 31));
	queue.enqueue(Person("Josiah", 34));
	queue.enqueue(Person("Janette", 32));

	queue.display();

	cout << "\ndequeuing two people...\n\n";
	queue.dequeue();
	queue.dequeue();

	queue.display();

	if (auto front = queue.peek()) {
		cout << "\npeek: name of person at the front = " << front->name << "\n";
	}
	else {
		cout << "\npeek: failure, can't peek an empty queue\n";
	}

	return 0;
}
