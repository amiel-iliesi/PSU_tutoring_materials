#include "reader.h"
#include <iostream>

using namespace std;

int main()
{
	vector<Reader> readers;

	readers.emplace_back("Jane");
	readers.emplace_back("Alex");

	Reader& jane = readers[0];
	Reader& alex = readers[1];

	jane.add(Book("Harry Potter and the Philosopher's Stone",
				  "J. K. Rowling",
				  "Harry Potter and the Chamber of Secrets"));
	jane.add(Book("Book A", "Author A", "Book B"));
	jane.add(Book("Book A", "Author B"));
	jane.add(Book("Book B", "Author B"));


	alex.add(Book("The C++ Programming Language",
				  "Bjarne Stroustrup"));
	alex.add(Book("Compilers: principles, techniques, and tools",
				  "Alfred V. Aho, Monica S. Lam, Ravi Sethi, and Jeffrey D. Ullman"));

	jane.display();

	cout << '\n';
	alex.display();

	vector<Book> jane_read = jane.ask_about("Book A");
	cout << '\n';
	cout << "Jane has read these books with the title \"Book A\":\n";
	for (const Book& book: jane_read) {
		cout << "* ";
		book.display();
		cout << '\n';
	}

	return 0;
}
