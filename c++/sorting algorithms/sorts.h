#pragma once

// utilities
void copy_arr(int dest[], int src[], unsigned size);
bool is_sorted(int arr[], unsigned size);

// algorithms
void selection(int arr[], unsigned size);
void insertion(int arr[], unsigned size);
void stdsort(int arr[], unsigned size);
void merge(int arr[], unsigned size);
void merge(int arr[], unsigned l, unsigned r);  // recursive func
void quick(int arr[], unsigned size);
void quick(int arr[], int l, int r);
