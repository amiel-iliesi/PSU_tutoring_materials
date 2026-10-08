#include "fraction.h"
#include <iostream>

using namespace std;

int main()
{
	Fraction<int> int_frac(1,2);
	cout << "my int fraction: ";
	int_frac.display();
	cout << endl;


	Fraction<float> float_frac(3.14159265359, 2.0);
	cout << "my float fraction: ";
	float_frac.display();
	cout << endl;

	return 0;
}
