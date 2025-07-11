#pragma once

#include <vector>

class Car {
	private:
		char * make;
		char * model;
		unsigned year;

		// some helper functions to make the copy constructor and assignment
		// operator more clear
		void clear();
		void copy(const Car & other);
	
	public:
		Car();
		~Car();
		Car(const char * _make, const char * _model, unsigned _year);

		// since we have dynamic memory, we need a copy
		// constructor and assignment operator overload
		Car(const Car & other);
		void operator=(const Car & other);

		// NOTE: const on a function means it won't change our data members
		void display() const; 
};




class Truck: public Car {
	private:
		unsigned carrying_capacity_lbs;
		unsigned torque_Nm;
	
	public:
		Truck();
		// Truck has no dynamic members; we don't need a custom destructor!
		Truck(const char * _make, const char * _model, unsigned _year,
			  unsigned _carrying_capacity_lbs, unsigned _torque_Nm);

		// Because it has no dynamic members, we also don't need a
		// custom copy constructor, or assignment operator, either!
		
		void display() const;
};




class Sedan: public Car {
	private:
		std::vector<char*> feature_list;

		void copy_features(const std::vector<char*> & other_list);

	public:
		Sedan();
		~Sedan();
		Sedan(const char * _make, const char * _model, unsigned _year,
			  const std::vector<char*> _feature_list);

		Sedan(const Sedan & other);
		void operator=(const Sedan & other);

		void display() const;

		void add_feature(const char * new_feature);
};
