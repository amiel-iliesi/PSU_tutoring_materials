#include "list.h"
#include <random>
#include <print>

using namespace std;

int main()
{
	List list;

	random_device rd;
	default_random_engine gen(rd());

	for (int i = 8 + gen() % 8; i >= 0; --i) {
		list.push(gen() % 10);
	}
	list.display();

	// -custom function calls here---------------------------------
	int sum_removed = list.remove2Largest();
	println("removing 2 largest elements from the list "
			"for a sum of {}", sum_removed);
	list.display();
	// ------------------------------------------------------------

	return 0;
}
