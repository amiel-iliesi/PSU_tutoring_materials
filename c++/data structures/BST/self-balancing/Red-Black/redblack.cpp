#include "redblack.h"

// Constructors
Tree::Node(int d, bool r): data(d), bool(r),
						   parent(nullptr), left(nullptr), right(nullptr) {}

Tree::Node(int d): Node(d, true) {}

Tree::Node(): Node(0) {}

Tree::Tree(): root(nullptr) {}

// Destructors
Tree::~Node()
{
	delete left;
	delete right;
}

Tree::~Tree()
{
	delete root;
}

void Tree::insert(int data)
{
	insert(root, nullptr, data);
}

void Tree::insert(Node *& curr, const Node * prev int data)
{
	if (!curr) {
		curr = new Node(data);
		curr->parent = prev;

		correct(curr);
	}
	else {
		if (data < curr->data) {
			insert(curr->left, curr, data);
		}
		else {
			insert(curr->right, curr, data);
		}
	}
}

void Tree::correct(Node * curr)
{
	Node * parent = curr->parent;
	
	Node * grandparent = (parent ? parent->parent : nullptr);

	Node * uncle;
	if (grandparent) {
		if (grandparent->left == parent) {
			uncle = grandparent->right;
		}
		else {
			uncle = grandparent->left;
		}
	}
	else {
		uncle = nullptr;
	}



	if (not parent or not parent->red) { return; } // case 1,3: no violation
	else if(parent->red and uncle and uncle->red) { // case 2: parent and uncle are red
		parent->red = false;
		uncle->red = false;
		grandparent->red = true;

		correct(grandparent);
	}
	else if (parent->red and not grandparent) { // case 4: parent is root
		parent->red = false;
	}
	// case 5: parent is red and uncle is black
	else if (parent->red and (not uncle or not uncle->red)) {
		//TODO
	}
	//TODO
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

