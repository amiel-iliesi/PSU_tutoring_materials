#include "bst.h"
#include <iostream>

using namespace std;


int main() {
	node * tree = nullptr;
	build(tree);
	display(tree);

	// PUT YOUR FUNCTION CALLS HERE
	// EX  7.
	node * evens = nullptr;
	copy_evens(evens, tree);
	display(evens);

	// EX 12.
	cout << "all of the leaves in the even tree "
		 << (all_leaves_level(evens) ? "are" : "are not") << " level." << endl;
	clear(evens);

	clear(tree);
	return 0;
}
