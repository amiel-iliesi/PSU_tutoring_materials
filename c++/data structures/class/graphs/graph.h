#pragma once

#include <vector>

#include "place.h"

class Graph
{
	private:
		struct Vertex {
			Place data;

			struct Node {
				Vertex* vertex;
				Node* next;
			};

			Node* edges_head;

			Vertex(const std::string&);
		};

		Vertex* get_vertex(const std::string&);
		const Vertex* get_vertex(const std::string&) const;

		std::vector<Vertex> vertices;
	
	public:
		~Graph();

		bool contains(const std::string&) const;
		bool connected(const std::string&, const std::string&) const;

		bool add_place(const std::string&);
		bool connect_places(const std::string&, const std::string&);

		void display() const;
};
