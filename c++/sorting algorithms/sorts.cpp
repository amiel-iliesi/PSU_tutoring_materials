#include "sorts.h"
#include <algorithm>

// ---------------------------------UTILITIES--------------------------------------
void copy_arr(int dest[], int src[], unsigned size)
{
	if (&dest == &src) { return; }

	for (unsigned i = 0; i < size; ++i) {
		dest[i] = src[i];
	}
}

bool is_sorted(int arr[], unsigned size)
{
	for (unsigned i = 0; i < size-1; ++i) {
		if (arr[i] > arr[i+1]) {
			return false;
		}
	}

	return true;
}

// -------------------------------ALGORITHMS---------------------------------------
void selection(int arr[], unsigned size)
{
	if (size <= 1) { return; }

	for (unsigned i = 0; i < size-1; ++i) {
		int min = i;
		for (unsigned j = i+1; j < size; ++j) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}

		std::swap(arr[i], arr[min]);
	}
}

void insertion(int arr[], unsigned size)
{
	int original[size];
	copy_arr(original, arr, size);

	for (unsigned i = 1; i < size; ++i) {
		for (unsigned j = 0; j < i; ++j) {
			if (original[i] < arr[j]) {
				//we need to move the values ahead so we can insert
				for (unsigned k = i; k > j; --k) {
					arr[k] = arr[k-1];
				}

				arr[j] = original[i]; // place it in newly made space
				break;
			}
		}
	}
}

void stdsort(int arr[], unsigned size)
{
	std::sort(arr, arr+size);
}

void merge(int arr[], unsigned size)
{
	merge(arr, 0, size-1);
}

void merge(int arr[], unsigned l, unsigned r)
{
	if (l >= r) { return; }

	unsigned middle = (l+r)/2;

	if (l < middle)
		merge(arr, l, middle);
	
	if (middle < r)
		merge(arr, middle+1, r);

	unsigned li = l;
	unsigned ri = middle+1;

	unsigned range = (r - l) + 1;
	int temp[range];
	unsigned temp_top = 0;
	while (li <= middle and ri <= r) {
		if (arr[li] <= arr[ri]) {
			temp[temp_top++] = arr[li++];
		}
		else {
			temp[temp_top++] = arr[ri++];
		}
	}

	while (li <= middle) {
		temp[temp_top++] = arr[li++];
	}

	while (ri <= r) {
		temp[temp_top++] = arr[ri++];
	}

	for (unsigned i = 0; i < range; ++i) {
		arr[l+i] = temp[i];
	}
}

void quick(int arr[], unsigned size)
{
	quick(arr, 0, size-1);
}

void quick(int arr[], int l, int r)
{
	// 0. base case: 0 or 1 elements
	if (l >= r) { return; }
	//    base case: 2 elements
	else if (r - l == 1) {
		if (arr[l] > arr[r]) {
			std::swap(arr[l], arr[r]);
		}
		return;
	}

	// 1. select appropriate pivot, using "median of three"
	int pivot = r;
	if (r - l >= 2) {
		int min = l;
		int max = r;
		int median = l + ((r-l)/2);

		if (arr[min] > arr[max]) {
			std::swap(arr[min], arr[max]);
		}
		if (arr[min] > arr[median]) {
			std::swap(arr[min], arr[median]);
		}
		if (arr[median] > arr[max]) {
			std::swap(arr[median], arr[max]);
		}

		pivot = median;
		
		// 2. put the pivot on the right side
		std::swap(arr[pivot], arr[r]);
		pivot = r;
	}


	// 3. find violations and swap
	int min_gt_pivot = pivot;
	int li = l;
	int ri = r-1;
	while (li < ri) {
		while (li < ri and arr[li] <= arr[pivot]) {
			++li;
		}
		while (ri > li and arr[ri] >= arr[pivot]) {
			--ri;
		}

		std::swap(arr[li], arr[ri]);

		min_gt_pivot = ri;
	}

	// 4. move pivot back into the array where it goes
	std::swap(arr[pivot], arr[min_gt_pivot]);
	pivot = min_gt_pivot;

	// 5. recurse on portions surrounding pivot
	if (pivot > l)
		quick(arr, l, pivot-1);
	
	if (pivot < r)
		quick(arr, pivot+1, r);
}
