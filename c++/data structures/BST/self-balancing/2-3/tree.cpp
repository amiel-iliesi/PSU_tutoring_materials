#include "tree.h"
#include <iostream>
#include <stdexcept>
#include <set>
#include <ctime>

using namespace std;

Tree::~Tree()
{
	for (int i = 0; i < 3; ++i)
		delete data[i];
	
	for (int i = 0; i < 4; ++i)
		delete children[i];
}

size_t Tree::size() const
{
	if (empty()) {
		return 0;
	}

	size_t size_sum = 1 + (bool)data[1];
	for (const Tree * child: children) {
		if (child) {
			size_sum += child->size();
		}
	}

	return size_sum;
}

bool Tree::empty() const
{
	return not data[0];
}

bool Tree::contains(const int & key) const
{
	if (!data[0]) {
		return false;
	}

	if (key == *data[0] or (data[1] and key == *data[1])) {
		return true;
	}

	if (key < *data[0] and children[0]) {
		return children[0]->contains(key);
	}
	else if ((!data[1] and children[1] and key > *data[0]) or
			 (data[1] and children[1] and key < *data[1]))
	{
		return children[1]->contains(key);
	}
	else if (data[1] and key > *data[1] and children[2]) {
		return children[2]->contains(key);
	}

	return false; //not in current node, and corresponding child to search does not exist
}

void Tree::build(int min, int max, size_t amount, bool duplicates_allowed)
{
    srand(time(NULL));

    long long range = (long long)max - (long long)min + 1;


    if (duplicates_allowed) {
        while (amount--)
            insert((rand() % range) + min);
    }
    else {
        if (range < (long long)amount) {
            throw std::length_error("BST build error: range is too small to not contain duplicates");
        }
        set<int> inserted;
        while (amount--) {
            int value;
            do {
                value = (rand() % range) + min;
            } while (inserted.contains(value));
            inserted.insert(value);
            insert(value);
        }
    }
}

void Tree::split()
{
	Tree * hold[4];
	for (int i = 0; i < 4; ++i) {
		hold[i] = children[i];
	}
	
	children[0] = new Tree(this);
	children[0]->data[0] = data[0];

	children[1] = new Tree(this);
	children[1]->data[0] = data[2];

	children[2] = children[3] = nullptr;

	data[0] = data[1];  // center internal node is now solitary
	data[1] = data[2] = nullptr;

	if (hold[0]) {
		children[0]->children[0] = hold[0];
		children[0]->children[0]->parent = children[0];
	}
	if (hold[1]) {
		children[0]->children[1] = hold[1];
		children[0]->children[1]->parent = children[0];
	}
	if (hold[2]) {
		children[1]->children[0] = hold[2];
		children[1]->children[0]->parent = children[1];
	}
	if (hold[3]) {
		children[1]->children[1] = hold[3];
		children[1]->children[1]->parent = children[1];
	}
}

void Tree::merge(Tree * child)
{
	//1. find out which child we're merging
	int child_id = 0;
	while (children[child_id] != child) {
		++child_id;
	}

	//2. find where the merged values go
	// CASE: parent (2 node -> 3 node)
	if (!data[1]) {
		switch (child_id) {
			case 1:
				data[1] = child->data[0];
				children[2] = child->children[1];
				children[1] = child->children[0];
				children[2]->parent = this;
				children[1]->parent = this;
				break;
			case 0:
				//shift over original values before overwrite
				children[2] = children[1];
				data[1] = data[0];

				data[0] = child->data[0];
				children[0] = child->children[0];
				children[1] = child->children[1];
				children[0]->parent = this;
				children[1]->parent = this;
				break;
			default:
				throw logic_error("a 2 node tree cannot have 3 children"); 
		}
		//transfer ownership
		child->children[0] = child->children[1] = nullptr;
		child->data[0] = nullptr; 
		delete child;
	}
	// CASE: parent (3 node -> 4 node)
	else if (!data[2]) {
		switch (child_id) {
			case 2:
				data[2] = child->data[0];
				children[3] = child->children[1];
				children[2] = child->children[0];
				//reassign grandchildren's parents
				children[3]->parent = this;
				children[2]->parent = this;
				break;
			case 1:
				//shift over original values before overwrite
				children[3] = children[2];
				data[2] = data[1];

				data[1] = child->data[0];
				children[2] = child->children[1];
				children[1] = child->children[0];
				children[2]->parent = this;
				children[1]->parent = this;
				break;
			case 0:
				children[3] = children[2];
				children[2] = children[1];
				data[2] = data[1];
				data[1] = data[0];

				data[0] = child->data[0];
				children[0] = child->children[0];
				children[1] = child->children[1];
				children[0]->parent = this;
				children[1]->parent = this;
				break;
			default:
				throw logic_error("a 3 node tree cannot have 4 children"); 
		}

		child->children[0] = child->children[1] = nullptr;
		child->data[0] = nullptr; 
		delete child;

		//3. repeat splitting and merging for parents until properties are restored
		split();
		if (parent) {
			parent->merge(this);
		}
	}
}

