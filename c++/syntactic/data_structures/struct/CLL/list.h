#pragma once

struct Node
{
	int data;
	Node* next;
};

// -predefined functions---------------------------------------
// NOTE: the implementation for these are normally hidden from you
void build(Node*& rear);
void destroy(Node*& rear);
void display(const Node* rear);
// ------------------------------------------------------------
