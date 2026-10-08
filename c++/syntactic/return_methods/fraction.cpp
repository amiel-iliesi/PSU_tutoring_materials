#include "fraction.h"
#include <iostream>

using namespace std;

void Fraction::display() const
{
	cout << numerator << '/' << denominator;
}

void Fraction::square_by_parameter(Fraction & dest)
{
	dest.numerator = numerator * numerator;
	dest.denominator = denominator * denominator;
}

Fraction Fraction::square_by_return() const
{
	int n_squared = numerator * numerator;
	int d_squared = denominator * denominator;

	Fraction new_fraction = Fraction(n_squared, d_squared);
	/* if you have a copy function, this is the same as above:
	Fraction new_fraction;
	new_fraction.copy(*this); */

	return new_fraction;
}
