#include "list.h"
#include <iostream>

using namespace std;

List::Node::Node(int&& datum): data(move(datum)) {}

int& List::Node::get() {
	return data;
}

List::Node* List::Node::get_next() {
	return next.get();
}

void List::Node::set_next(unique_ptr<Node> new_next) {
	next = move(new_next);
}

void List::insert(int&& datum) {
	if (!head) {
		head = make_unique<Node>(move(datum));
	}
	else {
		Node* tail = head.get();

		while (tail->get_next()) {
			tail = tail->get_next();
		}

		tail->set_next(make_unique<Node>(move(datum)));
	}
}

void List::display() const {
	Node* curr = head.get();
	while (curr->get_next()) {
		cout << curr->get() << ", ";
		curr = curr->get_next();
	}
	cout << curr->get() << endl;
}
