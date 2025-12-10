#include "list.h"

#include <iostream>

using namespace std;

int main()
{
	Node* head = nullptr;
	build(head);

	// -put function calls here------------------------------------
	display(head);
	// ------------------------------------------------------------
	
	destroy(head);

	return 0;
}
