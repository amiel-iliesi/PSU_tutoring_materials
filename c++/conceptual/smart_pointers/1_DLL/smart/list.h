#pragma once

#include <memory>

class List
{
	private:
		struct Node {
			int data;

			std::unique_ptr<Node> next;
			Node* prev;

			Node(int _data=0);
		};

		std::unique_ptr<Node> head;
	
	public:
		void insert(int _data); // insert sorted
		void display() const;
};
