#include "prime.h"
#include <iostream>

using namespace std;

const int NUMS = 5;

int main()
{
	int numbers[NUMS];

	cout << "enter " << NUMS << " numbers...\n";

	// get numbers from user
	for (int i = 0; i < NUMS; ++i) {
		cout << ">>> ";
		cin >> numbers[i];
	}
	cin.ignore(100,'\n'); // ignore trailing newline from `cin >> ...` operator
	
	// find out which numbers were prime
	int primes[NUMS];
	unsigned primes_top = 0;
	for (int i = 0; i < NUMS; ++i) {
		if (isPrime(numbers[i])) {
			primes[primes_top++] = numbers[i];
		}
	}

	// and output them, and their info
	cout << "primes: ";
	if (primes_top) {
		int primes_sum = 0;
		for (unsigned i = 0; i < (primes_top-1); ++i) {
			cout << primes[i] << ", ";
		}
		cout << primes[primes_top-1] << endl;

		for (unsigned i = 0; i < primes_top; ++i) {
			primes_sum += primes[i];
		}
		cout << "sum of primes: " << primes_sum << endl;
	}
	else {
		cout << "[NONE]" << endl;
	}
}
