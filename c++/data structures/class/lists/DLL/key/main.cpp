#include "list.h"
#include <random>
#include <print>
#include <cmath>

using namespace std;

bool is_square(const int& n)
{
	float sqrtn = sqrt((float)n);

	int isqrtn = (int)sqrtn;

	return n == (isqrtn * isqrtn);
}

int main()
{
	List list;

	random_device rd;
	default_random_engine gen(rd());

	for (int i = 16 + gen() % 8; i >= 0; --i) {
		list.push(gen() % 20);
	}
	list.display();

	// -custom function calls here---------------------------------
	println("\n- List::count(): the list has {} element(s).", list.count());

	{
		size_t insert_at = gen() % (2 * list.count());
		int insert_value = gen() % 20;
		println("\n- List::insert(index={}, value={}): {}",
				insert_at,
				insert_value,
				(list.insert(insert_at, insert_value) ? "success" : "failure"));
		list.display();
	}

	{
		int to_remove = gen() % 20;
		println("\n- List::remove(count=-1, value={}): removed {} element(s)",
				to_remove,
				list.remove(-1, to_remove));
		list.display();
	}

	{
		println("\n- List::List(const List& other): List B(A);");
		print("A: ");
		list.display();
		List other(list);
		print("B: ");
		other.display();

		println("\n- List::operator=(List& other): B = A;");
		print("A: ");
		list.display();
		other = list;
		print("B: ");
		other.display();
	}

	println("\n- List::reverse(): ...");
	list.reverse();
	list.display();

	println("\n- List::remove_if(is_square): removed {} elements",
			list.remove_if(is_square));
	list.display();

	println("\n- List::remove_evens(): removed {} element(s)",
			list.remove_evens());
	list.display();
	// ------------------------------------------------------------

	return 0;
}
