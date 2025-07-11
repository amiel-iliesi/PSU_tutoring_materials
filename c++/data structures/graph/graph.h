#pragma once

#include <memory>
#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>


template <class T,
		  class Hash = std::hash<T>,
		  class KeyEqual = std::equal_to<T>>
class Graph {
	private:
		struct Vertex {
			T data;
			typedef std::pair<std::weak_ptr<Vertex>, float> Edge;
			std::vector<Edge> edges;
			
			Vertex(T);

			// before looking at edges, you can prune the defunct weak_ptr
			// references, if you don't want to manually handle them in your
			// function
			void prune();
			
			bool connected(const T& b);

			// update: this->b (new weight)
			void update_weight(const T& b, float weight);

			float get_weight(const T& b) const;

			friend std::ostream& operator<<(std::ostream& out, Vertex& v) {
				v.prune();

				out << v.data;
				for (const auto& edge_pair: v.edges) {
					auto spt = edge_pair.first.lock();
					if (spt) {
						out << "\n  " << spt->data << '<' << edge_pair.second << '>';
					}
				}
				out << '\n';
				return out;
			}
		};

		std::unordered_map<
			T,
			std::shared_ptr<Vertex>,
			Hash,
			KeyEqual
		> vertices;
	public:
		bool add(const T&);
		bool remove(const T&);

		// connects a -> b (with given weight)
		bool connect(const T& a, const T& b, float weight=1);

		// connects a <-> b (with given weight)
		bool connect_bi(const T& a, const T& b, float weight=1);
		
		// update: a->b (new weight)
		bool update_weight(const T& a, const T& b, float weight);

		friend std::ostream& operator<<(std::ostream& out, Graph& g) {
			for (const auto& [key, value]: g.vertices) {
				out << *value;
			}
			return out;
		}

		// Returns shortest path between a and b. If the vector is empty, then
		// the points are disconnected.
		// return format is vector<pair<vertex key, weight>>
		std::vector<std::pair<T, float>> dijkstra(const T& a, const T& b);
};

#include "graph.tpp"
