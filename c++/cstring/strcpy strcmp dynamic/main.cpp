#include <cstring>
#include <iostream>

using namespace std;

const int BUF_SIZE = 1024;

/* PROBLEM: read 2 strings, and compare them */

int main()
{
    char temp[BUF_SIZE];

    cout << ">>> string A: ";
    cin.getline(temp, BUF_SIZE);

    char * string_a = new char[strlen(temp) + 1];
    strcpy(string_a, temp);

    cout << ">>> string B: ";
    cin.getline(temp, BUF_SIZE);

    char * string_b = new char[strlen(temp) + 1];
    strcpy(string_b, temp);

    int result = strcmp(string_a, string_b);

    if (result < 0) {
        cout << string_a << " < " << string_b << endl;
    }
    else if (result > 0) {
        cout << string_a << " > " << string_b << endl;
    }
    else { // result == 0
        cout << string_a << " == " << string_b << endl;
    }

    delete [] string_a;
    delete [] string_b;
   
    return 0;
}
