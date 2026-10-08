#include "list.h"

int main()
{
	Node* rear = nullptr;
	build(rear);

	// -put function calls here------------------------------------
	display(rear);
	// ------------------------------------------------------------
	
	destroy(rear);

	return 0;
}
