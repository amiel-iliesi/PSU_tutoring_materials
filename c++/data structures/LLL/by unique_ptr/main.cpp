#include "list.h"
#include <iostream>

using namespace std;

int main()
{
	List intList;
	intList.build(10, 1, 5);

	intList.display();

	return 0;
}
