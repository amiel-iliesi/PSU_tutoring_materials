#pragma once // this is called an "inclusion guard"
#include <string>

// NOTE: there are other inheritance modes besides 'public', but 'public' is
//       the most common and useful.
//
//       They can also be 'protected', and 'private'
//
// see:
// https://www.programiz.com/cpp-programming/public-protected-private-inheritance#syntax

// this is our base class
class Vehicle
{
	private:
		unsigned weight_lbs;
		unsigned seating_capacity;
		unsigned carrying_capacity_lbs;
	
	public:
		Vehicle();
		Vehicle(unsigned, unsigned, unsigned);
		// no dynamic data members, means we don't need a destructor
		
		void display() const;
};




class Car : public Vehicle
{	
	public:
		// let people outside the class refer to fuel types!
		enum class FuelType { gas, diesel, electric, hybrid }; 

	private:
		unsigned num_wheels;
		unsigned num_doors;
		
		FuelType fuel;

		char * color; // dynamic member to show off some other details
					  // we now need to implement: destructor, copy constructor, copy assignment
					  // see: https://en.cppreference.com/w/cpp/language/rule_of_three

		std::string fuel_to_string() const;

	public:
		Car();
		/* because Car is derived from a Vehicle, the Car constructor also
		 * needs the same data members that a Vehicle constructor would need to
		 * initialize. That's why we need those 3 unsigned parameters again! */
		Car(unsigned, unsigned, unsigned,
			unsigned, unsigned, FuelType, const char *); 

		// our "Rule of Three" functions we need because of the dynamic memory:
		~Car(); // destructor
		Car(const Car &); // copy constructor
		void operator=(const Car &); // copy assignment operator
		
		void display() const;
};




class Truck : public Car
{
	private:
		// no dynamic members here, so no destructor and all of that business
		unsigned bed_length_ft;
		bool has_hitch;

	public:
		Truck();
		// for the same reason seen in the Car constructor, truck needs all
		// those paramters again
		Truck(unsigned, unsigned, unsigned,
			  unsigned, unsigned, FuelType, const char *,
			  unsigned, bool); 
		
		void display() const;
};




class Boat : public Vehicle
{
	public:
		enum class Style { luxury, freight, fishing };

	private:
		Style style;
		
		std::string style_to_string() const;

	public:
		Boat();
		Boat(unsigned, unsigned, unsigned,
			 Style);

		void display() const;
};
