#include "list.h"
#include <random>

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
	// ------------------------------------------------------------

	return 0;
}
