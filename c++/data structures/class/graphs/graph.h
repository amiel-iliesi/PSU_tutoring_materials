#pragma once

#include <vector>

// NOTE: for a more complete definition, consider using smart pointers and
// sets, instead of raw pointers and vectors!

class Graph
{
	private:
		struct Vertex
		{
			int ID;

			std::vector<Vertex*> edges;

			Vertex(int);
			
			bool connected_to(int) const;
		};

		Vertex* get(int);
		const Vertex* get(int) const;

		std::vector<Vertex*> vertices;
	public:
		~Graph();

		bool contains(int) const;
		bool push(int);
		void pop(int);
		bool connect(int, int);
		bool disconnect(int, int);
		std::size_t connections(int) const;
		bool connected(int, int) const;
		void display(bool) const;
};
