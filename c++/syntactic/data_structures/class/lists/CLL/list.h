#pragma once

class List
{
	private:
		struct Node
		{
			int data;
			Node *next;
		};

		Node *rear;

		// -custom private functions---------------
		void recursive_display(const Node* curr) const;
		// ----------------------------------------
	public:
		List();
		~List();

		void push(int);
		void push_back(int);
		void display() const;

		// -custom functions-----------------------
		void recursive_display_wrapper() const;
		// ----------------------------------------
};
