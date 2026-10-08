#include <iostream>

using namespace std;

int main()
{
    int size;

    cout << ">>> how many integers to store?: ";
    cin >> size;
    cin.ignore(100, '\n');

    // declare
    int * integers = new int[size];

    // initialize
    for (int i = 0; i < size; ++i) {
        integers[i] = i;
    }

    // display
    cout << '[';
    for (int i = 0; i < size; ++i) {
        cout << integers[i];
        if (i != (size-1)) { // don't put a comma after the last element
            cout << ", ";
        }
    }
    cout << ']' << endl;

    delete [] integers;

    return 0;
}
