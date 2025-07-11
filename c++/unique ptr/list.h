#pragma once
#include <memory>

class List {
	private:
		class Node {
			private:
				int data;
				std::unique_ptr<Node> next;
			public:
				Node(int&&);
				int& get();
				Node* get_next();
				void set_next(std::unique_ptr<Node>);
		};

		std::unique_ptr<Node> head;
	
	public:
		void insert(int&&);
		void display() const;
};
