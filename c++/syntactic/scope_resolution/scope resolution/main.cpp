#include "store.h"
#include <iostream>

int main()
{
	Store Kroger;

	Kroger.add_region("Deli");
	Kroger.add_region("Electronics");
	Kroger.add_region("Dairy");

	Kroger.add_item("Deli", "Chicken Wrap", "0001111065448", 14, 600);
	Kroger.add_item("Deli", "Italian Sub", "0001111065440", 8, 600);
	Kroger.add_item("Electronics",
					"Playstation 5 Controller",
					"0071171957430",
					12,
					7499);
	Kroger.add_item("Electronics", "Printer", "0019633738009", 3, 5999);
	Kroger.add_item("Dairy", "2% Milk", "0001111041550", 48, 319);
	Kroger.add_item("Dairy", "Pepper Jack", "0001111058430", 63, 249);

	Kroger.display_all();

	std::cout << '\n';

	Store::Region& Kroger_deli = Kroger.get_region("Deli");
	{
		std::string UPC = "0001111065440";
		if (Kroger_deli.contains_item(UPC)) {
			Store::Item& product = Kroger_deli.get_item(UPC);
			std::cout << "The deli has " << product.name << "(s).\n";

			// let's pretend someone bought one
			std::cout << product.name << " purchased(x1).\n";
			--product.qty;
		}
	}

	std::cout << '\n';

	Kroger.display_all();

	return 0;
}
