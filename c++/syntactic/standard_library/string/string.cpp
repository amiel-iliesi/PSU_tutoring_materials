#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	// first, here's using a char array
	char temp[500];
	cout << "enter a phrase: ";
	cin.getline(temp, 500);
	char * s1 = new char[strlen(temp) + 1];
	strcpy(s1, temp);

	cout << "read in: " << s1 << endl;

	delete [] s1;
	s1 = nullptr;

	// ... and now with a string
	string s2;
	cout << "enter a phrase: ";
	getline(cin, s2);

	cout << "read in: " << s2 << endl;

	return 0;
}
