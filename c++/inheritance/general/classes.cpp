#include "classes.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std; // this is OK, we are in a `.cpp` file so it won't cause
					 // "namespace pollution"

// ----------------------------------------------------------------------
// - Vehicle IMPLEMENTATIONS --------------------------------------------
// ----------------------------------------------------------------------

// Use initialization lists when you can! They're more efficient, but also they
// are required to be used for derived constructor calls. You will see that use
// case below in the first derived class.
//
// see: https://en.cppreference.com/w/cpp/language/constructor

// default constructor
Vehicle::Vehicle(): weight_lbs(0), seating_capacity(0), carrying_capacity_lbs(0)
{
	// the body can be empty! the initializer list did everything we needed
}

// constructor with parameters
Vehicle::Vehicle(unsigned w, unsigned sc, unsigned cc)
	: weight_lbs(w), seating_capacity(sc), carrying_capacity_lbs(cc) {}

void Vehicle::display() const
{
	cout << "weight (lbs): " << weight_lbs
		 << "\nseats: " << seating_capacity
		 << "\ncarrying capacity (lbs): " << carrying_capacity_lbs << endl;
}



// ----------------------------------------------------------------------
// - Car IMPLEMENTATIONS ------------------------------------------------
// ----------------------------------------------------------------------

// Car has dynamic stuff, so it's going to be the longest 😬

Car::Car(): num_wheels(0), num_doors(0), fuel(FuelType::gas), color(nullptr) {}

Car::Car(unsigned w, unsigned sc, unsigned cc,
		 unsigned nw, unsigned nd, Car::FuelType ft, const char * c)
	: Vehicle(w, sc, cc) // just call the constructor above, that we already wrote!
	, num_wheels(nw), num_doors(nd), fuel(ft) 
{
	// now we actually have to do something in the constructor body, since we
	// have dynamic memory to copy!
	color = new char[strlen(c) + 1];
	strcpy(color, c);
}

// our "Rule of Three" functions we need because of the dynamic memory:
Car::~Car()
{
	delete [] color;
}

Car::Car(const Car & other) : Vehicle(other) // call our parent class' copy constructor for its data members!
{
	// we can just assign all non-dynamic elements (we don't have to do the
	// Vehicle part of our Car; see the initialization list above):
	num_wheels = other.num_wheels;
	num_doors = other.num_doors;
	fuel = other.fuel;

	// ...and now, manually copy over the dynamic portion that we can't just assign!
	color = new char[strlen(other.color) + 1];
	strcpy(color, other.color);
}

// copy assignment operator: same as Constructor, but this can be called
// anytime after our Car is constructed. What this means practically is that
// our Car might already have data in it, so we have to make sure to handle memory that
// might already be in there carefully.
void Car::operator=(const Car & other)
{
	// explicitly call assignment for the parent class portion, so we don't
	// have to manually deal with that!
	Vehicle::operator=(other);

	// and now we assign the rest of our Car that is unique from the Vehicle
	// portion:
	num_wheels = other.num_wheels;
	num_doors = other.num_doors;
	fuel = other.fuel;

	delete [] color; // NOTE: this is what differs from the copy constructor!
	color = new char[strlen(other.color) + 1];
	strcpy(color, other.color);
}

// this is just a helper function to convert our enum to a string for display()
string Car::fuel_to_string() const
{
	switch (fuel) {
		case FuelType::gas:
			return "gas";
		case FuelType::diesel:
			return "diesel";
		case FuelType::electric:
			return "electric";
		case FuelType::hybrid:
			return "hybrid";
		default:
			return "";
	}
}

void Car::display() const
{
	// call the display from our parent class before we display the new stuff!
	Vehicle::display(); 

	// now display the new stuff:
	cout << "wheels: " << num_wheels
		 << "\ndoors: " << num_doors
		 << "\nfuel type: " << fuel_to_string()
		 << "\ncolor: " << color << endl;
}




// ----------------------------------------------------------------------
// - Truck IMPLEMENTATIONS ----------------------------------------------
// ----------------------------------------------------------------------
Truck::Truck(): bed_length_ft(0), has_hitch(false) {}

Truck::Truck(unsigned w, unsigned sc, unsigned cc,
			 unsigned nw, unsigned nd, Car::FuelType ft, const char * c,
			 unsigned bl, bool h)
	: Car(w, sc, cc, nw, nd, ft, c)
	, bed_length_ft(bl), has_hitch(h) {}
		
void Truck::display() const
{
	// first, display the underlying car
	Car::display();

	// ...and now Truck specific stuff
	cout << "bed length (ft): " << bed_length_ft
		 << "\nhas hitch?: " << (has_hitch ? "yes" : "no") << endl;
}





// ----------------------------------------------------------------------
// - Boat IMPLEMENTATIONS -----------------------------------------------
// ----------------------------------------------------------------------
Boat::Boat() : style(Style::luxury) {}

Boat::Boat(unsigned w, unsigned sc, unsigned cc,
		   Style s)
	: Vehicle(w, sc, cc), style(s) {}

string Boat::style_to_string() const
{
	switch (style) {
		case Style::luxury:
			return "luxury";
		case Style::freight:
			return "freight";
		case Style::fishing:
			return "fishing";
		default:
			return "";
	}
}

void Boat::display() const
{
	Vehicle::display();

	cout << "boat type: " << style_to_string() << endl;
}
