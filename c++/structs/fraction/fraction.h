#pragma once

class Fraction
{
	public:
		Fraction();
		Fraction(int, int);

		void display() const;

		void copy(int, int);
		void copy(const Fraction &);
	private:
		int numerator;
		int denominator;
};

struct DivideByZero {};
