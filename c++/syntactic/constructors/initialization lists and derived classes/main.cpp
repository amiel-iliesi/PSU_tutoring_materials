#include "initialization.h"

#include <iostream>


using namespace std;

int main()
{
	// class Car stuff
	Car regular_car("Toyota", "Camry", 2002);
	cout << "regular car:\n";
	regular_car.display();

	Car copy_of_regular_car(regular_car); // copy constructor
	cout << "\nregular car(copy):\n";
	copy_of_regular_car.display();

	Car different_car("Volkswagen", "Passat TDI", 2014);
	cout << "\ndifferent car:\n";
	different_car.display();

	regular_car = different_car; // assignment operator
	cout << "\nregular car (now assigned to different car):\n";
	regular_car.display();




	// class Truck stuff
	Truck regular_truck("Ford", "F150", 2023, 4000, 550);
	cout << "\nregular truck:\n";
	regular_truck.display();

	Truck regular_truck_copy(regular_truck); // copy constructor
	cout << "\nregular truck(copy):\n";
	regular_truck_copy.display();

	Truck assigned_truck;
	assigned_truck = regular_truck; // assignment operator
	cout << "\nassigned truck:\n";
	assigned_truck.display();




	// class Sedan stuff
	Sedan beater("Toyota", "Corolla", 1980, {"doors", "windows", "engine"});
	cout << "\nbeater sedan:\n";
	beater.display();

	Sedan silly_sedan(beater); // copy constructor
	silly_sedan.add_feature("gigantic spoiler");
	silly_sedan.add_feature("spray paint flames");
	cout << "\nsilly sedan:\n";
	silly_sedan.display();

	beater = silly_sedan; // assignment operator
	cout << "\nbeater (reassigned):\n";
	beater.display();

	return 0;
}
