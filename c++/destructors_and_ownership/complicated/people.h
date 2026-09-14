#pragma once

struct Person
{
	char* name;
	int age;

	Person();
	~Person();
	Person(const char*, const int);
	Person(const Person&);
	void operator=(const Person&);

	private:
		void copy(const char*, const int);
		void clear();
};

class People
{
	private:
		struct Node {
			Person data;
			Node* next;

			Node();
			Node(const Person&);
		};

		Node* head;

		void copy(const People& other);
		void clear();
	public:
		People();
		~People();
		People(const People&);
		People& operator=(const People&);

		void push(const Person&);
		void display() const;
};
