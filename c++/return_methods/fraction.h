#pragma once

class Fraction {
	private:
		int numerator;
		int denominator;
	public:
		Fraction(int n = 0,int d = 0): numerator(n), denominator(d) {}

		void display() const;

		void square_by_parameter(Fraction &);
		Fraction square_by_return() const;
};
