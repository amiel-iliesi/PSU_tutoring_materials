# CLL

This file will explain some of the unique behaviors of CLLs, the pros, and
cons, and some common points of interest.

## Pros

* Always have access to the first *and* last elements.
* Don't have to update a tail pointer, makes appending much easier.

## Cons

* No special end-of-list variable like in regular linked-lists, which have the
`nullptr`.
* More edge cases to handle: 0, 1, 2+ elements are often handled in seperate
cases in a CLL.

## FAQ

### Recursion

Recursion in a CLL is a different problem than in a LLL or DLL. Because LLLs
and DLLs have special elements denoting a stopping position—the `nullptr`—they
can exit a recursive call *on entry*, by looking at the element and seeing it's
the special **stop** element.

The CLL has no such element, besides when the CLL is totally empty. In a
regular CLL—populated with elements—the last element leads into the first, and
you usually want to call your function on the last element, instead of just
skipping it. This means we have to do some trickery to loop in a CLL. The
solution is to have a **loop condition**, unlike the **stopping condition** of
other recursive functions.

This means, a regular recursive call looks something like this:

```
f_stop_condition() {
    // base case 1: LEAVE
    // base case 2: LEAVE
    ...
    // base case N: LEAVE

    ...otherwise
    {
        // run the function
    }

    // recursion
    f_stop_condition();
}
```

But for a CLL, it should look like something like this:

```
// handles cases: 0 elements
f_loop_wrapper() {

}

// handles cases: 1+ elements
f_loop_condition() {
    {
        // run the function
    }

    // base case 1: LEAVE
    // base case 2: LEAVE
    ...
    // base case N: LEAVE
    else if (NONE OF THE BASE CASES) {
        //keep going
        f_loop_condition();
    }
}
```

The difference is that in our regular **stop condition** style of recursive
base case handling, we can look before we run our function and determine if
we're on a valid node, or whatever.

However in a CLL, we can't make that decision because we want to operate on
*every* node, so instead we test the conditions we need in order to **loop**.

In short, regularly we check when to **stop**, but in a CLL, we check when to
**loop**. They are inverses of one another, and they both do similar things,
but the benefit is that in the **loop condition** version, we *always* run the
function logic. So that even if we reach the end of the CLL—the *rear*—we still
run the function, we just promise not to continue, with the base cases that
follow.

### Rear

The *rear* is not a meaningless name choice. It *really is* the back of the
list. Some students will ignore this deliberate choice, and treat the `rear`
variable as the front of the list. Variable names aren't arbitrary in general;
in a LLL and DLL, we have *head* which means front, and sometimes we have
*tail* which means back. Somthing like this might seem like it's simple, but
it's the simplest things that we can gloss over, like how you can no longer
smell something that has become overly familiar.

Don't become de-sensitized to code semantics and conventions. `rear` means 
back, just like how it sounds. Because a CLL is circular, the `rear->next`
is the first element, because in a loop, the thing that comes after the end is
the beginning. A simple idea but easy to forget. This mistake is where a lot of
bugs come from.
