#include "CLL.h"
#include <iostream>

using namespace std;

/*  NOTE: definition of the Node structure

struct Node {
	int data;
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
	Node* rear = nullptr;
	build(rear);
	display(rear);

	// ----------------------------------------
	// - put your function calls here! --------
	// ----------------------------------------

	// ----------------------------------------
	// - END of custom user function calls! ---
	// ----------------------------------------

	destroy(rear);

	return 0;
}



// --------------------------------------------------
// - function implementations HERE ------------------
// --------------------------------------------------
