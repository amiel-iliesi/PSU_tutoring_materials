#include "hybrid.h"
#include "merge.h"
#include "merge_util.h"
#include "insertion.h"

using namespace std;

// this is also called Timsort

void hybrid_sort(vector<int>& v)
{
	if (v.size() <= 1) {
		return;
	}
	else if (v.size() <= 32) {
		insertion_sort(v);
		return;
	}

	auto middle = v.begin() + v.size() / 2;

	vector<int> vl(v.begin(), middle);
	vector<int> vr(middle, v.end());

	merge_sort(vl);
	merge_sort(vr);

	v = merge(vl, vr);
}
