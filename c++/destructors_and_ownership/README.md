# Destruction and Ownership

The purpose of this directory is to illustrate the difference between good and
bad handling of dynamic memory, when it's time to release the memory.

## Structure

In this directory I have two sub-directores, one with a bad/naive approach to
destruction, and one with a good/better approach.

## Bad

Let's start with the bad folder.

What makes this example so bad? The problem is that the list itself has to
reach in to the `PersonInfo` and clean up the inner-most members. In this case
it might not be such a disaster, but once we start dealing with two, or three,
or even more levels of nested types with dynamic memory, this overextending of
ownership tends to make code very messy and hard to read.

For example take a good look at the `List` destructor. It is kind of hard to
read, it has to reach in and delete memebers that it has no idea about. As a
reader, it is easy to forget to free up this memory. It's better to give the
struct itself the responsibility of clearing its own memory.

## Good

Let's see how the good example deals with this. Notice how there's a bit more
code in `list.cpp` in this example. This isn't necessarily a bad thing, as all
the extra code does is provide different ways of constructing our info struct.
You can see one of the results of this helper code in `main.cpp`. Compare the
good and the bad `main.cpp` files, and you'll notice that the main in the good
directory is much easier to read and work with as a user.

Since we've told the info struct to handle all of it's own dynamic memory--to
take ownership--take a notice of how much more readable the rest of the code
is. The list add function, and the list destructor are both much more readable,
and they don't overextend themselves trying to manage their sub-struct's info.

This readability stays consant even if there's many (even dozens of) levels of
classes on top of classes, where we only have two in this example. If you tried
doing the same with the bad class, the bloat is actually exponential. It gets
too hard to manage after just another level or two of indirection.

In short, the good version scales *way* better!
