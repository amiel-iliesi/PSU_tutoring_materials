#include "classes.h"
#include "list.h"
#include <iostream>

using namespace std;

int main()
{
	Vehicle homemade_contraption(350, 1, 150);
	cout << "homemade contraption:" << endl;
	homemade_contraption.display();
	
	cout << endl;

	Car personal_car(1800, 5, 600,
			         4, 4, Car::FuelType::diesel, "silver");
	cout << "personal car:" << endl;
	personal_car.display();
	
	cout << endl;

	Car neighbors_car(2500, 8, 1500,
					  4, 4, Car::FuelType::gas, "maroon");
	cout << "neighbor's car:" << endl;
	neighbors_car.display();
	
	cout << endl;

	Car car_copy(personal_car);
	cout << "copy constructed personal car:" << endl;
	car_copy.display();
	
	cout << endl;

	car_copy = neighbors_car;
	cout << "copy assigned neighbor's car:" << endl;
	car_copy.display();
	
	cout << endl;

	Truck boss_truck(3500, 2, 3000,
					 6, 2, Car::FuelType::diesel, "titanium white",
					 12, true);
	cout << "boss' truck:" << endl;
	boss_truck.display();

	cout << endl;

	Boat my_yacht(15000, 35, 2000,
				  Boat::Style::luxury);
	cout << "my yacht:" << endl;
	my_yacht.display();

	cout << endl;

	cout << "now we are doing list stuff..." << endl;
	CarList car_list;

	car_list.append(1000, 1000, 1000,
					1000, 1000, Car::FuelType::diesel, "white");

	car_list.append(2000, 2000, 2000,
					2000, 2000, Car::FuelType::electric, "black");

	car_list.append(3000, 3000, 3000,
					3000, 3000, Car::FuelType::hybrid, "silver");

	car_list.display();

	return 0;
}
