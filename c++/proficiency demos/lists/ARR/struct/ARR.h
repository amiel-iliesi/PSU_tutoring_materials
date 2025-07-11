#pragma once
#include <cstddef>

struct Node {
	int data;
	Node* next;
};

struct ARR {
	Node** array;
	std::size_t size;
};

void build(ARR&);
void destroy(ARR&);
void display(ARR&);
