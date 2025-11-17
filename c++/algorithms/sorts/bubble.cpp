#include "bubble.h"

using namespace std;

void bubble_sort(vector<int>& v)
{
	if (v.size() < 2) {
		return;
	}

	bool swapped;

	do {
		swapped = false;

		for (int i = 0; i+1 != (int)v.size(); ++i) {
			if (v[i] > v[i+1]) {
				swap(v[i], v[i+1]);
				swapped = true;
			}
		}
	} while (swapped);
}
