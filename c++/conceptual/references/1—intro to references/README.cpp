/*. Everything has an address:
	* Basic data types:		int, float, char...
	* Aggregate data types:	int[], float[], char[], ...
	* functions:			int(sum*)(int, int), ...
	* and most confusingly, pointers!*
		> it's acutally super useful, and makes sense once you grasp the idea,
		  but it's kind of hard to wrap your mind around it.
*/





//you can get an object's address with the & symbol

int x = 5;			   //this has address &x
Node * head = nullptr; //this has address &head;

/* The above two objects work the same way! The (Node*) is just more confusing
   because it holds another address, and not a separate type like an (int). */

/* VARIABLE  |  ADDRESS  |  HOLDS/POINTS TO 
   -------------------------------------------
	  x		 |	  &x	 |		  5
	 head	 |	 &head	 |	nullptr = 0x0...0	*/

/* The variable's address, and the thing which that address is pointing to, are
   separate! */

/* This is most confusing in functions with parameters, because of how it works
   hand in hand with references. */







void double_int(int param_x)
{
	param_x *= 2;
}

// If we call this function with the x we wrote above, like this:
double_int(x);
/* What happens to the variables is listed below. I gave them hypothetical
   addresses, to illustrate the point a little more clearly: */

/* VARIABLE  |		ADDRESS		|  HOLDS/POINTS TO 
   ---------------------------------------------------
	   x	 |		 &x = 0x123	|		  5
	param_x  | &param_x	= 0x555	|		 10			*/

/* Because param_x is *not* a reference, it does not change x by the time the
   the function is done. Essentially, whenever you *don't* use a reference
   parameter, you are telling C++ to **make a copy** of your variable, which is
   local to the function. */





/* If we use a reference parameter this time (noted by the & in the parameter
   type): */

void double_int(int & param_x)
{
	param_x *= 2;
}

double_int(x);

// Now, this is what happens to both variables.
/* VARIABLE  |		ADDRESS		|  HOLDS/POINTS TO 
   ---------------------------------------------------
	  x		 |		 &x = 0x123	|		 10
	param_x  | &param_x	= 0x123	|		 10			*/


/* We can see that the variable that was passed in to the function is actually
   changed by this call, now! The parameter is no longer a copy, but is in fact
   the same adderss as the external variable, x! */






/* This is called a reference variable, which is also sometimes called an
   "alias". They call it this because it works like a nickname. You're just
   giving a name to something that already exists. You can even use these
   aliases outside of functions, but those are much less useful: */

int x = 5;
int & y = x; // y is just an alias for x; they have an address.
// any change made to y, will change x too, and vice versa.
