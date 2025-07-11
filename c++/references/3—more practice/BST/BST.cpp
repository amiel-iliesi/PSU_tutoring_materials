#include "BST.h"
#include <iostream>
#include <ctime>

using std::cout, std::endl;
using std::srand, std::rand, std::time;
using std::string;

//------------------------------DEFAULT FUNCTIONS-------------------------------

//this wipes out the tree, it's mostly here so the destructor can use it
void Tree::clear(Node*& curr) {
	if (!curr) { return; }

	clear(curr->l);
	clear(curr->r);

	delete curr;
	curr = nullptr;
}

void Tree::clear() {
	clear(root);
}

Tree::~Tree() {
	clear(root);
}




// this builds you a random tree by inserting random numbers
// within the range and quantity you give it
void Tree::build(int min, int max, size_t amount) {
	srand(time(NULL));

	long long range = (long long)max - (long long)min + 1;

	while (amount--)
		insert((rand() % range) + min);
}




void Tree::insert(int value) {
	insert(root, value);
}

void Tree::insert(Node*& curr, int value) {
	if (!curr) {
		curr = new Node(value);
		return;
	}

	if (value >= curr->data)
		insert(curr->r, value);
	else
		insert(curr->l, value);
}




// these display functions make the output pretty, you don't have to understand
// these, it's just here to help visualize your functions as you make them. But I
// won't stop you from learning from this code :)
void Tree::display() const {
	if (!root) { return; }

	cout << root->data << '\n';

	display(root->l, "", root->r);
	display(root->r, "", false);
}

void Tree::display(Node* const& curr, const string& prefix, bool hasRightSibling) const {
	if (!curr) { return; }

	cout << prefix;

	cout << (hasRightSibling ? "├─ " : "└─ ") << curr->data << '\n';

	display(curr->l, prefix + (hasRightSibling ? "│  " : "   "), curr->r);
	display(curr->r, prefix + (hasRightSibling ? "│  " : "   "), false);
}




//-------------------------------CUSTOM FUNCTIONS HERE-------------------------------

