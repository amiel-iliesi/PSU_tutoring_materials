#include "BST.h"
#include <iostream>
#include <climits>

using std::cout, std::endl;

int main()
{
	Tree tree;

	int MIN = 0;
	int MAX = 99;
	size_t NUM_OF_NODES = 12;
	bool ALLOW_DUPLICATES = false;

	tree.build(MIN, MAX, NUM_OF_NODES, ALLOW_DUPLICATES);
	tree.display_tree();

	cout << "the height of the tree is " << tree.height() << endl;

	Tree new_tree(tree);
	cout << "copy of tree:" << endl;
	new_tree.display_tree();

	return 0;
}
