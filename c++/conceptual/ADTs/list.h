#pragma once

#include "person.h"

#include <string>

class List
{
	private:
		struct Node
		{
			Person data;
			Node* prev;
			Node* next;

			Node(const Person& _data,
					Node* _prev = nullptr,
					Node* _next = nullptr):
				data(_data), prev(_prev), next(_next)
			{}
		};

		Node* get_node(unsigned index);

		Node *head;
		Node *tail;
	public:
		// constructors
		List();
		~List();

		// modifiers
		void insert(unsigned index, const Person& data);
		void push_front(const Person& data);
		void push_back(const Person& data);
		void clear();

		// accessors
		Person& get(unsigned index);
		void remove(unsigned index);
		Person& front();
		Person& back();

		// capacity
		std::size_t size() const;
		bool is_empty() const;

		// operators
		std::string as_string() const;
};
