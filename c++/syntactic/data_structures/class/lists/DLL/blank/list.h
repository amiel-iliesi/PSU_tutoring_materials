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
	public:
		List();
		~List();

		void push(int);
		void push_back(int);
		void display() const;

		// -custom functions-----------------------
		// ----------------------------------------
};
