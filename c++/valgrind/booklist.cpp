#include "booklist.h"

using namespace std;

// -CONSTRUCTORS---------------------------------------------------------

Book::Book(): sequel_ptr(nullptr) {}

Book(std::string t, std::string a, std::string* s=nullptr):
	title(t), author(a)
{
	if (s) {
		sequel_ptr = new String(*s);
	}
}

BookList::Node::Node(): next(nullptr) {}

BookList::BookList(): head(nullptr) {}

// -DESTRUCTORS----------------------------------------------------------
BookList::~BookList()
{
	if (!head) {
		return;
	}

	head = head->next;
	while (head) {
		Node* to_delete = head;
		head = head->next;
		delete to_delete;
	}
}
