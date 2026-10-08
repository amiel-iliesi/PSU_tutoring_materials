#include <iostream>

using namespace std;

class MyInt {
	private:
		int data;
	
	public:
		// default constructor; no parameters
		MyInt(): data(0) {
			cout << "default constructor called" << endl;
		}

		// custom constructor, arbitrary parameter(s)
		MyInt(int _data): data(_data) {
			cout << "custom constructor called" << endl;
		}

		// copy constructor, takes const reference to another object in the same class
		MyInt(const MyInt & other): data(other.data) {
			cout << "copy constructor called" << endl;
		}

		MyInt & operator=(const MyInt & other) {
			this->data = other.data;
			cout << "assignment operator called" << endl;
			return *this;
		}

		// default destructor is fine..
		~MyInt() {
			cout << "default destructor called" << endl;
		}

		void display() const {
			cout << data;
		}

		MyInt peek() const {
			return *this;
		}

		// this is the same as the peek above, but it doesn't make a copy; it's also
		// less safe when doing loops or reassignment
		MyInt & reference_peek() {
			return *this;
		}


};

int main() {
	// -- FIRST: lets initialize int_A and int_B --
	MyInt int_A(5);
	
	cout << "int_A: ";
	int_A.display();
	cout << endl;

	MyInt int_B(7);
	
	cout << "int_B: ";
	int_B.display();
	cout << endl;

	// -- SECOND: lets copy construct temp with int_A; and we'll use peek() --
	MyInt temp = int_A.peek(); // same as: MyInt int_B(int_A.peek());
	
	cout << "temp: ";
	temp.display();
	cout << endl;

	// -- THIRD: reassign temp to int_B; this breaks with a reference! --
	cout << "reassigning temp to B..." << endl;

	temp = int_B.peek();
	cout << "int_A: ";
	int_A.display(); // NOTE: this should show that int_A breaks if you use a reference
	cout << endl;

	cout << "temp: ";
	temp.display();
	cout << endl;

	return 0;
}
