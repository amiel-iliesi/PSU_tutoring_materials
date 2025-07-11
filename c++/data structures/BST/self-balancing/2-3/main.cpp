#include "tree.h"
#include <iostream>

using namespace std;

int main()
{
//	Tree ints;
//	for (const int &i: {5,2,6,9,4,10,1,3,7,8}) {
//		ints.insert(i);
//	}
//	ints.display();
//
//	cout << "\n\n";

	Tree random_ints;
	random_ints.build(0,99,30,false);
	random_ints.display();
	cout << "There *is" << (random_ints.contains(50) ? "* " : " not* ")
		 << "a 50 in the tree." << endl;

	return 0;
}
