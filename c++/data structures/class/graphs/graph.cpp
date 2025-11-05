#include "graph.h"
#include <iostream>
#include <vector>

using namespace std;

Graph::Vertex::Vertex(int _ID)
{
	ID = _ID;
}

Graph::Vertex* Graph::get(int ID)
{
	for (Vertex *vertex: vertices) {
		if (ID == vertex->ID) {
			return vertex;
		}
	}

	return nullptr;
}

const Graph::Vertex* Graph::get(int ID) const
{
	for (const Vertex *vertex: vertices) {
		if (ID == vertex->ID) {
			return vertex;
		}
	}

	return nullptr;
}

Graph::~Graph()
{
	for (Vertex* vertex: vertices) {
		delete vertex;
	}
	vertices.clear();
}

bool Graph::contains(int ID) const
{
	for (const Vertex* vertex: vertices) {
		if (vertex->ID == ID) {
			return true;
		}
	}

	return false;
}

bool Graph::Vertex::connected_to(int _ID) const
{
	for (const Vertex* edge: edges) {
		if (edge->ID == _ID) {
			return true;
		}
	}

	return false;
}

bool Graph::push(int ID)
{
	if (contains(ID)) {
		return false;
	}

	vertices.push_back(new Vertex(ID));

	return true;
}

void Graph::pop(int ID)
{
	// erase all references to ID in all edge lists
	for (Vertex *vertex: vertices) {
		{
			vector<Vertex*>& ve = vertex->edges;

			for (auto e_it = ve.begin(); e_it != ve.end(); ++e_it) {
				if ((*e_it)->ID == ID) {
					ve.erase(e_it);
					break;
				}
			}
		}
	}
	
	// then delete the ID from the main list of vertices
	vector<Vertex*>& v = vertices;
	for (auto v_it = v.begin(); v_it != v.end(); ++v_it) {
		if ((*v_it)->ID == ID) {
			delete *v_it;
			v.erase(v_it);
			break;
		}
	}
}

bool Graph::connect(int va, int vb)
{
	Vertex *va_p = get(va);
	Vertex *vb_p = get(vb);	

	if (not (va_p and vb_p) or va_p->connected_to(vb)) {
		return false;
	}

	va_p->edges.push_back(vb_p);

	return true;
}

bool Graph::disconnect(int va, int vb)
{
	Vertex *va_p = get(va);
	Vertex *vb_p = get(vb);

	if (not (va_p and vb_p) or not va_p->connected_to(vb)) {
		return false;
	}

	erase(va_p->edges, vb_p);

	return true;
}

size_t Graph::connections(int ID) const
{
	const Vertex *vertex = get(ID);

	return (vertex ? vertex->edges.size() : 0);
}

void Graph::display(bool verbose) const
{
	if (vertices.empty()) {
		cout << "<Graph @" << this << " is empty>" << endl;
	}
	else if (verbose) {
		for (const Vertex* vertex: vertices) {
			cout << vertex->ID << ": ";
			{
				const vector<Vertex*>& ve = vertex->edges;
				for (auto e_it = ve.begin(); e_it != ve.end(); ++e_it) {
					cout << (*e_it)->ID;
					if (next(e_it) != ve.end()) {
						cout << ", ";
					}
				}
			}
			cout << endl;
		}
	}
	else {
		{
			const vector<Vertex*>& v = vertices;
			for (auto v_it = v.begin(); v_it != v.end(); ++v_it) {
				cout << (*v_it)->ID;
				if (next(v_it) != v.end()) {
					cout << ", ";
				}
			}
		}
		cout << endl;
	}
}

