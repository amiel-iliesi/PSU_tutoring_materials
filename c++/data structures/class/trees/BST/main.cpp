#include "tree.h"
#include <random>

using namespace std;

int main()
{
	Tree tree;

	random_device rd;
	
	for (int i = 16 + rd() % 16; i >= 0; --i) {
		int to_add;

		// let's avoid duplicates (XXX: a set might've been smarter)
		do {
			to_add = rd() % 100;
		} while (tree.contains(to_add));

		tree.push(to_add);
	}

	tree.display();

	return 0;
}
