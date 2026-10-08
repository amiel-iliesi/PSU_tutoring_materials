#pragma once

struct Node
{
	int data;
	Node* next;
};

// -predefined functions---------------------------------------
// NOTE: the implementation for these are normally hidden from you
void build(Node*& head);
void destroy(Node*& head);
void display(const Node* head);
// ------------------------------------------------------------
