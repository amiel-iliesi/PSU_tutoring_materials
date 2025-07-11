#include "fraction.h"
#include <exception>

using namespace std;

Fraction::Fraction(): Fraction(1, 1) {}

Fraction::Fraction(int n, int d): numerator(n), denominator(d)
{
	if (denominator == 0) {
		throw domain_error("denominator cannot be zero");
	}

	// normalize negative sign
	else if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	}

	reduce();
}

//https://en.wikipedia.org/wiki/Euclidean_algorithm
void Fraction::reduce()
{
	if (numerator == 0) {
		denominator = 1;
		return;
	}

	int n = (numerator < 0 ? -numerator : numerator);
	int d = (denominator < 0 ? -denominator : denominator);
	int gcd = (n < d ? n : d);
	int x = (n > d ? n : d);

	while (x % gcd != 0) {
		x %= gcd;

		int swap = x;
		x = gcd;
		gcd = swap;
	}

	numerator /= gcd;
	denominator /= gcd;
}

ostream& operator<<(ostream & out, const Fraction & fraction)
{
	out << fraction.numerator << '/' << fraction.denominator;
	return out;
}

istream& operator>>(istream & in, Fraction & fraction)
{
	in >> fraction.numerator >> fraction.denominator;
	in.ignore(100, '\n');

	if (fraction.denominator == 0) {
		throw domain_error("denominator cannot be zero");
	}

	fraction.reduce();
	return in;
}

Fraction Fraction::operator+(const Fraction & other) const
{
	int n = this->numerator * other.denominator + other.numerator * this->denominator;
	int d = this->denominator * other.denominator;

	Fraction result(n, d);
	result.reduce();

	return result;
}

Fraction Fraction::operator-() const
{
	return Fraction(-(this->numerator), this->denominator);
}

Fraction Fraction::operator-(const Fraction & other) const
{
	return *this + -other; // we can use our other overloads in this one!
}
