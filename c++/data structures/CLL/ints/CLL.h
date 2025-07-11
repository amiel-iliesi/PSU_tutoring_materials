#pragma once

#include <cstddef> //size_t

class CLL {
private:
	struct Node {
		int data;
		Node* next;

		Node(): data(0), next(nullptr) {}
		Node(int _data): data(_data), next(nullptr) {}
		Node(int _data, Node* _next):
			data(_data), next(_next) {}
	};

	// HELPER FUNCTIONS
	void clear();
	void copy(const CLL &);
	void copy(const Node *, const Node *);

	// RECURSIVE FUNCTIONS
	void clear(Node*&);
	void insert(int, size_t, Node*&);
	void display(const Node* const &) const;
	void display_backwards(const Node* const &) const;
	size_t size(const Node* const &) const;
	
	// recursive functions
	int sum_of_even_indecies(const Node * curr, int index) const;
	void copy_except(const Node * other_curr, const Node * other_rear, int match);

	Node* rear; 
public:
	CLL(): rear(nullptr) {}
	CLL(const CLL &);
	~CLL(); 

	void insert(int, size_t);
	void display() const;
	void display_backwards() const;
	size_t size() const;

	// wrapper functions
	int sum_of_even_indecies() const;
	void copy_except(const CLL & other, int match);
};
