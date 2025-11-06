#pragma once

// To make the concept of ADT even clearer than the Stack example, we're going
// to use a prebuilt type for our underlying data structure: `std::list`

#include <list>



template <typename T>
class Queue {
	private:
		std::list<T> list;

	public:
		bool empty() const;

		void enqueue(const T&);
		void dequeue();
		T& peek();
};

#include "queue.tpp"