void Tree::insert(const int & datum)
{
	insert(new int(datum));
}

// takes a pointer because this function can re-insert existing data w/o copying
void Tree::insert(int * datum)
{
	bool is_leaf = not children[0];
	if (is_leaf) {
		// CASE: internal nodes are empty
		if (!data[0]) {
			data[0] = datum;
		}
		// CASE: insert into a 2 node
		else if (!data[1]) {
			if (*datum > *data[0]) {
				data[1] = datum;
			}
			else {
				data[1] = data[0];
				data[0] = datum;
			}
		}
		// CASE: insert into a 3 node
		else {
			if (*datum > *data[1]) {
				data[2] = datum;
			}
			else if (*datum > *data[0]) {
				data[2] = data[1];
				data[1] = datum;
			}
			else {
				data[2] = data[1];
				data[1] = data[0];
				data[0] = datum;
			}
			split();
			if (parent) {
				parent->merge(this);
			}
		}
	}
	else {  // not at a leaf, find insertion point
		if (*datum < *data[0]) {
			children[0]->insert(datum);
		}
		else if (!data[1] or (data[1] and (*datum < *data[1]))) {
			children[1]->insert(datum);
		}
		else {
			children[2]->insert(datum);
		}
	}
}

//TODO: delete

void Tree::display() const
{
    if (!data[0]) { return; }

	bool child_to_print[3] = {children[0] and not children[0]->empty(),
							  children[1] and not children[1]->empty(),
							  children[2] and not children[2]->empty()};

	if (child_to_print[2]) {
		children[2]->display("", true, false, true);
	}

	if (data[1]) {
		cout << *data[1] << '\n';
	}

	if (child_to_print[1]) {
		children[1]->display("", true, data[1], not (child_to_print[2] or data[1]));
	}

    cout << *data[0] << '\n';

	if (child_to_print[0]) {
		children[0]->display("", false, true, true);
	}
}   

void Tree::display(const string& prefix,
				   bool is_right,
				   bool has_right_parent,
				   bool at_edge) const
{
	bool child_to_print[3] = {children[0] and not children[0]->empty(),
							  children[1] and not children[1]->empty(),
							  children[2] and not children[2]->empty()};

	if (!data[0]) { return; }

	/* these are the sections being printed, below
	┌─ e
	d
	├─ c
	b
	└─ a
	*/

	// print: e
	if (child_to_print[2]) {
		children[2]->display(prefix + (is_right and not has_right_parent ? "   " : "│  "),
									   true, false, true);
	}

	// print: d
	if (data[1]) {
		cout << prefix;
		if (not at_edge or not is_right) {
			cout << "├─ ";
		}
		else {
			cout << (is_right ? "┌─ " : "└─ ");
		}
		cout << *data[1] << '\n';
	}

	// print: c
	if (child_to_print[1]) {
		children[1]->display(prefix + (data[1] or has_right_parent ? "│  " : "   "),
							 true,
							 data[1],
							 not child_to_print[2]);
	}

	// print: b
    cout << prefix;
	if (not at_edge or (is_right and data[1])) {
		cout << "├─ ";
	}
	else {
		cout << (is_right ? "┌─ " : "└─ ");
	}
	cout << *data[0] << '\n';

	// print: a
	if (child_to_print[0]) {
		children[0]->display(prefix + (is_right ? "│  " : "   "), false, true, true);
	}
}
