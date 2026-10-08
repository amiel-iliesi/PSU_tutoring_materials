#include "graph.h"
#include <iostream>

using namespace std;

Graph::Vertex::Vertex(const string& name_in): data(name_in), edges_head(nullptr) {}

Graph::~Graph()
{
	for (Vertex& vertex: vertices) {
		while (vertex.edges_head) {
			Vertex::Node* to_delete = vertex.edges_head;
			vertex.edges_head = vertex.edges_head->next;
			delete to_delete;
		}
	}
}

Graph::Vertex* Graph::get_vertex(const string& key) {
	for (Vertex& vertex: vertices) {
		if (vertex.data.get_name() == key) {
			return &vertex;
		}
	}

	return nullptr;
}

const Graph::Vertex* Graph::get_vertex(const string& key) const {
	for (const Vertex& vertex: vertices) {
		if (vertex.data.get_name() == key) {
			return &vertex;
		}
	}

	return nullptr;
}

bool Graph::contains(const string& key) const
{
	if (get_vertex(key) != nullptr) {
		return true;
	}

	return false;
}

bool Graph::connected(const string& a, const string& b) const
{
	const Vertex* va = get_vertex(a);
	const Vertex* vb = get_vertex(b);

	if (va and vb) {
		for (Vertex::Node* edge = va->edges_head; edge; edge = edge->next) {
			if (edge->vertex->data.get_name() == b) {
				return true;
			}
		}
	}

	return false;
}


bool Graph::add_place(const string& name_in)
{
	if (contains(name_in)) { // don't allow duplicates
		return false;
	}

	vertices.emplace_back(name_in);

	return true;
}

// can only connect IF: a and b both exist, and a and b aren't already connected
bool Graph::connect_places(const string& a, const string& b)
{
	if (not (contains(a) and contains(b)) or connected(a, b)) {
		return false;
	}

	Vertex* va = get_vertex(a);
	Vertex* vb = get_vertex(b);

	// standard LLL insert at front
	Vertex::Node* new_a_head = new Vertex::Node;
	new_a_head->vertex = vb;
	new_a_head->next = va->edges_head;
	va->edges_head = new_a_head;

	// same for b
	Vertex::Node* new_b_head = new Vertex::Node;
	new_b_head->vertex = va;
	new_b_head->next = vb->edges_head;
	vb->edges_head = new_b_head;

	return true;
}

void Graph::display() const
{
	/* output format:
	 * A: B, C
	 * B: A, C
	 * C: A, B, D
	 * D: C */

	for (const Vertex& vertex: vertices) {
		cout << vertex.data.get_name() << ": ";

		for (const Vertex::Node* edge = vertex.edges_head; edge; edge = edge->next) {
			cout << edge->vertex->data.get_name();

			if (edge->next) {
				cout << ", ";
			}
		}
		cout << endl;
	}
}
