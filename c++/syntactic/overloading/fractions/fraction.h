#pragma once
#include <iostream>

class Fraction {
	private:
		int numerator;
		int denominator;

		void reduce();
	
	public:
		Fraction();
		Fraction(int n, int d);

		// you can overload iostream operators
		friend std::ostream& operator<<(std::ostream & out, const Fraction & fraction);
		friend std::istream& operator>>(std::istream & in, Fraction & fraction);

		// and you can make your own overloaded operators
		Fraction operator+(const Fraction & other) const;
		Fraction operator-(const Fraction & other) const;
		Fraction operator-() const;
};
