#pragma once

template <typename TYPE>
class Fraction {
	private:
		TYPE numerator;
		TYPE denominator;
	public:
		Fraction(const TYPE & new_numerator, const TYPE & new_denominator);

		void display();
};

// NOTE: include your template implementation at the bottom of your header!
#include "fraction.tpp" 
