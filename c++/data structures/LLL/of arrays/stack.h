#pragma once

#include <iostream>
#include <climits>

class Stack
{
	private:
		struct Node
		{
			int * data;
			Node * next;

			~Node();
			Node(int arr_size);
			Node(int arr_size, Node * p);
		};


		Node * head;
		int arr_size;
		int top_index;
	public:
		Stack(int input_arr_size);
		~Stack();

		bool is_empty() const;

		void push(int);
		bool pop();
		int peek() const;
		void display() const;
};
