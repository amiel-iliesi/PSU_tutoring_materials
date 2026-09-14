#include <iostream>

using namespace std;

/** MAIN TOPICS FOR STUDY
* Pointers and Dynamic Memory (focus on Dynamic Arrays)
* LLLs
	* Insertion, Removal, and Traversal
* Functions, Arguments, and Structs
* Conditionals, Loops, and Functions
*/



int main()
{
	// ---------------------------------------------
	// -[SECTION 1]: pointers and dynamic memory----
	
	/* Question 1:
	   -----------
	   What is a pointer? Describe it in words.

		> 
	*/

	
	/* Question 2:
	   -----------
	   How do you you get the pointer of any object? Print out the address of
	   the variable, below. */
	int q2 = 5;

	
	/* Question 3:
	   -----------
	   How would you initialize a single element dynamically? Make the pointer
	   below hold the value (5). Then print out the value to show it worked! */
	int* q3 = nullptr;

	
	/* Question 4:
	   -----------
	   Now we're moving on to arrays. First, store something in the first "temp"
	   array. Then put it in a dynamic array that is exactly as big as it needs
	   to be, to hold the contents of temp. */
	char q4_temp[512];
	cout << ">>> Q4: ";

	
	/* Question 5:
	   -----------
	   I gave you an array, and I'm accessing a single element from it. Access
	   the same value, using the square bracket syntax! */
	int q5_array[] = {5, 6, 2, 3, 1, 8, 4};
	int q5_a = *(q5_array + 3);

	
	/* Question 6:
	   -----------
	   Using the `new`, and `delete` syntax:
	   1. Create a new dynamic, single character variable.
	   2. Store the letter 'J' in that character variable.
	   3. Print it out.
	   4. Delete the variable now that we're done with it. */

	// ---------------------------------------------
	
	// ---------------------------------------------
	// -[SECTION 2]: Linearly Linked Lists----------
	
	// NOTE: For this section, the code doesn't have to run. This is because,
	// in the final, you will not be able to run code, it will be on paper where
	// you answer questions. So just fill in the blanks, as best you can!

	/* Question 7:
	   -----------
	   Write the definition for a LLL node struct, which has a single character
	   data. */
	struct node {
	};

	
	/* Question 8:
	   -----------
	   Fill in this function: */

	// Adds new_data as a new node to the start of the list
	void q8_add_at_head(node* head, int new_data) {
	}
	

	/* Question 9:
	   -----------
	   Fill in this function: */

	// Returns the count of the nodes, which are greater than their previous
	// nodes.
	int q9_count_gt_previous(const node* head) {
	}


	/* Question 10:
	   ------------
	   Fill in this function: */

	// Given a node, delete the next node.
	void q10_remove_next(node*& curr) {
	}

	/* Question 11:
	   ------------
	   Fill in this function: */
	
	// A function that copies one list into another
	void q11_copy(node*& dest, const node* src) {
	}

	// NOTE: this is how you call this function:
	node* new_list = nullptr;
	q11_copy(new_list, old_list);


	/* Question 12:
	   ------------
	   Fill in this function: */

	
	// empties the list!
	void q12_clear(node*& head) {
	}

	
	// ------------------------------------------------
	// -[SECTION 3]: functions, arguments, and structs-

	/* Question 13:
	   ------------
	   Finish the function prototype for a function that gets an array of
	   integers, and squares all of the elements in the array (right in their
	   array, directly). */

	/*TYPE*/ q13_square_elements(/*ARGUMENTS*/);


	/* Question 14:
	   ------------
	   Given the following structs, and the following array. Write the function
	   below. */

	struct q14_Description {
		char name[256];
		char description[2048];
		char attractions[1024];
	}

	struct q14_Location {
		float latitude;
		float longitude;
	}

	struct q14_Place {
		q14_Description description;
		q14_Location location;
	}

	q14_Place places[15];

	// write a function that would print out the names of all the given places
	void print_out_place_names(q14_Place places[], int size = 15) {
	}


	// ---------------------------------------------
	// -[SECTION 4]: Loops and Conditionals---------

	/* Question 5:
	   -----------
	   Given the following 2D array, write a loop that sums up all of the even
	   values. */

	int q5_2d_array[2][4];
	/* it would look something like this:
	   { #, #, #, #,
	     #, #, #, # }					*/
	
	// write your loop here.




	   return 0;
}
