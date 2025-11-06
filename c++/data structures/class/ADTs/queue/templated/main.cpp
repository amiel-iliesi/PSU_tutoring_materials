#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
	Queue<int> queue;

	cout << "enqueueing {1, 2, 3, 4, 5}..." << endl;
	for (int n: {1, 2, 3, 4, 5}) {
		queue.enqueue(n);
	}

	cout << "dequeuing 3 items: ";
	for (int i = 0; i < 3; ++i) {
		cout << queue.peek();

		queue.dequeue();

		if (i != 2) {
			cout << ", ";
		}
	}
	cout << endl;

	cout << "enqueueing: {6, 7, 8}..." << endl;
	for (int n: {6, 7, 8}) {
		queue.enqueue(n);
	}


	cout << "dequeuing remaining: ";
	while (not queue.empty()) {
		cout << queue.peek();

		queue.dequeue();

		if (not queue.empty()) {
			cout << ", ";
		}
	}
	cout << endl;

	return 0;
}
