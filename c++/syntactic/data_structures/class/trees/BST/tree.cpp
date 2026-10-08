#include "tree.h"
#include <iostream>

using namespace std;

Tree::Node::Node(int x)
{
	data = x;
	left = nullptr;
	right = nullptr;
}

Tree::Tree()
{
	root = nullptr;
}

Tree::~Tree()
{
	clear(root);
}

void Tree::clear(Node*& curr)
{
	if (!curr) {
		return;
	}

	clear(curr->left);
	clear(curr->right);

	delete curr;
	curr = nullptr;
}


void Tree::push(int data)
{
	push(root, data);
}

void Tree::push(Node*& curr, int data)
{
	if (!curr) {
		curr = new Node(data);
	}
	else if (data <= curr->data) {
		push(curr->left, data);
	}
	else {
		push(curr->right, data);
	}
}

void Tree::display() const
{
	if (!root) {
		cout << "<Tree @" << this << " is empty>" << endl;
	}
	else {
		const Node *max = get_max(root);
		display(root, max);
		cout << endl;
	}
}

const Tree::Node* Tree::get_max(const Node* curr) const
{
	if (not curr or not curr->right) {
		return curr;
	}
	else {
		return get_max(curr->right);
	}
}

void Tree::display(const Node *curr, const Node *max) const
{
	if (!curr) {
		return;
	}

	display(curr->left, max);

	cout << curr->data;

	if (curr != max) {
		cout << ", ";
	}

	display(curr->right, max);
}

bool Tree::contains(int data) const
{
	return contains(root, data);
}

bool Tree::contains(const Node* curr, int data) const
{
	if (!curr) {
		return false;
	}
	else if (data == curr->data) {
		return true;
	}
	else if (data > curr->data) {
		return contains(curr->right, data);
	}
	else {
		return contains(curr->left, data);
	}
}

// -custom functions go here-----------------------------------
Tree Tree::copy_evens() const
{
	Tree new_tree;

	copy_evens(this->root, new_tree);

	return new_tree;
}

void Tree::copy_evens(const Node* current, Tree& new_tree) const
{
	if (!current) {
		return;
	}

	if (current->data % 2 == 0) {
		new_tree.push(current->data);
	}

	copy_evens(current->left, new_tree);
	copy_evens(current->right, new_tree);
}
// ------------------------------------------------------------
