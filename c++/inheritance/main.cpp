#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	List workers;

	workers.add("Jeff", 37, "Chocolatier", 125000);
	workers.add("Janet", 58, "Brain Surgeon", 356000);
	workers.add("Amiel", 99, "Still Interning", 15000);

	workers.display();
}
