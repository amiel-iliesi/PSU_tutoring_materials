#pragma once

class List
{
	private:
		struct Node
		{
			int data;
			Node *next;
		};

		Node *head;

		// -recursive helper functions-------------
		void append(Node*& curr, int x);
		int length(const Node*) const;
		int sum(const Node*) const;
		bool insert(Node*& curr, int x, int pos);
		bool pop(Node*& curr, int pos);
		void remove(Node*& curr, int x, int count);
		
		// NOTE: `curr` expected to be `nullptr`; not validated
		void copy(Node*& curr, const Node* other_curr); 
		void clear(Node*& curr);
		// ----------------------------------------
	public:
		List();
		~List();

		void push(int);
		void push_back(int);
		void display() const;

		// -custom functions-----------------------
		// EXERCISES: easy
		// 1. Append supplied element to list.
		void append(int x);

		// 2. Insert supplied element at the front of the list.
		// (I already implemented this for main to use to construct the list)
		
		// 3. Count elements in the list.
		int length() const;

		// 4. Sum elements in the list.
		int sum() const;

		// EXERCISES: medium
		// 1. Insert supplied element to the given index
		// return whether or not it was able to insert (IE valid index supplied)
		bool insert(int x, int pos);

		// 2. Delete element at given index, can fail like (Med.1.)
		bool pop(int pos);

		// 3. Remove first `n` matches of a given element, or *all* if supplied
		// count is `-1`
		void remove(int x, int count);

		// 4. Overload the copy constructor
		List(const List& other);

		// 5. Overload the assignment operator
		void operator=(const List& other);

		// TODO: EXERCISES: hard
		
		// TODO: EXERCISES: absurd

		// ----------------------------------------
};
