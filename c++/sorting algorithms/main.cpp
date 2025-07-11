#include "sorts.h"

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string timeit(void (*func)(int[], unsigned), int arr[], unsigned size);
void generate(int arr[], unsigned size);

int main()
{
	const int SIZE = 0xffff;
	int original[SIZE];
	int to_sort[SIZE];

	generate(original, SIZE);

	cout << "running tests for array of size: " << SIZE << endl;

	// NOTE: using a macro function for reflection capabilities
	#define RUN_TEST(ALGO) {\
		copy_arr(to_sort, original, SIZE);\
		cout << #ALGO " sort (" << SIZE << "): " << std::flush;\
		cout << timeit(ALGO, to_sort, SIZE) << endl;\
		if (!is_sorted(to_sort, SIZE)) { cout << "FAILED TO SORT!" << endl; }\
	}

	RUN_TEST(selection);
	RUN_TEST(insertion);
	RUN_TEST(stdsort);
	RUN_TEST(merge);
	RUN_TEST(quick);

	return 0;
}

string timeit(void (*func)(int[], unsigned), int arr[], unsigned size) {
	auto start = chrono::high_resolution_clock::now();
	func(arr, size);
	auto end = chrono::high_resolution_clock::now();
	
	unsigned long long duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	if (duration >= 1e9) {
		return to_string(duration/1e9) + 's';
	}
	else if (duration >= 1e6) {
		return to_string(duration/1e6) + "ms";
	}
	else if (duration >= 1e3) {
		return to_string(duration/1e3) + "μs";
	}
	else {
		return to_string(duration) + "ns";
	}
}


void generate(int arr[], unsigned size) {
	srand(time(NULL));

	int ascending[size];
	for (unsigned i = 0; i < size; ++i) {
		ascending[i] = i;
	}

	for (unsigned i = 0; i < size; ++i) {
		unsigned index = rand() % size;
		do {
			++index;
			if (index == size) { index = 0; }
		} while (ascending[index] == -1);
		arr[i] = ascending[index];
		ascending[index] = -1;
	}
}
