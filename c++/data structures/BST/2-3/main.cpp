// NOTE: uncomment me :)
//#define TREE_GLASSBOX_TESTING

#include "tree.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	Tree<char> tree;

	for (char c: string("ebfidja")) {
		tree.insert(move(c));
	}

	tree.display();

#ifdef TREE_GLASSBOX_TESTING
	{ // scoping just for syntax folding :)
		const size_t NUM_ELEMENTS = 100000;
		Tree<int> big_tree;
		for (size_t i = 0; i < NUM_ELEMENTS; ++i) {
			int num;
			// FIXME: this implementation cannot handle duplicate keys
			// TODO: replace data type in tree to buckets of type T
			do {
				num = rand();
			} while (big_tree.contains(num));
			big_tree.insert(move(num));
		}

		cout << "running glassbox testing on " << NUM_ELEMENTS
			<< " elements:" << endl;

		cout << "- The tree hierarchy is "
			<< (big_tree.proper_hierarchy() ? "valid." : "INVALID!") << endl;

		cout << "- The tree is "
			<< (big_tree.is_balanced() ? "balanced." : "UNBALANCED!") << endl;

		cout << "- The tree has "
			<< (big_tree.bidirectional() ? "bidirectional" : "UNIDIRECTIONAL")
			<< " relationships." << endl;

		cout << "- The tree "
			<< (big_tree.size() == NUM_ELEMENTS ? "does not have" : "HAS")
			<< " missing elements." << endl;
	}
#endif

	return 0;
}
