#pragma once

#include <cstddef>

template <typename T>
class Stack {
	private:
		struct Node {
			T data;
			Node *next;

			Node(Node* _next=nullptr);
			Node(T& _data, Node* _next=nullptr);
		};

		Node *top;
		size_t _size;
	public:
		Stack();
		~Stack();

		bool empty() const;
		std::size_t size() const;

		void clear();

		void push(T&);
		void pop();
		T& peek();
};

#include "stack.tpp"
