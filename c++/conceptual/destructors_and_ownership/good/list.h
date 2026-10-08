#pragma once

struct PersonInfo
{
	char* name;
	char* favorite_color;
	int age;

	PersonInfo();
	PersonInfo(const PersonInfo&);
	PersonInfo(const char*, const char*, const int&);
	void operator=(const PersonInfo&);
	~PersonInfo();

	private:
		// helpers for constructors and assignment
		void copy(const char*, const char*, const int&);
		void clear();
};

class List
{
	private:
		struct Node
		{
			PersonInfo info;
			Node* next;

			Node();
		};

		Node* head;
	
	public:
		List();
		~List();

		void add_person(const PersonInfo&);
		void display() const;
};
