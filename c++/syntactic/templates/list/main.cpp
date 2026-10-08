#include "list.h"
#include <iostream>

using namespace std;

int main()
{
	List<int> ints;
	for (int i: {1, 3, 2, 5, 7, 1, 4}) {
		ints.insert(i);
	}
	cout << ints << endl;

	List<char> chars;
	for (char c: {'a','s','b','r','z','y','n','l'}) {
		chars.insert(c);
	}
	cout << chars << endl;

	return 0;
}
