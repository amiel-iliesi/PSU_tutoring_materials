#pragma once

struct PersonInfo
{
	char* name;
	char* favorite_color;
	int age;
};


class List
{
	private:
		struct Node
		{
			PersonInfo info;
			Node* next;
		};

		Node* head;

	public:
		List();
		~List();

		void add_person(const PersonInfo&);
		void display() const;
};
