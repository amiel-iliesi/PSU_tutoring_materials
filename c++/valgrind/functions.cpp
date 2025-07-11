#include "functions.h"

int * make_array(size_t n)
{
	if (n > 0) {
		int * temp = new int[n]; // oops
		return new int[n];
	}
	else {
		return nullptr;
	}
}
