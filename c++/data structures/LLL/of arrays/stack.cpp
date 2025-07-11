#include "stack.h"

using namespace std;

//---------- Node constructors and destructors ----------
Stack::Node::~Node()
{
	delete [] data;
}

Stack::Node::Node(int arr_size): data(nullptr)
{
	data = new int[arr_size];
	next = nullptr;
}


// ---------- Stack constructors and destructors --------------
Stack::Stack(int input_arr_size){
	head = nullptr;
	arr_size = input_arr_size;
	top_index = 0;
}

Stack::~Stack()
{
	while (!is_empty()) {
		pop();
	}

	// this would also work, but it's less clear:
	// while (pop()) {}
}


// ----------------- Stack functions --------------------------
bool Stack::is_empty() const
{
	return !head;
}


void Stack::push(int new_data)
{
	if (is_empty() or top_index == arr_size) { // need new node
		Node * new_node = new Node(arr_size);
		new_node->next = head;
		head = new_node;
		top_index = 0;
	}	

	head->data[top_index++] = new_data;
}


bool Stack::pop()
{
	if (is_empty()) { return false; }

	if (top_index == 1) { // next delete will clear out this node
		Node * to_delete = head;
		head = head->next;
		delete to_delete;
	}

	// removing item from array here
	if (--top_index == 0) {
		top_index = arr_size;
	}

	return true;
}


int Stack::peek() const
{
	if (is_empty()) { return INT_MIN; } // failure case; return most negative num

	return head->data[top_index-1];
}


void Stack::display() const
{
	if (is_empty()) {
		cout << "top -> []" << endl;
		return;
	}

	// display head's array
	cout << "top -> [";
	for (int i = top_index-1; i >= 0; --i) {
		cout << head->data[i];
		if (i > 0) {
			cout << ',';
		}
	}
	cout << ']';

	// ...then the rest
	for (Node * curr = head->next; curr; curr = curr->next) {
		cout << " -> [";
		for (int i = arr_size-1; i >= 0; --i) {
			cout << curr->data[i];
			if (i > 0) {
				cout << ',';
			}
		}
		cout << ']';
	}

	cout << endl;
}
