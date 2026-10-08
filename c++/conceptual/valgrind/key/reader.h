#pragma once
#include "booklist.h"
#include <string>
#include <vector>

class Reader
{
	private:
		std::string name;
		BookList favorite_books;
	
	public:
		Reader(std::string _name);

		void add(const Book&);
		void display() const;
		std::vector<Book> ask_about(std::string title) const;
};
