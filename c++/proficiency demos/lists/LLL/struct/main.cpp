#include "LLL.h"
#include <iostream>

using namespace std;

/*  NOTE: definition of the Node structure

struct Node {
	int data;
	Node* next;
};
*/

/*  TODO: QUESTIONS

1. Add a new node to the end of a LLL with the same value as the first node
2. Sum all of the data in a LLL and add a new node to the end with this value
3. Remove the first node that isn't a 2
4. Remove the last node
5. Remove the last node but only if it isn't the same as the first
6. Move the first node and put it at the end of the list
7. Swap the data in the first and last nodes
8. Swap the first and last nodes
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

// 1. Add a new node to the end of a LLL with the same value as the first node
