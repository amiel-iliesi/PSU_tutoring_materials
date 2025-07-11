#include "ARR.h"
#include <iostream>
#include <ctime>

using namespace std;

ARR::Node::Node(int data, Node* next): data(data), next(next) {}

ARR::ARR(size_t arr_size_min,
		size_t arr_size_var,
		size_t list_size_min,
		size_t list_size_var,
		int data_min,
		int data_max)
{
	srand(time(NULL));
	int data_range = (data_max - data_min) + 1;

	size = arr_size_min + (rand() % (arr_size_var + 1));
	array = new Node*[size];
	for (size_t i = 0; i < size; ++i) {
		array[i] = nullptr;
	}

	for (size_t i = 0; i < size; ++i) {
		size_t list_size = list_size_min + (rand() % (list_size_var + 1));
		for (size_t _ = 0; _ < list_size; ++_) {
			array[i] = new Node((rand() % data_range) + data_min, array[i]);
		}
	}
}

ARR::~ARR()
{
	for (size_t i = 0; i < size; ++i) {
		while (array[i]) {
			Node* to_delete = array[i];
			array[i] = array[i]->next;
			delete to_delete;
		}
	}

	delete [] array;
	size = 0;
}

void ARR::display() const
{
	cout << "-array--------------------------------------------\n";
	for (size_t i = 0; i < size; ++i) {
		for (Node* curr = array[i]; curr; curr=curr->next) {
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
