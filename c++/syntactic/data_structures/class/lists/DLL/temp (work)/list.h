#pragma once

class List
{
	private:
		struct Node
		{
			int data;
			Node *next;
			Node *prev;
		};

		Node *head;
		Node *tail;

		// -helper functions-----------------------
		int remove2Largest(Node* curr,
				int& largest,
				int& second_largest);

		void remove(Node* to_remove);
		// ----------------------------------------
	public:
		List();
		~List();

		void push(int);
		void push_back(int);
		void display() const;

		// -custom functions-----------------------
		// returns: sum of all removed nodes
		int remove2Largest();
		// ----------------------------------------
};
