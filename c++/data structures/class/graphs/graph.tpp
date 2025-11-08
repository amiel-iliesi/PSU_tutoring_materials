#include <iostream>
#include <vector>

using namespace std;

template <typename T>
Graph<T>::Vertex::Vertex(const T& key)
{
	ID = key;
}

template <typename T>
Graph<T>::Vertex* Graph<T>::get(const T& ID)
{
	for (Vertex *vertex: vertices) {
		if (ID == vertex->ID) {
			return vertex;
		}
	}

	return nullptr;
}

template <typename T>
const Graph<T>::Vertex* Graph<T>::get(const T& ID) const
{
	for (const Vertex *vertex: vertices) {
		if (ID == vertex->ID) {
			return vertex;
		}
	}

	return nullptr;
}

template <typename T>
Graph<T>::~Graph()
{
	for (Vertex* vertex: vertices) {
		delete vertex;
	}
	vertices.clear();
}

template <typename T>
bool Graph<T>::contains(const T& ID) const
{
	for (const Vertex* vertex: vertices) {
		if (vertex->ID == ID) {
			return true;
		}
	}

	return false;
}

template <typename T>
bool Graph<T>::Vertex::connected_to(const T& key) const
{
	for (const Vertex* edge: edges) {
		if (edge->ID == key) {
			return true;
		}
	}

	return false;
}

template <typename T>
bool Graph<T>::push(const T& ID)
{
	if (contains(ID)) {
		return false;
	}

	vertices.push_back(new Vertex(ID));

	return true;
}

template <typename T>
void Graph<T>::pop(const T& ID)
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

template <typename T>
bool Graph<T>::connect(const T& va, const T& vb)
{
	Vertex *va_p = get(va);
	Vertex *vb_p = get(vb);	

	if (not (va_p and vb_p) or va_p->connected_to(vb)) {
		return false;
	}

	va_p->edges.push_back(vb_p);

	return true;
}

template <typename T>
bool Graph<T>::disconnect(const T& va, const T& vb)
{
	Vertex *va_p = get(va);
	Vertex *vb_p = get(vb);

	if (not (va_p and vb_p) or not va_p->connected_to(vb)) {
		return false;
	}

	erase(va_p->edges, vb_p);

	return true;
}

template <typename T>
size_t Graph<T>::connections(const T& ID) const
{
	const Vertex *vertex = get(ID);

	return (vertex ? vertex->edges.size() : 0);
}

template <typename T>
void Graph<T>::display(bool verbose) const
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

