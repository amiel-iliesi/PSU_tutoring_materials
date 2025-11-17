#include "insertion.h"

#include <iterator>

using namespace std;

void insertion_sort(std::vector<int>& v)
{
	if (v.size() < 2) {
		return;
	}

	for (auto r = v.begin() + 1; r != v.end(); ++r) {
		for (auto l = make_reverse_iterator(r); l != v.rend(); ++l) {
			if (*l > *(l-1)) {
				swap(*l, *(l-1));
			}
			else {
				break;
			}
		}
	}
}
