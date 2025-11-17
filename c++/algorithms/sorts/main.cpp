#include "bubble.h"
#include "insertion.h"

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

using namespace std;

// - helper function prototypes -------------------------------
bool is_sorted(const vector<int>&);
void display(const vector<int>&);




int main()
{
	// - get our random number stuff set up -----------------------
	random_device rd;
	mt19937 gen(rd());
	
	// - shuffle an ascending vector from [0, SIZE) ---------------
	int SIZE = 16 + gen() % 8;

	vector<int> shuffled_vector;
	shuffled_vector.reserve(SIZE);
	
	for (int i=0; i < SIZE; ++i) {
		shuffled_vector.push_back(i);
	}

	ranges::shuffle(shuffled_vector, gen);

	// - calls begin here -----------------------------------------
	vector<int> v = shuffled_vector;

	cout << "initial vector:" << endl;
	display(v);

	cout << '\n';

	bubble_sort(v);
	cout << "bubble sort: " << (is_sorted(v) ? "✓" : "✗") << endl;
	v = shuffled_vector;

	insertion_sort(v);
	cout << "insertion sort: " << (is_sorted(v) ? "✓" : "✗") << endl;
	v = shuffled_vector;

	return 0;
}




// - some helper functions ------------------------------------
bool is_sorted(const vector<int>& v)
{
	if (v.size() < 2) {
		return true;
	}

	for (auto i = v.begin(); i+1 != v.end(); ++i) {
		if (*i > *(i+1)) {
			return false;
		}
	}

	return true;
}

void display(const vector<int>& v)
{
	if (v.size() == 0) {
		return;
	}

	cout << '[' << (is_sorted(v) ? "✓" : "✗") << "]: " << v[0];

	for (auto i = v.begin() + 1; i != v.end(); ++i) {
		cout << ", " << *i;
	}

	cout << endl;
}
