#pragma once

#include "worker.h"

class List
{
	private:
		class Node: public Worker
		{
			private:
				Node* next;

			public:
				Node();
				Node(string _name, int _age, string _job_title, int _salary);

				Node*& get_next();
				const Node* get_next() const;
				void set_next(Node* _next);
		};
	
		Node* head;

		// -RECURSIVE HELPER FUNCTIONS---------------------------------
		void clear(Node*& curr);
		void display(const Node* curr) const;
	
	public:
		List();
		~List();

		void clear();

		void add(string _name, int _age, string _job_title, int _salary);

		void display() const;
};
