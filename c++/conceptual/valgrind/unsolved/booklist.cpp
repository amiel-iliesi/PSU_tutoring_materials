#include "booklist.h"
#include <iostream>

using namespace std;

// -CONSTRUCTORS---------------------------------------------------------

Book::Book(): sequel_ptr(nullptr) {}

Book::Book(string t, string a, string* s):
	title(t), author(a)
{
	sequel_ptr = (s ? new string(*s) : nullptr);
}

Book::Book(const char* t, const char* a, const char* s):
	title(t), author(a)
{
	sequel_ptr = (s ? new string(s) : nullptr);
}

Book::Book(const Book& other):
	title(other.title), author(other.author)
{
	sequel_ptr = (other.sequel_ptr ? new string(*other.sequel_ptr) : nullptr);
}

BookList::Node::Node(): next(nullptr) {}

BookList::Node::Node(const Book& other): data(other), next(nullptr) {}

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

// -BOOK FUNCTIONS-------------------------------------------------------
void Book::display() const
{
	cout << title << " by " << author;
	if (sequel_ptr) {
		cout << "\n\t- sequel: " << *sequel_ptr;
	}
}

// -LIST FUNCTIONS-------------------------------------------------------
void BookList::add(const Book& book)
{
	Node* new_node = new Node(book);
	new_node->next = head;
	head = new_node;
}

void BookList::display() const
{
	if (!head) {
		return;
	}

	for (Node* curr=head; curr; curr=curr->next) {
		cout << "* ";
		curr->data.display();
		cout << '\n';
	}
}

vector<Book> BookList::get(const std::string& title) const
{
	vector<Book> matches;

	for (Node* curr=head; curr; curr=curr->next) {
		if (curr->data.title == title) {
			matches.push_back(curr->data);
		}
	}

	return matches;
}
