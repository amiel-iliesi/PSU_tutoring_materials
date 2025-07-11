#include "functions.h"

using namespace std;

int main()
{
	int * my_ints = make_array(10);
	delete [] my_ints;
	return 0;
}
