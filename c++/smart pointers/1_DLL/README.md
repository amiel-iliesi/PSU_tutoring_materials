# Conversion From Raw to Smart

In these two directories: `raw/` and `smart/`, I have the same basic example of
a DLL. I have just converted the functions directly to use smart pointers.

I've also only implemented the basic necessities for the demo, but it should
show enough of how the ownership works, and should show the syntax off enough
so that you can get a grasp of it through this conversion.

Before we begin, please keep the
[documentation](https://en.cppreference.com/w/cpp/memory/unique_ptr.html)
in mind! Better to have this on hand as a map, then to stumble blindly!

## Structure

First, we have to re-define the structure. If we paid attention to the
explanation of the general `README` from before, then we know that we have to
define who owns the data. As we talked about, the `head` pointer, and the
`next` pointers are a good way to do this!—And so I re-declared those variables
to become owners of the memory with the `unique_ptr` class.

## Construction and Destruction

Because we have no more dynamic memory, we don't need custom construction and
destruction. We can get rid of these custom rules! (See
[Rule of Zero](https://en.cppreference.com/w/cpp/language/rule_of_three.html#Rule_of_zero)
).

## Insert and Display

Now this is where things get interesting. The first piece of new syntax to keep
a note of is how we construct our nodes now. Since we don't have dynamic memory, we invoke the construction indirectly via
[`make_unique`](https://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique.html)
. You use this function like a regular constructor, since it can forward
arguments. As you can see the relationship between this, and the raw version is
one-to-one. Fairly simple!

Next is the use of swap. Because when we let go of unique pointers, they
destruct, I like to swap pointers around with a diagram in mind. Since we just
swap, and don't release and reset, we guarantee nothing gets lost. It also
reads more clearly to me than releasing and resetting manually, but to each
their own. Below are diagrams of the several insertion cases, demonstrating
what the swaps do.

* [Case: Insertion Before Head](figures/case_insert_before_head.png)
* [Case: Insertion in the Middle](figures/case_insert_inbetween.png)
* [Case: Insertion After Tail](figures/case_insert_after_tail.png)

Finally, we note that we use `unique_ptr::get()` to use the raw pointers for
traversal. This is how we access the weak pointers for non-owning use! For
example in `List::insert`, we use this to iterate and find our insertion point.

Display is much the same so I won't repeat myself, but the changes are faily
minimal!

## Overview

The changes are kind of difficult to get used to, but as we saw, if we approach
the refactoring mindfully, and carefully, and if we go in with a plan for
**ownership**, then the changes are actually pretty easy! So remember, always
plan you structures regarding ownership in advance when using smart pointers,
and you will be smooth sailing!
