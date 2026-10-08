#include "fraction.h"
#include <iostream>

using namespace std;

int main()
{
	Fraction A(1,2);
	Fraction B(A);
	Fraction C(3,4);
	C = A;
	Fraction D;
	D = 5;
	D = A;

	A.display();
	B.display();
	C.display();
	D.display();

	return 0;
}
