#pragma once
#include <cstddef>
#include <vector>

class List {
	private:
		struct Node {
			int data;
			Node * prev;
			Node * next;

			Node(): prev(nullptr), next(nullptr) {}
			Node(int d): data(d), prev(nullptr), next(nullptr) {}
			Node(int d, Node* p, Node* n): data(d), prev(p), next(n) {}
		};

		//recursive functions
		void display(const Node*) const;
		void remove_all_evens(Node *);
		void remove_node(Node *&);
		bool insert_forward(Node *&, size_t, int);
		bool insert_backward(Node *&, size_t, int);

		void insert_after(Node *&, int);
		void insert_before(Node *&, int);

		int size(const Node *) const;

		int max(const Node *) const;
		
		// CUSTOM USER FUNCTIONS
		void copy_except_match(Node *& dest, const Node * src, int match);

		Node * head;
		Node * tail;

	public:
		List();
		~List();

		void clear();

		void push(int);
		void append(int);
		bool insert(int, int);
		void display() const;
		void shuffle();
		int size() const;

		int max() const;

		void remove_all_evens();

		// CUSTOM USER FUNCTIONS ------------------------------
		int copy_except_largest(const List & other); // returns max value not copied
};
