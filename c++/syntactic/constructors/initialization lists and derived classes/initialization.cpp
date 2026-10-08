#include "initialization.h"

#include <cstring> // for strlen(), strcpy()
#include <iostream> // for cout, endl

using namespace std;

// --------------------------------------------------------------------------------
// ------------------------Car CLASS FUNCTIONS-------------------------------------
// --------------------------------------------------------------------------------

// - Constructors  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
Car::Car()
{
	make = nullptr;
	model = nullptr;
	year = 1900; // our arbitrary start date
}

Car::~Car()
{
	clear(); // might as well reuse the function for this too!
}

Car::Car(const char * _make, const char * _model, unsigned _year)
{
	make = new char[strlen(_make) + 1];
	strcpy(make, _make);

	model = new char[strlen(_model) + 1];
	strcpy(model, _model);

	year = _year;
}

// - Reassignment Functions  - - - - - - - - - - - - - - - - - - - - - - - - - - - 
void Car::clear()
{
	delete [] make;
	make = nullptr;

	delete [] model;
	model = nullptr;

	year = 1900;
}

void Car::copy(const Car & other)
{
	this->make = new char[strlen(other.make) + 1];
	strcpy(this->make, other.make);

	this->model = new char[strlen(other.model) + 1];
	strcpy(this->model, other.model);

	year = other.year;
}

// copy constructor
Car::Car(const Car & other)
{
	copy(other);
}

// assignment operator
void Car::operator=(const Car & other)
{
	// don't let the user self assign, EXAMPLE: x = x;
	if (this == &other) { return; }

	/* Almost entirely identical to the copy constructor body, but because we can
	   reassign any time after we create our object, we need to delete what we're
	   overwriting! We don't have to clear out our copy constructor because the
	   copy constructor only gets called when the object is new; it will always
	   start out empty!*/
	clear();
	copy(other);
}

// - Output Functions  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
void Car::display() const
{
	cout << "make: " << make
		 << "\nmodel: " << model
		 << "\nyear: " << year << '\n'; 
}




// --------------------------------------------------------------------------------
// -------------------------Truck CLASS FUNCTIONS----------------------------------
// --------------------------------------------------------------------------------

// - Constructors  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
Truck::Truck()
{
	/* By default, it will call our parent class' default constructor if we don't
	   supply an alternative in an initialization list. Because we want it to call
	   the regular Car() constructor, we don't need a list! */
	carrying_capacity_lbs = 0;
	torque_Nm = 0;
}

Truck::Truck(const char * _make, const char * _model, unsigned _year,
			 unsigned _carrying_capacity_lbs, unsigned _torque_Nm):
					Car(_make, _model, _year) // pass the data members to our parent!
{
	/* Assign the remaining data members that our Car(...) constructor didn't assign!
	   All that remains are the things specific to the Truck class. */
	carrying_capacity_lbs = _carrying_capacity_lbs;
	torque_Nm = _torque_Nm;
}

// - Output Functions  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
void Truck::display() const
{
	/* lets call our parents' display function before we display the things
	   specific to the Truck! */
	Car::display();

	// now we can display the truck specific things
	cout << "carrying capacity (lbs): " << carrying_capacity_lbs
		 << "\ntorque (Nm): " << torque_Nm << '\n';
}




// --------------------------------------------------------------------------------
// ------------------------Car CLASS FUNCTIONS-------------------------------------
// --------------------------------------------------------------------------------

/* NOTE: I won't comment as much here since it's similar to what we did for Truck,
		 but this time I won't make it as messy with a lot of comments :) */

// - Constructors  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
Sedan::Sedan()
{
	// no need to initialize the vector; it has it's own default constructor
}

Sedan::~Sedan()
{
	// here's how you use iterators to loop through a STL container
	for (auto it = feature_list.begin(); it != feature_list.end(); ++it) {
		// 'it' is short for iterator,
		// we dereference it to access the char * at the address
		delete [] *it; // delete the (char *) at the iterator's address 
	}
}

Sedan::Sedan(const char * _make, const char * _model, unsigned _year,
			 const std::vector<char*> _feature_list):
				Car(_make, _model, _year)
{
	copy_features(_feature_list);
}

// - Reassignment Functions  - - - - - - - - - - - - - - - - - - - - - - - - - - - 
void Sedan::copy_features(const std::vector<char*> & other_list)
{
	if (!feature_list.empty()) {
		for (int i = 0; i < feature_list.size(); ++i) {
			delete [] feature_list[i];
		}
		feature_list.clear(); // vectors have their own clear function!
	}

	// vectors are also like arrays, you don't have to use iterators!
	for (int i = 0; i < other_list.size(); ++i) {
		add_feature(other_list[i]);
	}
}

Sedan::Sedan(const Sedan & other): Car(other) // call parent's copy constructor too!
{
	copy_features(other.feature_list);
}

void Sedan::operator=(const Sedan & other)
{
	// assign the parent's members too; this is like when we call our parent's
	// constructor, but for assignment!
	Car::operator=(other); 

	copy_features(other.feature_list);
}

// - Output Functions  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
void Sedan::display() const
{
	Car::display();
	
	cout << "features: ";
	for (int i = 0; i < feature_list.size(); ++i) {
		cout << feature_list[i];
		if (i < feature_list.size()-1) {
			cout << ", ";
		}
	}
	cout << '\n';
}

// - Modifying Functions - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
void Sedan::add_feature(const char * new_feature)
{
		// copy the strings over
		char * to_add = new char[strlen(new_feature) + 1];
		strcpy(to_add, new_feature);

		// append the char * to the end of the vector
		feature_list.push_back(to_add);
}
