#include "list.h"

#include <iostream>

using namespace std;

int main()
{
	Node* head = nullptr;
	build(head);

	// -put function calls here------------------------------------
	display(head);

	Node* tail = head;
	while (tail->next) {
		tail = tail->next;
	}

	cout << "swapping elements at index 1 and 2...\n";
	swap(head->next, head->next->next, head);

	display(head);

	cout << "swapping head and tail...\n";
	swap(head, tail, head);

	display(head);

	// ------------------------------------------------------------
	
	destroy(head);

	return 0;
}
