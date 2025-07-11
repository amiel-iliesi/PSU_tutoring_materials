#pragma once

struct node
{
	int data;
	node * left;
	node * right;
};

// --------------------------PUT YOUR PROTOTYPES HERE------------------------------

// EX 7.
void copy_evens(node *& dest, const node * src);

// EX 12.
bool all_leaves_level(const node * root);
bool all_leaves_level(const node * root, const int max_height, int curr_height);

int height(const node * root);




// ----------------------------SOME EXAMPLE PROBLEMS-------------------------------

/*  NOTE: these are listed by difficulty. * through ***, where * is easy and ***
		  is hard.
*   1.  DISPLAY the tree in-order.
*   2.  DISPLAY the tree in reverse order.
*   3.  COPY the given tree into a new tree.
*   4.  INSERT a new element into the tree.
**  5.  DISPLAY all even elements.
**  6.  RETURN the count of all even elements.
*** 7.  COPY all even elements into a new tree.
**  8.  REMOVE the max element from the tree (min is similar).
**  9.  REMOVE the in-order successor of the minimum value.
**  10. RETURN the number of leaves.
**  11. RETURN the height of the tree.
*** 12. RETURN a boolean indicating whether or not all leaves are at the
	    same height.
*   13. RETURN the sum of all of the tree's elements.
*** 14. ROTATE the root right:
	      ┌ C         ┌ C
	  EX: B     ⇒   ┌ B
		  └ A       A
**  15. COPY the contents of the tree into an array (in order).
*   16. MODIFY each element; double each node's data.
*/

// ----------------------------------SUPPLIED--------------------------------------

// NOTE: all the ones with '*' next to them, you don't need; they're just for
//		 building the BST to begin with; you won't have those functions given
//		 to you in the FP Demo. You can safely ignore them *entirely*.

void build(node *& root);
void display(const node * root);
void insert(node *& root, int data); //*
void display_rec(const node * root, int level); //*
int size(const node * root); //*
bool contains(const node * root, int data); //*
void clear(node *& root); //** NOTE: I don't remember if you have access to this?
