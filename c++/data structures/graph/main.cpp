#include "graph.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	Graph<string> graph;

	for (string s: {"a", "b", "c", "d", "e", "f"}) {
		graph.add(s);
	}
	graph.connect_bi("a", "b", 14);
	graph.connect_bi("a", "c", 9);
	graph.connect_bi("a", "d", 7);
	graph.connect_bi("b", "c", 2);
	graph.connect_bi("b", "e", 9);
	graph.connect_bi("c", "d", 10);
	graph.connect_bi("c", "f", 11);
	graph.connect_bi("d", "f", 15);
	graph.connect_bi("e", "f", 6);

	cout << "connections:\n------------\n";
	cout << graph;

	cout << "\nfastest path from a->e:\n-----------------------\n";
	vector<pair<string, float>> path = graph.dijkstra("a", "e");
	for (unsigned long i = 0; i < (path.size() - 1); ++i) {
		cout << '(' << path[i+1].second << "): " << path[i].first << " -> "
			 << path[i+1].first << '\n';
	}
	return 0;
}
