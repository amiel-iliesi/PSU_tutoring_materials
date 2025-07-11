#include "BST.h"
#include <iostream>
#include <ctime>
#include <set>
#include <stdexcept>

using std::cout, std::endl;
using std::srand, std::rand, std::time;
using std::string;
using std::set;

//------------------------------DEFAULT FUNCTIONS-------------------------------
void Tree::clear(Node*& curr)
{
	if (!curr) { return; }

	clear(curr->l);
	clear(curr->r);

	delete curr;
	curr = nullptr;
}

void Tree::clear()
{
	clear(root);
}

// wrapper
Tree::Tree(const Tree& other)
{
	copyTree(other.root, root);
}

// recursive function
void Tree::copyTree(const Node* src, Node*& dest) const
{
	if (!src) { return; } // end of copying
	
	dest = new Node(src->data); // load dest w/ src data
	
	copyTree(src->l, dest->l); // copy left side
	copyTree(src->r, dest->r); // copy right side
}

Tree::~Tree()
{
	clear();
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
			throw std::domain_error("BST build error: range is too small to not contain duplicates");
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

void Tree::insert(int value)
{
	insert(root, value);
}

void Tree::insert(Node*& curr, int value)
{
	if (!curr) {
		curr = new Node(value);
		return;
	}

	if (value >= curr->data)
		insert(curr->r, value);
	else
		insert(curr->l, value);
}

bool Tree::remove(int value)
{
	return remove(root, value);
}

Tree::Node* Tree::popMin(Node*& curr)
{
	if (!curr->l) {
		Node* toPop = curr;
		curr = curr->r;
		return toPop;
	}

	return popMin(curr->l);
}

bool Tree::remove(Node*& curr, int value)
{
	if (!curr) { return false; }


	if (curr->data == value) {
		Node* toDelete = curr;

		if (!curr->l) //<2 child; not @l
			curr = curr->r;

		else if (!curr->r) //<2 child; not @r
			curr = curr->l;

		else { //both children
			Node* IOS = popMin(curr->r);
			std::swap(IOS->data, curr->data);
			toDelete = IOS;
		}

		delete toDelete;

		return true;
	}
	else if (curr->data < value)
		return remove(curr->r, value);
	else
		return remove(curr->l, value);
}

bool Tree::contains(int value) const
{
	return contains(root, value);
}

bool Tree::contains(Node* const& curr, int value) const
{
	if (!curr) { return false; }
	if (curr->data == value) { return true; }

	if (value > curr->data)
		return contains(curr->r, value);
	else
		return contains(curr->l, value);
}

size_t Tree::size() const
{
	return size(root);
}

size_t Tree::size(const Node* curr) const
{
	if (!curr) { return 0; }

	return 1 + size(curr->l) + size(curr->r);
}

int max(int a, int b)
{
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int Tree::height() const
{
	if (!root) { return 0; }

	return height(root) - 1;
}

int Tree::height(const Node * current) const
{
	if (!current) { return 0; }

	int left_height = height(current->l);
	int right_height = height(current->r);
	int children_height = max(left_height, right_height);

	return children_height + 1;
}


void Tree::display_tree() const
{
	if (!root) { return; }

	display_tree(root->r, "", true);

	cout << root->data << '\n';

	display_tree(root->l, "", false);
}

void Tree::display_tree(Node* const& curr, const string& prefix, bool is_right) const
{
	if (!curr) { return; }

	display_tree(curr->r, prefix + (is_right ? "   " : "│  "), true);

	cout << prefix;
	cout << (is_right ? "┌─ " : "└─ ") << curr->data << '\n';

	display_tree(curr->l, prefix + (is_right ? "│  " : "   "), false);
}




//-------------------------------CUSTOM FUNCTIONS-------------------------------

