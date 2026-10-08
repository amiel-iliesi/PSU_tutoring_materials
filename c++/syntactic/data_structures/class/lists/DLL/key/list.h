#pragma once

#include <cstddef>
#include <functional>

class List
{
	private:
		struct Node
		{
			int data;
			Node *next;
			Node *prev;
		};

		Node *head;
		Node *tail;

		void clear();

		// -custom functions-----------------------
		size_t count(const Node* curr) const;
		bool insert(size_t index, int value, Node*& curr);
		size_t remove(int count, int value, Node* curr);
		void remove(Node*& to_remove);
		void copy(Node*& dst, const Node* src);
		size_t remove_evens(Node* curr);
		size_t remove_if(std::function<bool(const int&)> filter, Node* curr);
		void reverse(Node* curr);
		// ----------------------------------------
	public:
		List();
		~List();

		void push(int);
		void push_back(int);
		void display() const;

		// -custom functions-----------------------
		size_t count() const;
		bool insert(size_t index, int value);
		size_t remove(int count, int value);
		List(const List& other);
		void operator=(const List& other);
		void reverse();
		size_t remove_evens();
		size_t remove_if(std::function<bool(const int&)> filter);
		// ----------------------------------------
};
