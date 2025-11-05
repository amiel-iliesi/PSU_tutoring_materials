#include "list.h"
#include <random>

using namespace std;

int main()
{
	List list;

	random_device rd;

	for (int i = 8 + rd() % 8; i >= 0; --i) {
		list.push(rd() % 10);
	}
	list.display();

	// -custom function calls here---------------------------------
	// ------------------------------------------------------------

	return 0;
}
