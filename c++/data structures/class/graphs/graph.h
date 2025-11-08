#pragma once

#include <vector>

// NOTE: for a more complete definition, consider using smart pointers and
// sets, instead of raw pointers and vectors!

// NOTE: This graph implementation runs slow, but should be easier to work with
// as a result. For more details: this std::vector implementation compares on
// equality, so no std::hash or std::less needs to be supplied to the template.
// This does make it run O(n) instead of O(1) or O(log(n)) on most operations.
// But it does mean that you can use whatever types you like, so long as the ==
// operator is supported for the type. If that's too slow, consider replacing
// the vector with a std::unordered_set and requiring a supplied std::hash.

template <typename T>
class Graph
{
	private:
		struct Vertex
		{
			T ID;

			std::vector<Vertex*> edges;

			Vertex(const T&);
			
			bool connected_to(const T&) const;
		};

		Vertex* get(const T&);
		const Vertex* get(const T&) const;

		std::vector<Vertex*> vertices;
	public:
		~Graph();

		bool contains(const T&) const;
		bool push(const T&);
		void pop(const T&);
		bool connect(const T&, const T&);
		bool disconnect(const T&, const T&);
		std::size_t connections(const T&) const;
		bool connected(const T&, const T&) const;
		void display(bool) const;
};

#include "graph.tpp"
