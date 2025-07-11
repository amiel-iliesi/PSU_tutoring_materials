#pragma once
#include <cstddef> // for size_t

class List {
	private:
		struct Node {
			int data;
			Node* next;

			Node(int data=0, Node* next=nullptr);
		};

		Node* head;

		// CUSTOM FUNCTIONS HERE--------

		//------------------------------
	public:
		// these are predefined
		List(int min=0, int max=10, std::size_t min_size=10, std::size_t size_var=5);
		~List();

		void display() const;

		// CUSTOM FUNCTIONS HERE--------

		//------------------------------
};
