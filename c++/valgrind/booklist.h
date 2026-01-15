#pragma once

#include <string>

struct Book
{
	std::string title;
	std::string author;
	std::string* sequel_ptr;

	Book();
	Book(std::string t, std::string a, std::string* s=nullptr);
};

class BooksList
{
	private:
		struct Node {
			Book data;
			Node* next;

			Node();
		};

		Node* head;
	public:
		BookList();
		~BookList();

		void add(const Book&);

		void display() const;

		vector<Book> get(const std::string& title) const;
};
