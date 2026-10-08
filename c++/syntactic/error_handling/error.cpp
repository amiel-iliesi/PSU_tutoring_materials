#include <iostream>
#include "error.h"

using namespace std;

float divide_with_handling(float a, float b)
{
	if (b == 0.0) {
		divideByZeroError.numerator = a;
		throw (divideByZeroError);
	}

	//NOTE: uncomment to introduce a previously uncaught error type
	if (a == 5.0) {
		throw (randomDivisionError);
	}

	return a / b;
}

float divide(float a, float b)
{
	try {
		return divide_with_handling(a, b);
	}
	
	//NOTE: uncomment to see a error info packaged with the error object
	catch (DivideByZeroError errorObj) {
		cerr << "\nERROR: divide by zero, aborting" << endl;
		abort();
	}

	catch (...) {
		cerr << "\nUnknown error caught in divide, aborting..."
			 << endl;
		abort();
	}
}

int main()
{
	const float A = 5.0f;
	const float B = 0.0f;
	cout << A << " / " << B << " = " << divide(A, B) << endl;
	return 0;
}
