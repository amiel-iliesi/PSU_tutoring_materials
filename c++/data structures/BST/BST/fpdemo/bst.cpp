#include "bst.h"

#include <cstdlib> // for rand()
#include <ctime> // for time() so srand() can use it
#include <iostream>

using namespace std;

// NOTE: you can edit these values if you want to change the type of tree made
const int TREE_SIZE_MAX = 20;
const int TREE_SIZE_MIN = 10;
const bool ALLOW_DUPLICATES = false;



// ---------------------------WRITE YOUR FUNCTIONS HERE----------------------------

// EX 7.
void copy_evens(node *& dest, const node * src)
{
	if (!src) { return; }

	if (src->data % 2 == 0) {
		insert(dest, src->data);
	}

	copy_evens(dest, src->left);
	copy_evens(dest, src->right);
}

// EX 12.
bool all_leaves_level(const node * root)
{
	int max_height = height(root);

	return all_leaves_level(root, max_height, 0);
}

bool all_leaves_level(const node * root, const int max_height, int curr_height)
{
	if (!root) { return true; }

	if (!root->left && !root->right) {
		return curr_height == max_height;
	}
	else {
		return all_leaves_level(root->left, max_height, curr_height+1) &&
		       all_leaves_level(root->right, max_height, curr_height+1);
	}
}

int height(const node * root)
{
	if (!root) { return -1; }

	int l = height(root->left);
	int r = height(root->right);

	int max_child = (l > r ? l : r);

	return max_child + 1;
}

void copy(node *& dest, const node * src)
{
	if (!src) { return; }

	if (dest) {
		clear(dest);
	}

	dest = new node;
	dest->data = src->data;
	copy(dest->left, src->left);
	copy(dest->right, src->right);
}

bool has_duplicates(const node * root)
{
	if (!root) { return false; }

	bool root_is_duplicated = contains(root->right, root->data);

	bool left_has_duplicates = has_duplicates(root->left);
	bool right_has_duplicates = has_duplicates(root->right);

	return root_is_duplicated || left_has_duplicates || right_has_duplicates;
}

void duplicate_IOS(node *& root)
{
	int IOS_value = find_IOS(root);	

	if (IOS) {
		insert(root, IOS_value);
	}
}

int find_IOS(const node * root)
{
	return min(root->right);
}

int min(const node * root)
{
	if (!root->left) { // base case
		return root->data;
	}
	else { // recursive case
		return min(root->left);
	}
}

void remove_max(node *& root)
{
	if (!root) { return; } // empty tree

	if (!root->right) { // we are at max
		node * hold = root->left; // only child we *could* have; might be nullptr
		delete root;
		root = hold;
	}
	else {
		remove_max(root->right);
	}
}





// ----------------------------------SUPPLIED--------------------------------------
// NOTE: you won't be able to see how these functions are implemented in the 
//		 real FP Demo, so if you want more practice, you can ignore them here
//		 too. They're just included for optional reference.

void build(node *& root)
{
	srand(time(NULL));

	int size_range = TREE_SIZE_MAX - TREE_SIZE_MIN;
	int value_range = 2 * size_range; //times 2 -- to make no-duplicates possible
	int tree_size = (rand() % size_range) + TREE_SIZE_MIN;

	for (int i = 0; i < tree_size; ++i) {
		int value;
		do {  // keep getting value until it's not a duplicate; lazy but works
			value = rand() % value_range;
		} while (not ALLOW_DUPLICATES and contains(root, value));

		insert(root, value);
	}
}

// NOTE: you won't have this function given to you in the FP demo
void insert(node *& root, int data)
{
	if (!root) {  // base case
		root = new node;
		root->data = data;
		root->left = root->right = nullptr;
	}

	else {  // recursion
		if (data < root->data)
			insert(root->left, data);
		else
			insert(root->right, data);
	}
}

void display(const node * root)
{
	cout << "the tree contains " << size(root) << " elements." << endl;

	display_rec(root, 0);
}

// NOTE: you won't have this function given to you in the FP demo
void display_rec(const node * root, int level)
{
	if (!root) { return; }

	// FYI this displays in pre-order
	cout << "level " << level << ": " << root->data << endl;

	display_rec(root->left, level+1);
	display_rec(root->right, level+1);
}

// NOTE: you won't have this function given to you in the FP demo
int size(const node * root)
{
	if (!root) { return 0; }

	return 1 + size(root->left) + size(root->right);
}

// NOTE: you won't have this function given to you in the FP demo
bool contains(const node * root, int data)
{
	if (!root) { return false; }  // case 1

	if (root->data == data) { return true; } // case 2

	if (data < root->data) {
		return contains(root->left, data);
	}
	else {
		return contains(root->right, data);
	}
}

// NOTE: you *MIGHT NOT* have this function given to you in the FP demo
void clear(node *& root)
{
	if (!root) { return; }

	clear(root->left);
	clear(root->right);

	delete root;
	root = nullptr;
}
