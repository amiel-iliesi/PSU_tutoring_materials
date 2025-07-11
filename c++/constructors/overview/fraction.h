#pragma once

class Fraction
{
	private:
		int numerator;
		int denominator;

		void copy(const Fraction &);
	
	public:
		Fraction();
		Fraction(int, int);
		Fraction(const Fraction &);
		~Fraction();
		void operator=(const Fraction &);
		void operator=(int);

		void display() const;
};
