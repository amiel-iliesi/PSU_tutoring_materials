# Exercises

Here are some exercises that you can try and complete to prepare you for
proficiency demos. Please read the notes!

**Note:** a *suggested* function call is shown for each exercise; something
that might be seen in `main.cpp`. The assumed type for the ADT is `int`.
Obviously, create whatever helper and wrapper functions you may need. The calls
are just what they commonly look like from the ADT user's perspective.

**Note:** If you haven't done overloads yet, alternatives are provided that do
the same thing, but in a more familiar syntax.

**Note:** I will include a key for these exercises for the LLL, but these
exercises apply to all list-type ADTs.

## Easy
1. Append supplied element to list: `list.append(3)`.
2. Insert supplied element at the front of the list: `list.push(7)`.
3. Count elements in the list: `int len = list.length()`.
4. Sum elements in the list: `int sum = list.sum()`.

## Medium
1. Insert supplied element to the given index: `list.insert(3, 7)`.
2. Delete element at given index: `list.pop(3)`.
3. Remove first `n` matches of a given element, or *all* if supplied count is
   `-1`: `list.remove(5, -1)`.
4. Copy (pick one):
    * Overload the copy constructor: `List new_list = old_list`.
    * Copy the list to another list: `new_list.copy(old_list)`.
5. Assign (pick one):
    * Overload the assignment operator: `list_B = list_A`.
    * **function form is the same as copy; see problem 4**

## Hard
1. Remove all evens: `list.filter_evens()`.
2. Reverse a list in place with resursive backtracking (one-pass):
   `list.reverse()`.
3. Delete the last `n` elements from the list: `list.pop_back(3)`.

## Absurd (you won't be asked these; just for fun/learning)
1. Remove all elements that satisfy a criteria (see "c++ lambdas"):
   `list.filter([](int x){ return x % 3 == 0; })`.
2. Sum all elements that satisfy a criteria:
   `list.sum_if([](int x){ return is_prime(x); })`.
