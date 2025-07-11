#include <iostream>

using namespace std;

bool is_prime(int n);
void set_primes(int * primes, int size);

int main()
{
    int max_prime;
    cout << "generate primes up to: ";
    cin >> max_prime;
    cin.ignore(100, '\n');

    int * primes = new int[max_prime];

    // if primes[i] is 0, it is *not* prime
    set_primes(primes, max_prime);

    for (int i = 0; i < max_prime; ++i) {
        if (primes[i] != 0) {
            cout << primes[i] << ' ';
        }
    }
    cout << endl;

    delete primes;  // NOTE: we don't do anything like this in Python at all!
    primes = nullptr;

    return 0;
}

bool is_prime(int n) {
    if (n < 2) { return false; }

    for (int i = 2; i < n; ++i) {
        if (n % i == 0) { return false; }
    }

    return true;
}

void set_primes(int * primes, int size) {
    for (int i = 0; i < size; ++i) {
        if (is_prime(i))
            primes[i] = i;
        else
            primes[i] = 0;
    }
}