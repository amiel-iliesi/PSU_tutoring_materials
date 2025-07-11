#include <iostream>

using namespace std;

void greet(const char * name);

int main()
{
    greet("Amiel");

    return 0;
}

void greet(const char * name) {
    cout << "Hello, " << name << '!' << endl;
}