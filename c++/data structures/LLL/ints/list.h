#pragma once
#include <cstdlib>

class List
{
	private:
	struct Node {
		int data;
		Node *next;

		Node(): data(0), next(nullptr) {}
		Node(int newData): data(newData), next(nullptr) {}
	};

	//---recursive functions--------
	void insert(int, Node *&);
	void display(const Node*) const;
	bool remove(size_t, Node*&);
	int get(size_t, const Node*) const;
	size_t size(const Node *) const;
	void swap_head_tail(Node *& curr);
	int count_greater_than_tail(Node *, int &) const;
	int remove_all_after_last_2(Node *&, bool &);
	int remove_last_2(Node *&, bool &);
	
	//---custom recursive functions-
	void insert_ascending(int, Node*&);
	int count_match(int match, const Node * current) const;

	//data members
	Node * head;

	public:
	//---basic functions------------
	List(): head(nullptr) {}
	~List();
	void insert(int);
	void display() const;
	bool remove(size_t);
	int get(size_t) const;
	size_t size() const;

	//build a random list
	void build(size_t, const int, const int);

	//---custom functions-----------
	void insert_ascending(int);
	int count_first() const;
	int count_primes() const;
	int count_composites() const;
	bool is_prime(Node * current) const;
	void swap_head_tail();
	int count_greater_than_tail() const;
	int remove_all_after_last_2();
	int remove_last_2();
};
