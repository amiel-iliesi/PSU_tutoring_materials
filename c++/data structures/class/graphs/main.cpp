#include "graph.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	Graph graph;

	while (true) {
		cout << "new place: ";
		string name;
		getline(cin, name);

		if (name.empty()) {
			break;
		}

		if (graph.add_place(name)) {
			cout << "add success: " << name << endl;
		}
		else {
			cout << "*** add fail: " << name << endl;
		}
	}

	while (true) {
		cout << "connect: ";
		string A;
		getline(cin, A);

		if (A.empty()) {
			break;
		}

		cout << A << " -> ";
		string B;
		getline(cin, B);

		if (B.empty()) {
			break;
		}

		if (graph.connect_places(A, B)) {
			cout << "connect success: " << A << " -> " << B << endl;
		}
		else {
			cout << "*** connect fail: " << A << " -> " << B << endl;
		}
	}

	cout << "\ngraph contents:\n---------------\n";
	graph.display();
	cout << "---------------\n";

	return 0;
}

