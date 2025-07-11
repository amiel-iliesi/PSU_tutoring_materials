# Overview

I've written you a BST for your convenience, so you can practice writing
recursive/reference functions on it.

This is mostly just to save you time trying to write a tree and having your
mem-leaks and segfaults keep you from practicing with different algorithms and
functions.

It should hopefully let you focus on the reference part of it.

Learning how to make your own BST from scratch is valuable though, and you
should give it a shot at some point. It should be much easier after you
understand reference parameters.

Use the provided makefile for your convenience.

# Practice Problems
The difficulty is noted with a number of stars (out of three)

## Reference Parameter Focused Practice
1. ★ Duplicate the root, and insert it into the right subtree.
2. ★★ Remove all even numbers from the tree.
3. ★ Write a copy tree function.
	* ★★ Bonus points: write it as a copy constructor:
	* [documentation](https://en.cppreference.com/w/cpp/language/copy_constructor)
	* [examples](https://www.geeksforgeeks.org/copy-constructor-in-cpp/)
4. ★★★ For each leaf, add on to the end of the leaf, the average of the path to
   (and including) the leaf.
   * EG:	  4
			  └─ 2
				 └─ 1
	 becomes: 4
              └─ 2
                 └─ 1
					└─ 2
	 because: (4+2+1)/3 = 7/3 = 2 when truncated to an integer.
5. ★★ Turn the tree into an ascending order vine:
	* EG:      4
			   ├─ 2
			   │  └─ 1
			   └─ 6
	  becomes: 1
			   └─ 2
				  └─ 4
					 └─ 6
6. ★★★ Merge two trees into a new tree.


## General Recursion Practice
1. ★ Find a node at a given index.
2. ★ Print out the contents of the tree, in order: EG: "1, 2, 3, 4, 5, ...".
3. ★★ Test if two trees are equal (same shape, and same ints in the same spots).
3. ★★ Invert a tree (flip all left and right children in the whole tree).
