#pragma once

#include <string>
#include <vector>

struct Book
{
	std::string title;
	std::string author;
	std::string* sequel_ptr; //optional

	Book();
	Book(std::string t, std::string a, std::string* s=nullptr);
	Book(const char* t, const char* a, const char* s=nullptr);
	Book(const Book& other);

	void display() const;
};

class BookList
{
	private:
		struct Node {
			Book data;
			Node* next;

			Node();
			Node(const Book&);
		};

		Node* head;
	public:
		BookList();
		~BookList();

		void add(const Book&);

		void display() const;

		std::vector<Book> get(const std::string& title) const;
};
