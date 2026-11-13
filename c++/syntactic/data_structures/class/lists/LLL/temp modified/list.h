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
		
		// -helper functions-----------------------
		void displayRecHelper(const Node* curr) const;
		void removeMatchLastHelper(Node*& curr, int& last_value);
		// ----------------------------------------
	public:
		List();
		~List();

		void push(int);
		void push_back(int);
		void display() const;

		// -custom functions-----------------------
		void displayRecWrapper() const;
		void removeMatchLastWrapper();
		// ----------------------------------------
};
