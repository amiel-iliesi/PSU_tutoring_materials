#include <iostream>
#include <string>
#include <memory>

using namespace std;

void store(string&&);

int main()
{
	for (string s: {"abcde", "hello, world!", "12345"}) {
		store(move(s)); 
	}

	unique_ptr<string> sp = make_unique<string>("hello");
	unique_ptr<string> sp_new = move(sp);

	cout << sp.get() << endl;
	cout << *sp_new << endl;
}

void store(string&& new_string) {
	cout << "stored: \"" << new_string << "\"." << endl;
}

