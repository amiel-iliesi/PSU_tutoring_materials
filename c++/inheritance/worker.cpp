#include "worker.h"
#include <iostream>

Person::Person(string _name, int _age): name(_name), age(_age)
{}

void Person::display() const
{
	cout << name << '(' << age << ')';
}

Worker::Worker(string _name, int _age, string _job_title, int _salary):
	Person(_name, _age), job_title(_job_title), salary(_salary)
{}

void Worker::display() const
{
	Person::display();
	cout << ": " << job_title << " $" << salary;
}
