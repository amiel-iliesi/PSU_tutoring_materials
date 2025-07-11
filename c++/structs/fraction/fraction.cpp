#include "fraction.h"
#include <iostream>

using namespace std;

Fraction::Fraction()
{
	numerator = 0;
	denominator = 0;
}

Fraction::Fraction(int n, int d)
{
	if (d == 0) {
		throw DivideByZero();
	}

	numerator = n;
	denominator = d;
}

void Fraction::display() const
{
	cout <<  numerator << '/' << denominator << endl;
}

void Fraction::copy(int n, int d)
{
	numerator = n;
	denominator = d;
}

void Fraction::copy(const Fraction & other)
{
	copy(other.numerator, other.denominator);
}
