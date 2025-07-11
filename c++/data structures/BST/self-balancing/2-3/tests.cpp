#include "tree.h"
#include <cassert>
#include <iostream>
#include <set>

using namespace std;

void Tree::assert_parent_child_relationship() const
{
	for (const Tree* child: children) {
		if (child) {
			assert(child->parent == this);
			child->assert_parent_child_relationship();
		}
	}
}

void Tree::assert_key_hierarchy() const
{
	//1. determine which children to check (and how many checks need to be done)
	int children_internal_nodes[3] = {0,0,0};
	for (int i = 0; i < 3; ++i) {
		if (!children[i]) {
			children_internal_nodes[i] = 0;
			continue;
		}


		if (children[i]->data[1]) {
			children_internal_nodes[i] = 2;
		}
		else if (children[i]->data[0]) {
			children_internal_nodes[i] = 1;
		}
		else {
			children_internal_nodes[i] = 0;
		}
	}

	//2. check internal nodes
	if (data[1])
	{
		assert(*data[1] > *data[0]);
	}

	//3. check children against internal nodes
	if (children_internal_nodes[0]) {
		for (int i = 0; i < children_internal_nodes[0]; ++i) {
			if (not (*children[0]->data[i] < *data[0])) {
				cerr << *children[0]->data[i] << ',' << *data[0] << endl;
				display();
			}
			assert(*children[0]->data[i] < *data[0]);
		}
	}

	if (children_internal_nodes[1]) {
		for (int i = 0; i < children_internal_nodes[1]; ++i) {
			if (not (*children[1]->data[i] > *data[0])) {
				cerr << *children[1]->data[i] << ',' << *data[0] << endl;
				display();
			}
			assert(*children[1]->data[i] > *data[0]);
			if (data[1]) {
				assert(*children[1]->data[i] < *data[1]);
			}
		}
	}

	if (children_internal_nodes[2]) {
		for (int i = 0; i < children_internal_nodes[2]; ++i) {
			assert(*children[2]->data[i] > *data[1]);
		}
	}
}

void Tree::assert_internal_structure() const
{
	bool child_exists[4] = { children[0] and not children[0]->empty(),
						     children[1] and not children[1]->empty(),
						     children[2] and not children[2]->empty(),
						     children[3] and not children[3]->empty() };

	if (child_exists[3] or data[2]) {
		throw length_error("encountered a (non-temporary) 4-node");
	}

	if (data[1] and not data[0]) {
		throw logic_error("internal nodes contain gap");
	}

	if ((!data[1] and child_exists[2]) or
		(!data[0] and (child_exists[1] or child_exists[0])))
	{
		throw logic_error("child has no respective internal node parent");
	}

	for (const Tree * child: children) {
		if (child and not child->empty()) {
			child->assert_internal_structure();
		}
	}
}

void Tree::assert_size(size_t expected_size) const
{
	assert (expected_size == size());
}

void Tree::assert_contents(set<int> & inserted) const
{
	for (const int & i: inserted) {
		assert(contains(i));
	}
}

int main()
{
	Tree ints;
	const int SIZE = 100000;
	const int MIN = 0;
	const int MAX = 200000;
	set<int> inserted;

	{ //lets replicate Tree::build so we can keep the `std::set<int> inserted` exposed
		int amount = SIZE;
		long long range = (long long)MAX - (long long)MIN + 1;
		while (amount--) {
			int value;
			do {
				value = (rand() % range) + MIN;
			} while (inserted.contains(value));
			inserted.insert(value);
			ints.insert(value);
		}
	}

	cerr << "running tests...\n" << endl;

	ints.assert_parent_child_relationship();
	cerr <<  "parent test: PASS\nall children know their correct parents...\n" << endl;

	ints.assert_key_hierarchy();
	cerr << "key test: PASS\n"
		 << "all children and internal nodes are in the correct order...\n" << endl;

	ints.assert_internal_structure();
	cerr << "count test: PASS\n"
		 << "all nodes within tree are internally consistent...\n" << endl;

	ints.assert_size((size_t)SIZE);
	cerr << "size test: PASS\n"
		 << "size of tree matches expected size; all insertions are accounted for" << endl;

	ints.assert_contents(inserted);
	cerr << "contents test: PASS\n"
		 << "everything we expected to be in the tree, was in the tree\n"
		 << "NOTE: combined with the size test, and that duplicates are not allowed,\n"
		 << "      we've verified that the tree contains *only* what we expected.\n"
		 << endl;

	cerr << "------------------\n"
		 << "-ALL TESTS PASSED-\n"
		 << "------------------" << endl;
	return 0;
}
