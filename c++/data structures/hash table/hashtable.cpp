#include "hashtable.h"
#include <cstring>
#include <iostream>

using namespace std;

//--------------------------------------------------------------------------------
//--------------------------------PERSON CLASS------------------------------------
//--------------------------------------------------------------------------------

//--CONSTRUCTORS------------------------------------------------------------------
Person::Person()
{
	name = nullptr;
	age = 0;
}

Person::Person(const char * n, const int a): Person()
{
	set_name(n);
	set_age(a);
}

Person::Person(const Person & other): Person()
{
	set_name(other.name);
	set_age(other.age);
}

Person::~Person()
{
	delete [] name;
}


//--SETTERS-----------------------------------------------------------------------
void Person::set_name(const char * n)
{
	delete [] name;
	name = nullptr;

	if (!n) { return; }

	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

void Person::set_age(const int a)
{
	age = a;
}


//--GETTERS-----------------------------------------------------------------------
const char * const & Person::get_name() const
{
	return name;
}

int Person::get_age() const
{
	return age;
}


//--OUTPUT------------------------------------------------------------------------
void Person::display() const
{
	cout << name << ',' << age << endl;
}



//--------------------------------------------------------------------------------
//--------------------------------PERSONNODE CLASS--------------------------------
//--------------------------------------------------------------------------------

PersonNode::PersonNode()
{
	next = nullptr;
}

PersonNode::PersonNode(const char * n, const int a): Person(n, a)
{
	next = nullptr;
}

void PersonNode::set_next(PersonNode * pn)
{
	next = pn;
}

PersonNode * PersonNode::get_next() const
{
	return next;
}




//--------------------------------------------------------------------------------
//------------------------------HASHTABLE CLASS-----------------------------------
//--------------------------------------------------------------------------------


//--CONSTRUCTORS------------------------------------------------------------------
Hashtable::Hashtable(int s)
{
	size = s;
	table = new PersonNode * [size];
	for (int i = 0; i < size; ++i) {
		table[i] = nullptr;
	}
}

Hashtable::~Hashtable()
{
	for (int i = 0; i < size; ++i)
	{
		while (table[i]) {
			PersonNode * to_delete = table[i];
			table[i] = table[i]->get_next();
			delete to_delete;
		}
	}

	delete [] table;
}

int Hashtable::hash(const char * s) const
{
	int sum = 0;

	for (int digit_pos = 0; s[digit_pos] != '\0'; ++digit_pos) {
		sum += s[digit_pos] * (digit_pos + 1);
	}

	return sum % size;
}


//--REQUIRED HASH TABLE FUNCTIONS-------------------------------------------------
void Hashtable::insert(const char * n, const int a)
{
	int position = hash(n);
	
	PersonNode * new_person_node = new PersonNode(n, a);
	new_person_node->set_next(table[position]);
	table[position] = new_person_node;
}

bool Hashtable::has(const char * n) const
{
	int position = hash(n);

	for (PersonNode * curr = table[position]; curr; curr = curr->get_next())
	{
		if (strcmp(curr->get_name(), n) == 0) {
			return true;
		}
	}

	return false;
}

Person Hashtable::retrieve(const char * n)
{
	int position = hash(n);

	for (PersonNode * curr = table[position]; curr; curr = curr->get_next())
	{
		if (strcmp(curr->get_name(), n) == 0) {
			return *curr;
		}
	}

	return Person();
}

bool Hashtable::remove(const char * n)
{
	if (!has(n)) { return false; }

	int position = hash(n);

	PersonNode * prev = nullptr;
	PersonNode * curr = table[position];
	while (strcmp(curr->get_name(), n) != 0) {
		prev = curr;
		curr = curr->get_next();
	}

	if (prev) {
		prev->set_next(curr->get_next());
	}
	else {
		table[position] = curr->get_next();
	}

	delete curr;
	return true;
}


//--OUTPUT------------------------------------------------------------------------
void Hashtable::display() const
{
	for (int i = 0; i < size; ++i) {
		for (PersonNode * curr = table[i]; curr; curr = curr->get_next()) {
			curr->display();
		}
	}
}
