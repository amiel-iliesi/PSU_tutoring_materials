#include "fraction.h"
#include <iostream>

using namespace std;

Fraction::Fraction(): numerator(0), denominator(0)
{
	cout << "default constructor called" << endl;
}

Fraction::Fraction(int n, int d): numerator(n), denominator(d)
{
	cout << "parameterized constructor called" << endl;
}

void Fraction::copy(const Fraction & other)
{
	cout << "ran copy(...)" << endl;
	numerator = other.numerator;
	denominator = other.denominator;
}

Fraction::Fraction(const Fraction & other)
{
	cout << "copy constructor called" << endl;
	copy(other);
}

Fraction::~Fraction()
{
	cout << "ran destructor" << endl;
}

void Fraction::operator=(const Fraction & other)
{
	cout << "running assignment operator" << endl;
	// simulating deleting dynamic data by setting to zero
	numerator = 0;
	denominator = 0;

	copy(other);
}

void Fraction::operator=(int n)
{
	cout << "running custom assignment operator" << endl;

	// simulating deleting dynamic data by setting to zero
	numerator = 0;
	denominator = 0;

	numerator = n;
	denominator = 1;
}

void Fraction::display() const
{
	cout << numerator << '/' << denominator << endl;
}
