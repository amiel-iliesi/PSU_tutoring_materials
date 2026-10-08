#pragma once

#include <string>

using namespace std;

class Person
{
	protected:
		string name;
		int age;

	public:
		Person() = default;
		Person(string _name, int _age);

		void display() const;
};

class Worker: public Person
{
	protected:
		string job_title;
		int salary;
	
	public:
		Worker() = default;
		Worker(string _name, int _age, string _job_title, int _salary);

		void display() const;
};
