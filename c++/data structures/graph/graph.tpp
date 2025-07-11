#include <functional>
#include <algorithm>
#include <unordered_set>
#include <queue>

template <class T, class Hash, class KeyEqual>
Graph<T, Hash, KeyEqual>::Vertex::Vertex(T a): data(a) {}

template <class T, class Hash, class KeyEqual>
void Graph<T, Hash, KeyEqual>::Vertex::prune() {
	auto it = edges.begin();
	while (it != edges.end()) {
		auto spt = it->first.lock();
		if (not spt) {
			it = edges.erase(it);
		}
		else {
			++it;
		}
	}
}

template <class T, class Hash, class KeyEqual>
bool Graph<T, Hash, KeyEqual>::Vertex::connected(const T& b) {
	prune();

	for (auto it = edges.begin(); it != edges.end(); ++it) {
		auto spt = it->first.lock();
		if (!spt) { // WARNING: this should never run; should have been pruned
			continue;
		}

		const T& a = spt->data;
		if (std::invoke(KeyEqual{}, a, b)) {
			return true;
		}
	}

	return false;
}

template <class T, class Hash, class KeyEqual>
void Graph<T, Hash, KeyEqual>::Vertex::update_weight(const T& b, float weight) {
	prune();

	for (auto& pair: edges) {
		const T& curr = pair.first.lock()->data;
		if (std::invoke(KeyEqual{}, curr, b)) {
			pair.second = weight;
			break;
		}
	}
}

template <class T, class Hash, class KeyEqual>
float Graph<T, Hash, KeyEqual>::Vertex::get_weight(const T& b) const
{
	for (const auto& e: edges) {
		if (e.first.lock()->data == b) {
			return e.second;
		}
	}

	return 0;
}

template <class T, class Hash, class KeyEqual>
bool Graph<T, Hash, KeyEqual>::add(const T& a) {
	if (vertices.contains(a)) {
		return false; // cannot have vertices with duplicate keys in the graph
	}
	else {
		vertices[a] = std::make_shared<Vertex>(a);
		return true;
	}
}

template <class T, class Hash, class KeyEqual>
bool Graph<T, Hash, KeyEqual>::remove(const T& a) {
	if (not vertices.contains(a)) {
		return false; // cannot remove what isn't there
	}
	else {
		auto to_remove = vertices.find(a);
		vertices.erase(to_remove);
		return true;
	}
}

template <class T, class Hash, class KeyEqual>
bool Graph<T, Hash, KeyEqual>::connect(const T& a, const T& b, float weight) {
	if (not (vertices.contains(a) and vertices.contains(b))) {
		return false; // cannot connect what does not exist
	}
	else {
		auto spt = vertices[a];
		if (spt->connected(b)) {
			return false; // can't connect what is already connected
		} else {
			spt->edges.push_back({vertices[b], weight});
			return true;
		}
	}
}

template <class T, class Hash, class KeyEqual>
bool Graph<T, Hash, KeyEqual>::connect_bi(const T& a, const T& b, float weight) {
	return connect(a, b, weight) and connect(b, a, weight);
}

template <class T, class Hash, class KeyEqual>
bool Graph<T, Hash, KeyEqual>::update_weight(const T& a, const T& b, float weight) {
	if (not (vertices.contains(a) and vertices.contains(b))) {
		return false; // definitely not connected, one of the vertices DNE
	}
	else if (not vertices[a]->connected(b)) {
		return false; // cannot update a weight for a connection that DNE
	}
	else {
		vertices[a]->update_weight(b, weight);
		return true;
	}
}

template <class T, class Hash, class KeyEqual>
std::vector<std::pair<T, float>>
Graph<T, Hash, KeyEqual>::dijkstra(const T& a, const T& b)
{
	// NOTE: use shared pointers for links, because weak pointers cannot be
	// compared, nor hashed, which is required for operating both the visited
	// set, and the link map
	struct Link {
		std::shared_ptr<Vertex> at;
		std::shared_ptr<Vertex> from;
		float cum_weight;
	};

	if (not (vertices.contains(a) and vertices.contains(b))) {
		return {}; // both endpoints don't exist, don't even bother
	}

	typedef std::pair<std::weak_ptr<Vertex>, float> Edge;

	// keeps us from cycling
	std::unordered_set<std::shared_ptr<Vertex>> visited;

	auto comp = [](const Link& a, const Link& b) {
		return a.cum_weight <= b.cum_weight;
	};

	std::priority_queue<Link,
		std::vector<Link>,
		decltype(comp)
	> search_queue;

	search_queue.push({vertices[a], nullptr, 0});

	// gives us memory, lets us retrace our steps
	std::unordered_map<std::shared_ptr<Vertex>, Link> link_map;

	while (not search_queue.empty()) {
		Link current = search_queue.top();
		search_queue.pop();

		if (visited.contains(current.at)) {
			continue;
		}

		// update link map to new value OR overwrite previous value if new value
		// is shorter
		if (not link_map.contains(current.at)
			or link_map[current.at].cum_weight < current.cum_weight)
		{
			link_map[current.at] = current;
		}

		const Vertex& v = *(current.at);

		if (v.data == b) {  // found endpoint!
			break;
		}

		for (const Edge& e: v.edges) {
			search_queue.push({
					e.first.lock(),
					current.at,
					e.second + current.cum_weight
			});
		}

		visited.insert(current.at);
	}

	if (link_map.contains(vertices[b])) {
		std::vector<std::pair<T, float>> path;

		for (Link curr = link_map[vertices[b]];
			 curr.at->data != a;
			 curr = link_map[curr.from])
		{
			float weight = curr.from->get_weight(curr.at->data);
			path.push_back({curr.at->data, weight});
		}

		path.push_back({a, 0});

		std::reverse(path.begin(), path.end());

		return path;
	}
	else { // endpoint was never linked to; it's unreachable
		return {};
	}
}
