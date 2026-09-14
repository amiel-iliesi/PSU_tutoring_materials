#include "tree.h"
#include <random>
#include <iostream>

using namespace std;

int main()
{
	Tree tree;

	// -fill with random numbers-----------------------------------
	random_device rd;
	mt19937 gen(rd());
	
	for (int i = 16 + gen() % 16; i >= 0; --i) {
		int to_add;

		// let's avoid duplicates (XXX: a set might've been smarter)
		do {
			to_add = gen() % 100;
		} while (tree.contains(to_add));

		tree.push(to_add);
	}
	// ------------------------------------------------------------

	tree.display();

	cout << "copying evens to new tree..." << endl;
	Tree even_copy = tree.copy_evens();

	even_copy.display();

	return 0;
}
