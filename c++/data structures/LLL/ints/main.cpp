#include "list.h"
#include <iostream>

using namespace std;

int main()
{
	List intList;
	intList.build(10, 1, 5);

	cout << "size of list: " << intList.size() << endl;
	intList.display();

	int head_item_count = intList.count_first();
	int head_item = intList.get(0);
	cout << "\nthere are " << head_item_count << (head_item_count == 1 ? " instance " : " instances ")
		 << "of a " << head_item << '.' << endl;

	cout << "\nthere are " << intList.count_primes() << " primes in the list" << endl;
	cout << "there are " << intList.count_composites() << " composites in the list" << endl;

	cout << "\nswapping head and tail..." << endl;
	intList.swap_head_tail();
	intList.display();


	int tail_gt_count = intList.count_greater_than_tail();
	if (tail_gt_count == 1) {
		cout << "\nthere is 1 item in the list greater than "
			 << intList.get(intList.size() - 1) << '.' << endl;
	}
	else {
		cout << "\nthere are " << tail_gt_count << " items in the list greater than "
			 << intList.get(intList.size() - 1) << '.' << endl;
	}

	/*
	cout << "\nremoving all values after the final two..." << endl;
	cout << "removed " << intList.remove_all_after_last_2() << '.' << endl;
	intList.display();
	*/

	cout << "\nremoving the last 2 in the list..." << endl;
	cout << "there are " << intList.remove_last_2() << " 2s remaining." << endl;
	intList.display();

	/*
	List intAscending;
	for (int i: {1, 5, 2, 3, 4})
		intAscending.insert_ascending(i);
	
	intAscending.display();
	*/

	return 0;
}
