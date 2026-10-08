#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
	FractionList my_list_of_fractions;
	my_list_of_fractions.add(5, 3);
	my_list_of_fractions.add(2, 2);
	my_list_of_fractions.display();
	return 0;
}
