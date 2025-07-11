#pragma once
#include <iostream>

template <typename T>
class List
{
	private:
		struct Node {
			T data;
			Node *next;

			Node(): next(nullptr) {}
			Node(T _data, Node * _next = nullptr): data(_data), next(_next) {}
		};

		using Ptr = Node*;

		Ptr head;
	public:
		List(): head(nullptr) {}
		List(const List&) = delete;
		~List();

		friend std::ostream & operator<< (std::ostream & out, const List & obj)
		{
			for (Ptr curr = obj.head; curr; curr = curr->next) {
				out << curr->data;
				if (curr->next) {
					std::cout << "->";
				}
			}

			return out;
		}

		void insert(const T&);

	//---custom functions-----------
};

#include "list.tpp"
