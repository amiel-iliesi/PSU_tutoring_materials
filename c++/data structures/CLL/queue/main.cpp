#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
	Queue my_queue;

	cout << "NOTE: the \"-> ...\" in the displayed lists means that's where "
		 << "the loop of the CLL restarts.\n" << endl;

	// queueing some words to start with
	for (const char * str: {"this", "is", "a", "test!"}) {
		my_queue.enqueue(str);
	}

	// display initial list
	my_queue.display();

	// -------- dequeue test ---------
	cout << "\nremoving two words from the queue..." << endl;
	my_queue.dequeue();
	my_queue.dequeue();
	my_queue.display();


	// -------- enqueue test ---------
	const char NEW_WORD[] = "WOW!";
	cout << "\nadding " << NEW_WORD << " into the queue..." << endl;
	my_queue.enqueue(NEW_WORD);
	my_queue.display();


	// -------- peek test --------
	char peek_buffer[256];
	my_queue.peek(peek_buffer);
	cout << "\nthe next word in the queue is: " << peek_buffer << endl;

	return 0;
}
