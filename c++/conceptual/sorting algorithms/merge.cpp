#include "merge.h"
#include "merge_util.h"

#include <vector>

using namespace std;

void merge_sort(vector<int>& v)
{
	if (v.size() <= 1) {
		return;
	}

	auto middle = v.begin() + v.size() / 2;

	vector<int> vl(v.begin(), middle);
	vector<int> vr(middle, v.end());

	merge_sort(vl);
	merge_sort(vr);

	v = merge(vl, vr);
}

vector<int> merge(const vector<int>& vl, const vector<int>& vr)
{
	auto vl_it = vl.begin();
	auto vr_it = vr.begin();

	vector<int> v;
	v.reserve(vl.size() + vr.size());

	while (vl_it != vl.end() and vr_it != vr.end()) {
		if (*vl_it < *vr_it) {
			v.push_back(*(vl_it++));
		}
		else {
			v.push_back(*(vr_it++));
		}
	}

	while (vl_it != vl.end()) {
		v.push_back(*(vl_it++));
	}

	while (vr_it != vr.end()) {
		v.push_back(*(vr_it++));
	}

	return v;
}
