#pragma once

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

// -predefined functions---------------------------------------
// NOTE: the implementation for these are normally hidden from you
void build(Node*& head);
void destroy(Node*& head);
void display(const Node* head);
// ------------------------------------------------------------

// -custom functions go here-----------------------------------
bool swap(Node* A, Node* B, Node*& head);
// ------------------------------------------------------------
