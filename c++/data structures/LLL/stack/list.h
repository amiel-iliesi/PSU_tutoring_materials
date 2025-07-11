#pragma once
#include <cstdlib>

class Stack
{
	private:
	struct Node {
		int data;
		Node *next;

		Node(): data(0), next(nullptr) {}
		Node(int newData): data(newData), next(nullptr) {}
	};

	//---recursive functions--------
	void display(const Node*) const;
	size_t size(const Node *) const;
	
	//data members
	Node * head;

	public:
	//---basic functions------------
	Stack(): head(nullptr) {}
	~Stack();
	void display() const;
	size_t size() const;



	//---stack functions-----------
	void push(int);
	void pop();
	int peek() const;
};
