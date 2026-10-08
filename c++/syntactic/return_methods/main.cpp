#include "fraction.h"
#include <iostream>

using namespace std;

int main()
{
	Fraction f1(1,2);

	// function returns info by return value
	Fraction f1_squared_1 = f1.square_by_return();

	// function returns info by parameter
	Fraction f1_squared_2;
	f1.square_by_parameter(f1_squared_2);

	cout << "they should be the same: ";
	f1_squared_1.display();
	cout << ", ";
	f1_squared_2.display();
	cout << endl;

	return 0;
}
