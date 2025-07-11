#pragma once

class Person {
	private:
		char * name;
		int age;

		void clear();

	public:
		Person();
		Person(const char *, int);
		Person(const Person &);
		~Person();

		void operator=(const Person &);

		void set(const char *, int);

		void display() const;
};
