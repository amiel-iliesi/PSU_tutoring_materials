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

		for (auto i = v.begin(); i+1 != v.end(); ++i) {
			if (*(i+1) < *i) {
				swap(*i, *(i+1));
				swapped = true;
			}
		}
	} while (swapped);
}
