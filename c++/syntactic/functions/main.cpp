#include <iostream>
#include "functions.h"

using namespace std;

/*
[TYPE] function_name (parameter_list) {
	// function
	// body

	return value;
}
*/

int main() {
	// add 3 integers and print that out to the user
	int w = 5;
	int x = 3;
	int y = 2;
	int z = 7;
	int sum;

	sum = x + y + z;

	cout << "w = " << w << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "z = " << z << endl;
	cout << '\n';

	cout << "the sum of x, y, z is " << sum << endl;
	cout << "the sum of x, x, x is " << sum_3(x,x,x) << endl;

	return 0;
}
