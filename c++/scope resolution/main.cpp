#include <iostream>
#include <cstring>

using namespace std;

struct Location {
	struct Coordinate {
		float x;
		float y;

		void display();
	};

	char name[100];
	Coordinate coordinate;

	Location(); // constructor functions are special, they return nothing;
				// they also tell you the default state of any object from the class
	~Location(); // destuctor is like a constructor; it returns nothing
				 // it runs when the object is going to leave

	void display();
};

// constructor
Location::Location() {
	cout << "running Location() constructor..." << endl;

	strcpy(name, "<NONE>");
	coordinate.x = 0;
	coordinate.y = 0;
}

// destructor
Location::~Location() {
	cout << "running ~Location() destructor..." << endl;
}

void Location::Coordinate::display() { // Location's Coordinate's display() function
	cout << "(" << x << ", " << y  << ")";
}

void Location::display() {  // Location's display() function
	cout << name << ": ";
	coordinate.display();
}


int main()
{
	Location place1;

	place1.display();
	cout << endl;

	return 0;
}
