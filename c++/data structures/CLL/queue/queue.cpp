#include "queue.h"
#include <iostream>
#include <cstring>

using namespace std;

// -------- Queue Node constructors and destructors -------------------------------
Queue::Node::Node()
{
	text = nullptr;
	next = nullptr;
}


Queue::Node::~Node()
{
	delete [] text;
}


Queue::Node::Node(const char *other_text)
{
	text = new char[strlen(other_text) + 1];
	strcpy(text, other_text);
}




// --------- Queue Node functions -------------------------------------------------
void Queue::Node::copy(const Node *other_node)
{
	delete [] text; // empty out this current node before overwriting it

	text = new char[strlen(other_node->text) + 1];
	strcpy(text, other_node->text);
}




// ---------- Queue constructors and destructors ----------------------------------
Queue::Queue()
{
	rear = nullptr;
}


Queue::~Queue()
{
	while (!is_empty()) {
		dequeue();
	}
}


// ---------- Queue functions -----------------------------------------------------
bool Queue::is_empty() const
{
	return !rear;
}


void Queue::dequeue()
{
	if (is_empty()) { return; }

	if (rear->next == rear) { // deleting last item in the queue
		delete rear;
		rear = nullptr;
	}
	else {
		Node * front = rear->next;
		rear->next = front->next;

		//NOTE: because I have a destructor in the Node struct, I don't have to
		//		delete the inner text of the Node manually; it happens in there when
		//		I call delete on the node.
		delete front;
	}
}

void Queue::enqueue(const char text_src[])
{
	if (is_empty()) {
		rear = new Node(text_src);
		rear->next = rear;
	}

	else {
		// make new node
		Node * new_node = new Node(text_src);

		// ...and connect it into the list at the end
		new_node->next = rear->next; //this line makes the list circular :)
		rear->next = new_node;
		rear = new_node;
	}
}

void Queue::display() const
{
	if (is_empty()) { return; }

	Node * curr = rear->next;
	do {
		if (curr->text) {
			cout << curr->text;
		}
		cout << " -> ";

		curr = curr->next;
	} while (curr != rear->next);

	cout << "..." << endl;
}

void Queue::peek(char text_dest[]) const
{
	if (is_empty()) { return; }

	strcpy(text_dest, rear->next->text);
}
