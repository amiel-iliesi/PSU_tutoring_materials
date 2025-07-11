#include <iostream>

using namespace std;

int main() {
	int x = 0;

	do {
		x--;
	} while (x > 0);

	//x == -1, loop ran once
	cout << "x = " << x << endl;
}
