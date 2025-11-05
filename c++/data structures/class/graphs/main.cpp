#include "graph.h"
#include <random>
#include <iostream>

using namespace std;

// NOTE: change these
const int MIN_SIZE = 5;
const int SIZE_VAR = 5;
const int CONNECTIONS_MIN = 0;
const int CONNECTIONS_VAR = 4;
const bool ALLOW_SELF_CONNECTIONS = false;
const bool BIDIRECTIONAL = true;

constexpr int MAX_CONNECTIONS = CONNECTIONS_MIN + CONNECTIONS_VAR;

int main()
{
	Graph graph;

	random_device rd;

	const int SIZE = MIN_SIZE + rd() % SIZE_VAR;

	// make vertices
	for (int i = 0; i < SIZE; ++i) {
		graph.push(i);
	}

	// add edges
	for (int i = 0; i < SIZE; ++i) {
		int N = (CONNECTIONS_MIN + rd() % CONNECTIONS_VAR) - graph.connections(i);

		for (int j = 0; j < N; ++j) {
			bool connected = false;
			do {
				int connect_dest = rd() % SIZE;
				if ((not ALLOW_SELF_CONNECTIONS) and (i == connect_dest)) {
					continue;
				}
				else if (graph.connections(connect_dest) == MAX_CONNECTIONS) {
					continue;
				}

				connected = graph.connect(i, connect_dest);
				if (BIDIRECTIONAL) {
					graph.connect(connect_dest, i);
				}
			} while (not connected);
		}
	}

	graph.display(true);

	// -put custom function calls here-----------------------------
	// ------------------------------------------------------------

	return 0;
}
