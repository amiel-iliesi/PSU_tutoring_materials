#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> numbers;
	for (int i = 0; i < 3; ++i) {
		int x;
		cout << ">>> (" << i+1 << "/3): ";
		cin >> x;
		cin.ignore(100, '\n');
		numbers.push_back(x);
	}

	cout << "you stored: ";
	for (int x: numbers) {
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}
