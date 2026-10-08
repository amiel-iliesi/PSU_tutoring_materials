#pragma once

#include "list.h"

class Queue
{
	private:
		List list;
	public:
		void push(const Person& data);
		Person peek();
		Person pop();

		std::size_t size() const;
		bool is_empty() const;
};
