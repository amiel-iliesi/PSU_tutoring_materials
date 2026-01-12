#include "list.h"
#include <random>
#include <iostream>

using namespace std;

int main()
{
	bool status; //to be used throughout running

	List list;

	random_device rd;
	default_random_engine gen(rd());

	for (int i = 8 + gen() % 8; i >= 0; --i) {
		list.push(gen() % 100);
	}

	List original = list;

	cout << "original list:\n";
	original.display();
	cout << '\n';

	// -custom function calls here---------------------------------
	cout << "-Exercises: Easy--------------------------------------------\n";

	cout << "1: appending `5`\n";
	list.append(5);
	list.display();
	cout << '\n';

	cout << "2: pushing `3`:\n";
	list.push(3);
	list.display();
	cout << '\n';

	cout << "3: length = " << list.length() << "\n\n";

	cout << "4: sum = " << list.sum() << "\n";

	cout << "-Exercises: Medium------------------------------------------\n";

	// NOTE: insert range can go past, for chance of fail (to test case)
	int insert_at = gen() % (list.length() + 5); // range = [0, L+5)
	cout << "1: insert 6 at index " << insert_at <<  '\n';
	status = list.insert(6, insert_at);
	cout << "insert " << (status ? "success" : "failure") << '\n'; // "ternary"
	list.display();
	cout << '\n';

	int pop_at = gen() % (list.length() + 5);
	cout << "2: pop at index " << pop_at << '\n';
	status = list.pop(pop_at);
	cout << "pop " << (status ? "success" : "failure") << '\n';
	list.display();
	cout << '\n';

	cout << "3: remove first 2 occurrences of 3\n";
	list.remove(3, 2);
	list.display();
	cout << '\n';

	cout << "4: copying list to new list...\n";
	List new_list = list;
	cout << "new list:\n";
	new_list.display();
	cout << '\n';

	cout << "5: assigning list to other list...\n";
	List other_list;
	// populate it with whatever
	other_list.push(1);
	other_list.push(2);
	other_list.push(3);
	cout << "other list, before assignment:\n";
	other_list.display();
	other_list = list;
	cout << "other list, after assignment:\n";
	other_list.display();

	cout << "-Exercises: Hard--------------------------------------------\n";

	cout << "Hard, 1: removing all evens...\n";
	list.filter_evens();
	list.display();
	cout << '\n';

	cout << "Hard, 2: reversing list...\n";
	list.reverse();
	list.display();
	cout << '\n';

	cout << "Hard, 3: popping the last 3 elements in the list...\n";
	list.pop_back(3);
	list.display();

	cout << "-Exercises: Absurd------------------------------------------\n";
	
	cout << "The list is too small now, restoring the list to the original...\n";
	list = original;
	list.display();
	cout << '\n';

	cout << "1: removing all elements where x >= 50...\n";
	list.remove_if([](const int& x) -> bool { return x >= 50; });
	list.display();
	cout << '\n';

	cout << "2: summing of all elements where x <= 25...\n";
	cout << "sum = " << list.sum_if([](const int& x) -> bool { return x <= 25; });
	cout << '\n';
	// ------------------------------------------------------------

	return 0;
}
