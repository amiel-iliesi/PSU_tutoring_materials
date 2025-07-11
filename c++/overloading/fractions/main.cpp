#include "fraction.h"
#include <iostream>

using namespace std;

int main()
{
	Fraction A(1,2);
	Fraction B(3,7);

	Fraction C = A + B;

	cout << A << " + " << B << " = " << C << endl;

	cout << A << " - " << B << " = " << A - B << endl;

	cout << "-" << B << " = " << -B << endl;

	Fraction D;
	cout << "Enter a fraction (space separated, EG: N D): ";
	cin >> D;

	cout << C << " + " << D << " = " << C + D << endl; 
}
