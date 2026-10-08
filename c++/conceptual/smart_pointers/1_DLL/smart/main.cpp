#include "list.h"
#include <iostream>
#include <random>

using namespace std;

int main()
{
	random_device rd;
	default_random_engine gen(rd());

	List list;

	const int LIST_SIZE = 10 + gen() % 10;

	for (int i = 0; i < LIST_SIZE; ++i) {
		list.insert(gen() % LIST_SIZE);
	}

	list.display();

	return 0;
}
