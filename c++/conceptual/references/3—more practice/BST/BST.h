#ifndef __BST_H__
#define __BST_H__

#include <cstdlib>
#include <string>

class Tree {
private:
	//private Node type
	struct Node {
		int data;
		Node *l, *r;

		Node(int data): data(data), l(nullptr), r(nullptr) {}
		Node(): data(0), l(nullptr), r(nullptr) {}
	};

	//private data member(s)
	Node* root;

	//recursive functions
	void clear(Node*&);

	void insert(Node*&, int);
	void display(Node* const&, const std::string&, bool) const;

	//custom functions begin here
public:
	Tree(): root(nullptr) {}
	Tree(const Tree&);
	~Tree();

	void clear();
	void build(int, int, size_t);

	//public functions
	void insert(int);
	void display() const;

	//custom functions begin here
};

#endif //__BST_H__
