#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    // for loop
    int sum = 0;

    for (int i = 10; i < 101; i += 5) {
        sum += i;
    }

    cout << "10 + 15 + 20 + ... + 100 = " << sum << endl;

    // while loop; lets find the first capital letter
    const char * word = "abcEFgHIj";
    int i = 0;
    while (i < strlen(word) && !isupper(word[i])) {
        ++i;
    }

    if (word[i] != '\0')
        cout << "the first capital letter of \"" << word << "\" is '"
             << word[i] << "'." << endl;
    else
        cout << word << " contains no capital letters." << endl;


    // if, else if, else
    char choice = 'b';

    if (choice == 'a')
        cout << "choice 1" << endl;
    else if (choice == 'b')
        cout << "choice 2" << endl;
    else
        cout << "other choice" << endl;

    return 0;
}