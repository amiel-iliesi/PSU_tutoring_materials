#include "prime.h"
#include <iostream>

using namespace std;

int main()
{
	int arr[5];

	cout << "enter " << 5 << " numbers...\n";

	for (int i = 0; i < 5; ++i) {
	cout << ">>> ";
	cin >> arr[i];
	}
	cin.ignore(100,'\n');
	
	
	int p[5];
	unsigned j = 0;
	for (int i = 0; i < 5; ++i) {
	bool x = true;
	if (arr[i] <= 1) { x = false; }
	


	for (int k = 2; (k * k) <= arr[i]; ++k) {
		if (arr[i] % k == 0) {
			x = false;
		}
	}
	if (x) {
		p[j++] = arr[i];
	}
	}






	cout << "primes: ";
	
	if (j) {
		int x = 0;
	for (unsigned i = 0; i < (j-1); ++i) {
		cout << p[i] << ", ";
	}
	cout << p[j-1] << endl;

	for (unsigned i = 0; i < j; ++i) {
		x += p[i];
	}
	cout << "sum of primes: " << x << endl;
	}
	else {
		cout << "[NONE]" << endl;
	}
}
