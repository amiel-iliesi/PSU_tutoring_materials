#include "BST.h"
#include <cassert>
#include <iostream>

using std::cerr, std::endl;


//NOTE: run these tests with `make test`
//		or by running the commands it contains:
//		`g++ -Wall -Wextra -Werror -O2 -g -DBST_TEST -o test BST_test.cpp BST.cpp`
//		`./test`
//		`rm test`



int main()
{
	Tree testTree;
	testTree.build(0, RAND_MAX, 10000);

	cerr << "testing that BST hierarchy holds at each nodes..." << endl;
	testTree.assert_hierarchy();
	cerr << "test passed!" << endl;

	cerr << "\ntesting that all leaves were properly null terminated..." << endl;
	testTree.assert_proper_leaves();
	cerr << "test passed!" << endl;

	cerr << "\ntesting removal (this may take a while)..." << endl;
	size_t removed = 0;
	for (int i = 0; i < RAND_MAX; ++i) {
		int toRemove = rand();
		bool has = testTree.contains(toRemove);
		if (has)
			++removed;
		assert(has == testTree.remove(toRemove));
	}
	cerr << "test passed!" << endl;

	cerr << "\nretesting BST hierarchy after removals..." << endl;
	testTree.assert_hierarchy();
	cerr << "test passed!" << endl;

	cerr << "\nretesting null termination after removals..." << endl;
	testTree.assert_proper_leaves();
	cerr << "test passed!" << endl;

	cerr << "\ntesting if size counting is working properly..." << endl;
	assert(testTree.size() == (10000 - removed));
	cerr << "test passed!" << endl;

	return 0;
}





void Tree::assert_hierarchy() const
{
	assert_hierarchy(root);
}

void Tree::assert_hierarchy(const Node* curr) const
{
	if (!curr) { return; }

	if (curr->l) { assert(curr->l->data <= curr->data); }
	if (curr->r) { assert(curr->r->data >= curr->data); }

	assert_hierarchy(curr->l);
	assert_hierarchy(curr->r);
}

void Tree::assert_proper_leaves() const
{
	assert_proper_leaves(root);
}

void Tree::assert_proper_leaves(const Node* curr) const
{
	if (!curr) { return; }
	if (curr) { assert(curr->data == curr->data); } //attempt to dereference

	// if curr exists but dererference fails, it *should* have been a leaf
	// but was not properly set to nullptr

	assert_proper_leaves(curr->l);
	assert_proper_leaves(curr->r);
}
