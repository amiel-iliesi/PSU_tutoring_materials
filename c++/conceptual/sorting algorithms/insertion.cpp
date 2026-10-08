#include "insertion.h"

#include <iterator>

using namespace std;

void insertion_sort(std::vector<int>& v)
{
	if (v.size() < 2) {
		return;
	}

	for (int r = 1; r < (int)v.size(); ++r) {
		for (int l = r-1; l >= 0; --l) {
			if (v[l] > v[l+1]) {
				swap(v[l], v[l+1]);
			}
			else {
				break;
			}
		}
	}
}
