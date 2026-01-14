#pragma once

#include "person.h"

// NOTE: this is a doubly-linked list

class List {
	private:
		struct Node {
			Person data;
			Node* next;
			Node* prev;

			Node();
		};

		Node* head;
	
	public:
		List();
		~List();

		void emplace(std::string, int);

		void display() const;
		void display_neighbors(std::string) const;
};
