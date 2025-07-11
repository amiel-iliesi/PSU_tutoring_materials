#include "BST.h"
#include <iostream>
#include <ctime>

// NOTE: you would not normally be able to see these implementations in the demo!

Tree::Node::Node(int data, Node* left, Node* right):
	data(data), left(left), right(right) {}

Tree::Node::~Node()
{
	delete left;
	delete right;
}

const Tree::Node* Tree::Node::get_max() const
{
	if (right) {
		return right->get_max();
	}
	else {
		return this;
	}
}

void Tree::Node::display(const Node* max) const
{
	if (left) {
		left->display(max);
	}

	std::cout << data;
	if (this != max) {
		std::cout << ", ";
	}
	
	if (right) {
		right->display(max);
	}
}

void Tree::Node::insert(int data)
{
	if (data <= this->data) {
		if (!left) {
			left = new Node(data);
		}
		else {
			left->insert(data);
		}
	}
	else {
		if (!right) {
			right = new Node(data);
		}
		else {
			right->insert(data);
		}
	}
}

Tree::Tree(int min, int max, std::size_t min_size, std::size_t size_var)
{
	root = nullptr;

	srand(time(NULL));

	int range = (max - min) + 1;

	std::size_t size = min_size + (rand() % (size_var + 1));

	for (std::size_t _ = 0; _ < size; ++_) {
		insert((rand() % range) + min);
	}
}

Tree::~Tree()
{
	delete root;
}

void Tree::display() const
{
	if (!root) { return; }

	const Node* max = root->get_max();

	root->display(max);

	std::cout << std::endl;
}

void Tree::insert(int data)
{
	if (!root) {
		root = new Node(data);
	}
	else {
		root->insert(data);
	}
}

