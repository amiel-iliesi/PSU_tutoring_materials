#include "DLL.h"
#include <iostream>

using namespace std;

/*  NOTE: definition of the Node structure

struct Node {
	int data;
	Node* prev;
	Node* next;
};
*/



// --------------------------------------------------
// - function prototypes go HERE --------------------
// --------------------------------------------------

// --------------------------------------------------
// - function prototypes END ------------------------
// --------------------------------------------------




int main()
{
	// Karla's functions (don't touch)
	Node* head = nullptr;
	build(head);
	display(head);

	// ----------------------------------------
	// - put your function calls here! --------
	// ----------------------------------------


	// ----------------------------------------
	// - END of custom user function calls! ---
	// ----------------------------------------

	destroy(head);

	return 0;
}



// --------------------------------------------------
// - function implementations HERE ------------------
// --------------------------------------------------
