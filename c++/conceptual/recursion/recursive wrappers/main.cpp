#include <iostream>

using namespace std;

struct node {
	int data;
	node * next;
};

void destroy(node *&);
void insert(node *&, int);
void display_wrapper(const node *);
void display_recursive(const node *);



int main()
{
	node * head = nullptr;

	for (int i: {1, 2, 3, 4, 5, 6})
		insert(head, i);

	display_wrapper(head);

	destroy(head);

	return 0;
}



// 1 -> 2 -> 3 -> 4 -> 5
void destroy(node *& curr) {
	if (curr) {
		destroy(curr->next);
		delete curr;
		curr = nullptr;
	}
}

// insert(1->..., 5)
// 1 -> 2 -> 3 -> 4 -> X
void insert(node *& curr, int new_data) {
	if (!curr) {
		curr = new node;
		curr->data = new_data;
		curr->next = nullptr;
	}
	else {
		insert(curr->next, new_data);
	}
}

void display_wrapper(const node * head) {
	// list: 1 -> 3 -> 2 -> 5\n
	// list: display_recursive(...)\n
	// LIST IS EMPTY
	if (!head) {
		cout << "LIST IS EMPTY" << endl;
	}
	else {
		cout << "list: ";
		display_recursive(head);
		cout << endl;
	}
}

void display_recursive(const node * curr) {
	// 1 -> 3 -> 2 -> 5
	if (!curr) { return; } // list is empty, just leave

	cout << curr->data;
	if (curr->next) {
		cout << " -> ";
		display_recursive(curr->next);
	}
}
