#pragma once
#include <cstdlib>
#include <memory> //unique_ptr

class List
{
	private:
	struct Node;
	using Uptr = std::unique_ptr<Node>;

	struct Node {
		int data;
		Uptr next;

		Node(): data(0) {}
		Node(int newData): data(newData) {}
	};

	//---recursive functions--------
	void insert(int, Uptr& current);
	void display(const Node*) const;
	
	//---custom recursive functions-

	//data members
	Uptr head;

	public:
	//---basic functions------------
	void insert(int);
	void display() const;

	//build a random list
	void build(size_t, const int, const int);

	//---custom functions-----------
};
