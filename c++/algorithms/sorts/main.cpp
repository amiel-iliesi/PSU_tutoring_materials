#include "bubble.h"
#include "insertion.h"
#include "merge.h"

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>
#include <functional>

using namespace std;

// - helper function prototypes -------------------------------
bool is_sorted(const vector<int>&);
void display(const vector<int>&);
chrono::microseconds time(vector<int>&, function<void(vector<int>&)>);
void run(vector<int>&, const string&, function<void(vector<int>&)>);




int main()
{
	// - get our random number stuff set up -----------------------
	random_device rd;
	mt19937 gen(rd());
	
	// - shuffle an ascending vector from [0, SIZE) ---------------
	int SIZE = 512 + gen() % 512;

	vector<int> shuffled_vector;
	shuffled_vector.reserve(SIZE);
	
	for (int i=0; i < SIZE; ++i) {
		shuffled_vector.push_back(i);
	}

	ranges::shuffle(shuffled_vector, gen);

	// - calls begin here -----------------------------------------
	vector<int> v = shuffled_vector;

	cout << "vector size is " << v.size() << endl;

	cout << '\n';

	cout << "running sorts:\n--------------" << endl;

	// put sorts to be called here:
	vector<pair<string, function<void(vector<int>&)>>> to_run = {
		{"std::sort", ranges::sort},
		{"bubble sort", bubble_sort},
		{"insertion sort", insertion_sort},
		{"merge sort", merge_sort}
	};

	for (auto &[name, func]: to_run) {
		run(v, name, func);
		v = shuffled_vector; //reset v for next run
	}

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

chrono::microseconds time(vector<int>& v, function<void(vector<int>&)> f)
{
	chrono::high_resolution_clock clock;

	auto t1 = clock.now();
	f(v);
	auto t2 = clock.now();

	return duration_cast<chrono::microseconds>(t2 - t1);
}

void run(vector<int>& v, const string& f_name, function<void(vector<int>&)> f)
{
	chrono::microseconds runtime = time(v, f);
	
	if (is_sorted(v)) {
		cout << "[✓] " << f_name << ":"
			 << setw(21 - f_name.length()) << runtime << endl;
	}
	else { // if it's not sorted correctly, don't bother displaying the time
		cout << "[✗] " << f_name << endl;
	}

}
