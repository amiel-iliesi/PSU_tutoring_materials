#pragma once

struct Node {
	int data;
	Node* next;
};

// these functions will normally be hidden from you for
// the demo
void build(Node*&);
void destroy(Node*&);
void display(const Node*);
