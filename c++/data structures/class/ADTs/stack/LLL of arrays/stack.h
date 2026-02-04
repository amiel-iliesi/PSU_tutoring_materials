#pragma once

#include <string>
#include <optional>

// NOTE: for simplicity, the core data type is just a string

class Stack
{
	private:
		struct Node {
			std::string* data;
			Node* next;

			Node(size_t ARR_SIZE);
			~Node();
		};

		Node* top;
		size_t top_index;
		const size_t ARR_SIZE;
	public:
		Stack(size_t ARR_SIZE=5);
		~Stack();

		void push(std::string data);
		bool pop();
		std::optional<std::string> peek() const;

		void display() const;
};
