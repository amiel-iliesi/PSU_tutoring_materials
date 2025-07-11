#include "ARR.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// NOTE: you won't be able to see these implementations during the demos!

void build(ARR& arr)
{
	srand(time(NULL));

	const size_t ARR_SIZE_MIN = 3;
	const size_t ARR_SIZE_VAR = 2;
	const size_t LIST_SIZE_MIN = 5;
	const size_t LIST_SIZE_VAR = 10;
	const size_t DATA_MIN = 0;
	const size_t DATA_MAX = 9;
	
	const size_t data_range = (DATA_MAX - DATA_MIN) + 1;

	arr.size = ARR_SIZE_MIN + (rand() % (ARR_SIZE_VAR + 1));
	arr.array = new Node*[arr.size];

	for (size_t i=0; i < arr.size; ++i) {
		arr.array[i] = nullptr;
	}

	for (size_t i=0; i < arr.size; ++i) {
		size_t list_size = LIST_SIZE_MIN + (rand() % (LIST_SIZE_VAR + 1));
		
		for (size_t _=0; _ < list_size; ++_) {
			Node* new_node = new Node;
			new_node->data = (rand() % data_range) + DATA_MIN;
			new_node->next = arr.array[i];
			arr.array[i] = new_node;
		}
	}
}

void destroy(ARR& arr)
{
	for (size_t i=0; i < arr.size; ++i) {
		while (arr.array[i]) {
			Node* to_delete = arr.array[i];
			arr.array[i] = arr.array[i]->next;
			delete to_delete;
		}
	}

	delete[] arr.array;

	arr.array = nullptr;
	arr.size = 0;
}

void display(ARR& arr)
{
	cout << "-displaying array---------------------------------\n";
	for (size_t i=0; i < arr.size; ++i) {
		for (const Node* curr=arr.array[i]; curr; curr=curr->next) {
			cout << curr->data;
			if (curr->next) {
				cout << " -> ";
			}
			else {
				cout << endl;
			}
		}
	}
	cout << "--------------------------------------------------\n";
}
