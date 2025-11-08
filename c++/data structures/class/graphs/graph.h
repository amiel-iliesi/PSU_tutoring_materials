#pragma once

#include <vector>

// NOTE: for a more complete definition, consider using smart poTers and
// sets, instead of raw poTers and vectors!

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
