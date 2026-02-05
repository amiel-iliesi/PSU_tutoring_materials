#include "list.h"

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
