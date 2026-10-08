/* Before we move on to this document, if you struggle to understand reading
   type names like: */
const int * const x = nullptr;
/* You might want to optionally read this short, but well put together guide on
   reading C/C++ types and variable names: https://c-faq.com/decl/spiral.anderson.html */


/* ...and if you're not familiar with recursion, then I suggest you come back
   to this lesson after you've been introduced to that idea, though this lesson
   doesn't ask of your mastery on the subject. */







/* Now that you've read the overview of references, lets talk about references
   to pointers.

   Not much changes here—as compared to the last lesson—but it should help
   connect the slightly abstract idea of references to the problems you might
   have been working through in your classes. */

// Here's an example (Node) we'll be working with, just to make things concrete

struct Node
{
	int data;
	Node * next;
};

// And lets use this opportunity to fix a problem you've had with pointers.

/* First things first, we have to set the stage. Here's an outline of things to
   come:
		* I will write a linear linked list for us to use in this demonstration
		* I will explain a function I wrote using recursion and reference
		  parameters.
		* You will write a function that removes the first even number it sees
		  from the list
			* You *must* write this using recursion. This point will be clear in
			  an explanation, soon—below. */

#include "linkedlist.h" //*
/* *check out linkedlist.cpp and linkedlist.h to see the details of the
   list implementation, though if you know how a linearly-linked list works,
   it's not necessary. */





/* here are some classic problems when looping over list without references:
	* Inserting at the end; needing to keep a previous pointer so we don't
	  "fall off".
	* Removing something from the list and needing to keep a previous pointer
	  so we can point the previous *past* the node we are deleting.

References on things like lists, trees, and other aggregate types that use
pointers, fix all these little problems that pop up when we modify the size
of the object. */






// Before writing our function, let's dissect the problem's root cause.

/* When we want to insert something to the end of a list, for example:
   1 -> 2 -> 3

   We want to insert it here:
   1 -> 2 -> 3 -> (*)

   The problem is: that pointer is (nullptr) since it's at the end, so we
   obviously can't set it to anything.

   But that's actually not true! Lets take a closer look at node3 to see why */

//pretend this is the contents of the third node:
struct Node node3
{
	int data = 3;
	Node * next = nullptr;
}

/* So it looks like it *is* (nullptr), what gives? Here is where the reference
   business comes back into play. Lets take a look again at a similar table
   from the first lesson: 

     VARIABLE  |		ADDRESS			   |	CONTAINS
   ------------------------------------------------------------
   node3->next | &(node3->next) = 0x123... | nullptr = 0x00...0

   The next node *contains* a nullptr, but the "next" variable is stored
   at an address! With a reference, we can set this "next" directly!

   This just doesn't work normally in our loops and functions because we
   do something like this: */
Node * current = tail; // where tail->next == nullptr
current = tail->next;
current = new Node;
//...


/* This doesn't work because current isn't a reference! There's no (&) anywhere!
   This means that current is always just a *copy* of whatever it's looking at,
   and it just points to/contains the same address as what it copied.

   This is known as a shallow copy.

   ...so, can't we just fix it by changing it to the following? */
Node * & current = tail;

/* Not exactly. C/C++ doesn't let us rebind our reference variables. Remember,
   references are like aliases; we change the new variable, we change the
   original. So if we do this: */
Node * & current = tail;
current = current->next;
current = new Node;

// it's the same as doing this:
tail = tail->next;
tail = new Node;

// ... and it should be obvious how this breaks the list.








/* This is where recursion saves our life. It side-steps this issue and lets
   us make a new variable on every loop so we never break the list in the way you
   saw above. I wrote the (push_back) function to use this idea, so I'll paste
   it below, and we'll walk through how it's using references and recursion
   together. */


/* I'll omit a time saving shortcut I used in the linkedlist.cpp file, just
   so everything's purpose is more clear, but you can look in the file if you
   want to see the nicer shorthand version. */

void List::push_back(int new_value) //wrapper function
{
	push_back(head, new_value);
}

void List::push_back(Node *& curr, int new_value) //recursive function
{
	if (!curr)								// 1
	{										// 2
		curr = new Node;					// 3
		Node->data = new_value;				// 4
		Node->next = nullptr;				// 5
	}										// 6
	else									// 7
	{										// 8
		push_back(curr->next, new_value);	// 9
	}										// 10
}


/* First, the wrapper is just there as an entry point, so our user doesn't have
   to deal with nodes directly. I just included it here for clarity.

   Lets think about push_back in the following case, assume this list exists:
   1 -> 2 -> 3
   ...and we're inserting a 4 with (List::push_back(4))

   I'll be giving the nodes hypothetical addresses, just to have things make
   sense. See "initial_list.png".

   Lets skip ahead in the recursive calls to save some mental load and just
   focus on what happens by the time that (curr) is the node holding an int of 3,
   IE:
   Node * curr = &0x123: { data = 3, next(&0x555) = nullptr }
			   = a pointer to a Node at address 0x123, which is holding a 3 and a null next pointer.

   Now onto the first call (see "list_call1.png"):

   1. In this function call, we start at line 1. This condition is (false) because
      it contains a node. This node contains { data = 3, next = nullptr }. This
	  means we jump to the else condition on line 7.
   
   2. recursively call with curr->next.

   3. Now, we're in the next function call: push_back(curr->next, 4)
	  (see "list_call2.png")

   FYI in this subsequent call, the parameter curr is now:
   curr = Node* &0x555: (nullptr)
		= a pointer to a Node at address 0x555, which points to (nullptr).
   
   NOTE: the address of (curr->next) from the previous call, and (curr) from this new
		 call are the *same*, because we are using a reference.

   4. We start on this new call on line 1. This condition is (true) because
      curr(&0x555) *contains* (nullptr).
   
   5. We proceed into the if statement, and start making our new node.

   6. We set (curr = new node), this is where the magic begins. What happens
      here, is that we are modifying the (curr) pointer by reference. We are
	  modifying the address &0x555 directly. We are changing it's contents from
	  nullptr, to the location of a new (Node*).

	  This means we actually change the tail without needing a previous pointer!
   
   7. We finish setting the values of this new node, and we are finished! */







/* Using the push_back example, do you think you could write a function that
   removes the first even number it finds, from the list?

   I've prepared a working linearly-linked list for you, and a makefile to
   compile it all.

   Write your functions in:
   * linkedlist.h
   * linkedlist.cpp

   ...and call it in:
   * main.cpp

   If you get stuck and want to see the solution, just look in:
   * solution.cpp
   ...but try and work through it first, struggling is where learning lives

   Compile the list with:
   > make
   —in the terminal. */



//BONUS: make a function that pops the head node, and adds it to the end
