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

	void copyTree(const Node*, Node*&) const;

	void insert(Node*&, int);
	bool remove(Node*&, int); //remove by searching for int
	Node* popMin(Node*&);
	bool remove(Node*&); //remove current node from tree
	bool contains(Node * const&, int) const;
	size_t size(const Node*) const;
	int height(const Node*) const;

	void display_tree(Node* const&, const std::string&, bool) const;

	//some testing functions, these are defined in BST_test.cpp
	//if you don't care about tests, you can get rid of these lines, and BST_test.cpp
	#ifdef BST_TEST
	void assert_hierarchy(const Node*) const;
	void assert_proper_leaves(const Node*) const;
	#endif //BST_TEST
	
	//custom functions begin here
public:
	Tree(): root(nullptr) {}
	Tree(const Tree&);
	~Tree();

	void build(int, int, size_t, bool);

	//public functions
	void insert(int);
	bool remove(int);
	void clear();
	bool contains(int) const;
	size_t size() const;
	int height() const;

	void display_tree() const;

	#ifdef BST_TEST
	void assert_hierarchy() const;
	void assert_proper_leaves() const;
	#endif //BST_TEST

	//custom functions begin here
};

#endif //__BST_H__
