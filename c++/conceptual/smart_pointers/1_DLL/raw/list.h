#pragma once

class List
{
	private:
		struct Node {
			int data;

			Node* next;
			Node* prev;

			Node(int _data=0);
		};

		Node* head;
	
	public:
		List();
		~List();

		void insert(int _data); // insert sorted
		void display() const;
};
