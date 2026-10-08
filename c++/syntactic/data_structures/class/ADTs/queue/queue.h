#pragma once

#include <string>
#include <optional>
#include "person.h"

// implemented as CLL
class Queue
{
	private:
		struct Node {
			Person data;
			Node* next;

			Node(const Person&);
		};

		Node* rear;
	public:
		Queue();
		~Queue();

		void enqueue(const Person& data);
		bool dequeue();
		std::optional<Person> peek() const;

		void display() const;
};
