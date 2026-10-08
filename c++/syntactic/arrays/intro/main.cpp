#include <iostream>

using namespace std;

int main()
{
	int x = 5;

	cout << "x = " << x << endl;
	cout << "&x = " << &x << endl;

	int * x_location = &x;
	cout << "x_location = " << x_location << endl;
	cout << "*x_location = " << *x_location << endl;

	cout << endl;

	int arr_of_numbers[5] = {7, 3, 1, 2, 9};
	cout << "arr_of_numbers = " << arr_of_numbers << endl;
	cout << "*arr_of_numbers = " << *arr_of_numbers << endl;
	cout << "*(arr_of_numbers + 2) = " <<  *(arr_of_numbers + 2) << endl;
	cout << "arr_of_numbers[2] = " << arr_of_numbers[2] << endl;

	// *(address + index) == address[index]
	
	char sentence[1024];
	cout << "enter a sentence: ";
	cin.getline(sentence, 1024);
	cout << "sentence[0] = " << sentence[0] << endl;
	cout << "sentence = " << sentence << endl;
	cout << "&sentence[0] = " << &sentence[0] << endl;
	cout << "&sentence[1] = " << &sentence[1] << endl;

	return 0;
}
