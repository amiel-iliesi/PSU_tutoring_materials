#pragma once

class Person {
	private:
		char * name;
		int age;
	
	public:
		Person();
		Person(const char * n, const int a);
		Person(const Person & other);
		~Person();

		void set_name(const char * n);
		void set_age(const int a);

		const char * const & get_name() const;
		int get_age() const;

		void display() const;
};

class PersonNode: public Person {
	private:
		Person data;
		PersonNode * next;

	public:
		PersonNode();
		PersonNode(const char * n, const int a);

		void set_next(PersonNode * pn);
		PersonNode * get_next() const;
};

class Hashtable {
	private:
		PersonNode ** table;
		int size;

		int hash(const char * s) const;
	
	public:
		Hashtable(int s = 101); // prime numbers work better for hash table sizes
		~Hashtable();

		void insert(const char * n, const int a);
		bool has(const char * n) const;
		Person retrieve(const char * n);
		bool remove(const char * n);

		void display() const;
};
