#pragma once

class A
{
	private:
		char * str1;
	
	public:
		A();
		A(const char *);
		A(const A&);

		void display() const;
};

class B : public A
{
	private:
		char * str2;
	
	public:
		B();
		B(const char *, const char *);
		B(const B &);

		void display() const;
};

class C : public A
{
	private:
		char * str2;

	public:
		C();
		C(const char *, const char *);
		C(const C &);

		void display() const;
};
