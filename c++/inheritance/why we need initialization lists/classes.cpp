#include "classes.h"
#include <cstring>
#include <iostream>

using namespace std;

// ----------------------------------------------------------------------
// - A implementations --------------------------------------------------
// ----------------------------------------------------------------------

A::A() : str1(nullptr)
{
	cout << "> 'A' [default] constructor called" << endl;
}

A::A(const char * s)
{
	cout << "> 'A' [custom] constructor called" << endl;
	str1 = new char[strlen(s) + 1];
	strcpy(str1, s);
}

A::A(const A & other)
{
	cout << "> 'A' [copy] constructor called" << endl;
	str1 = new char[strlen(other.str1) + 1];
	strcpy(str1, other.str1);
}

void A::display() const
{
	cout << "str1 = " << (str1 ? str1 : "<NULL>") << endl;
}




// ----------------------------------------------------------------------
// - B implementations --------------------------------------------------
// ----------------------------------------------------------------------

B::B() : str2(nullptr)
{
	cout << "> 'B' [default] constructor called" << endl;
}

B::B(const char * s1, const char * s2) : A(s1)
{
	cout << "> 'B' [custom] constructor called" << endl;
	str2 = new char[strlen(s2) + 1];
	strcpy(str2, s2);
}

// NOTE: intentional error; B forgets to call A(const A &)
B::B(const B & other)
{
	cout << "> 'B' [copy] constructor called" << endl;
	str2 = new char[strlen(other.str2) + 1];
	strcpy(str2, other.str2);
}

void B::display() const
{
	A::display();
	cout << "str2 = " << (str2 ? str2 : "<NULL>") << endl;
}





// ----------------------------------------------------------------------
// - C implementations --------------------------------------------------
// ----------------------------------------------------------------------

C::C() : str2(nullptr)
{
	cout << "> 'C' [default] constructor called" << endl;
}

C::C(const char * s1, const char * s2) : A(s1)
{
	cout << "> 'C' [custom] constructor called" << endl;
	str2 = new char[strlen(s2) + 1];
	strcpy(str2, s2);
}

// NOTE: C remembers to call A(const A &); error should be absent 
C::C(const C & other) : A(other)
{
	cout << "> 'C' [copy] constructor called" << endl;
	str2 = new char[strlen(other.str2) + 1];
	strcpy(str2, other.str2);
}

void C::display() const
{
	A::display();
	cout << "str2 = " << (str2 ? str2 : "<NULL>") << endl;
}
