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
	public:
		List();
		~List();

		void push(int);
		void push_back(int);
		void display() const;

		// -custom functions-----------------------
		// ----------------------------------------
};
