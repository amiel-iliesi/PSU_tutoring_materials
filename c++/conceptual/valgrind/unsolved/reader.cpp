#include "reader.h"
#include <iostream>

using namespace std;

Reader::Reader(string _name): name(_name) {}

void Reader::add(const Book& book)
{
	favorite_books.add(book);
}

void Reader::display() const
{
	cout << name << "'s favorite books:\n";
	favorite_books.display();
}

vector<Book> Reader::ask_about(string title) const
{
	return favorite_books.get(title);
}
