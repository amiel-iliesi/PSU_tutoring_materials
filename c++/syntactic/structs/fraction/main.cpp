#include "fraction.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	int d;

	cout << ">>> enter a numerator: ";
	cin >> n;
	cin.ignore(100, '\n');

	cout << ">>> enter a denominator: ";
	cin >> d;
	cin.ignore(100, '\n');

	try {
		Fraction f(n,d);
		cout << "you have entered ";
		f.display();
	}
	catch (DivideByZero) {
		cerr << "cannot construct a fraction, denominator is zero!" << endl;
	}

	return 0;
}
