#include "classes.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "constructing an A object..." << endl;
	A obj1("obj1_str1");
	obj1.display();

	cout << endl;

	cout << "constructing a B object..." << endl;
	B obj2("obj2_str1", "obj2_str2");
	obj2.display();

	cout << endl;

	cout << "constructing a B object (by copy)..." << endl;
	B obj3(obj2);
	obj3.display();

	cout << endl;

	cout << "constructing a C object..." << endl;
	C obj4("obj4_str1", "obj4_str2");
	obj4.display();

	cout << endl;

	cout << "constructing a C object (by copy)..." << endl;
	C obj5(obj4);
	obj5.display();

	return 0;
}
