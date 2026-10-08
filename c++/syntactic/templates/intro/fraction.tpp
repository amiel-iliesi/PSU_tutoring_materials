// NOTE: don't include header in template files!

#include <iostream>

template <typename TYPE>
Fraction<TYPE>::Fraction(const TYPE & new_numerator, const TYPE & new_denominator)
{
	numerator = new_numerator;
	denominator = new_denominator;
}

template <typename TYPE>
void Fraction<TYPE>::display()
{
	std::cout << numerator << " / " << denominator;
}
