#include "tree.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm> // shuffle for insert method 2
#include <set>
#include <string>

using namespace std;

int main()
{
	// -parameter(s) (change these!)-------------------------------
	const bool DISPLAY_COLOR = false;
	const bool DISPLAY_TREE = true; // might wanna disable if N_ELEMENTS is big
	const bool RUN_TESTS = true;
	const size_t N_ELEMENTS = 32;
	const int INSERT_METHOD = 3; // choose {1, 2, 3}
	const bool SHOW_SECOND_TREE_EXAMPLE = false;




	// -program start----------------------------------------------
	cout << "-Tree<int>--------------------------------------------------\n";

	Tree<int> tree;

	size_t n_inserted = 0;
	set<int> inserted;

	random_device rd;
	mt19937 gen(rd());




	// -insertion methods------------------------------------------

	if (INSERT_METHOD == 1) {
		cout << "> Insertion method 1: hard-coded values.\n";

		for (int n: {5, 4, 3, 2, 1}) { // change me!
			if (tree.insert(n)) {
				++n_inserted;
				inserted.insert(n);
			}
		}
	}
	else if (INSERT_METHOD == 2) {
		cout << "> Insertion method 2: elements [0, N) inserted in shuffled order.\n";
		
		{
			vector<int> elements;
			elements.reserve(N_ELEMENTS);
			for (size_t i = 0; i < N_ELEMENTS; ++i) {
				elements.push_back((int)i);
			}

			shuffle(elements.begin(), elements.end(), gen);

			for (int n: elements) {
				if (tree.insert(n)) {
					++n_inserted;
					inserted.insert(n);
				}
			}
		}
	}

	else if (INSERT_METHOD == 3) {
		cout << "> Insertion method 3: attempt to insert (x in [0, N)), "
			 << "N times.\n"
			 << "  Possible duplicates means that insertion failure is "
			 << "also possible.\n";

		{
			for (size_t i = 0; i < N_ELEMENTS; ++i) {
				int new_datum = gen() % N_ELEMENTS;
				if (tree.insert(new_datum)) {
					++n_inserted;
					inserted.insert(new_datum);
				}
			}
		}
	}
	/*-END: insertion method 3- - - - - - - - - - - - - */




	// -display tree info------------------------------------------
	if (DISPLAY_TREE) {
		cout << '\n';
		tree.display(DISPLAY_COLOR);
		cout << '\n';
	}

	cout << "> The tree has " << tree.size() << " element(s).\n\n";

	cout << "> The tree " << (tree.contains(8) ? "*does*" : "*doesn't*")
		 << " contain the value 8.\n";




	// -run some tests---------------------------------------------

	if (RUN_TESTS)
	{
		cout << "\n-Testing `Tree<int>`----------------------------------------\n";

		cout << "Test 1 ["
			 << (tree.TEST_valid_inequality() ? "pass" : "FAIL")
			 << "]: all nodes (left < self < right).\n";

		cout << "Test 2 ["
			 << (tree.TEST_parent_child_verification() ? "pass" : "FAIL")
			 << "]: parent-child relationships are correctly linked.\n";

		cout << "Test 3 ["
			 << (tree.TEST_no_red_parent_child() ? "pass" : "FAIL")
			 << "]: no red node has a red child.\n";

		cout << "Test 4 ["
			 << (tree.TEST_all_black_height_equal() ? "pass" : "FAIL")
			 << "]: all paths to leaves through root go through the same "
			 << "number of black nodes.\n";

		cout << "Test 5 ["
			 << (tree.size() == n_inserted ? "pass" : "FAIL")
			 << "]: the tree holds as many values as it's reported to have "
			 << "inserted.\n";

		cout << "Test 6 [";
		{
			bool success = n_inserted == inserted.size();
			// 1: everything in the set is in the tree
			for (int n: inserted) {
				if (not success) {
					break;
				}

				success &= tree.contains(n);
			}

			vector<int> tree_contents = tree.get_all();

			// 2: everything in the tree is in the set
			for (int n: tree_contents) {
				if (not success) {
					break;
				}

				success &= inserted.contains(n);
			}

			// (1) and (2) together bijectively prove the soundness of the contents of
			// the tree.

			cout << (success ? "pass" : "FAIL");
		}
		cout << "]: the contents of the tree match the requested inputs "
			 << "to `Tree.insert`.\n";
	}




	// Just for fun: because the tree is a template, we can try other types, so
	// long as the type given supports `<`.
	if (SHOW_SECOND_TREE_EXAMPLE) {
		cout << "\n-Tree<std::string>------------------------------------------\n";

		Tree<string> string_tree;

		for (string s: {
				"hello, world!",
				"lorem ipsum",
				"say, hey, good-looking, whatcha got cooking?",
				"do Balanced Trees dream of electric leaves?",
				"pro tip: Valgrind!",
				"another pro tip: GDB!",
				"perchance, another string inserted?",
				"what",
				"xylophone",
				"zebra",
				"google: \"Rosy Maple Moth\"",
				"the last digit of pi is 7",
				"Bjarne Stroustrup was here",
				"\"more like, C--\", -Jesse Chaney",
				"how do I exit Vim?<Esc><Esc><Esc><^Q><Enter>"
		}) {
			string_tree.insert(s);
		}

		string_tree.display();
	}

	return 0;
}
